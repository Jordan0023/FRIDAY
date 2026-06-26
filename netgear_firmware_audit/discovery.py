from __future__ import annotations

import re
import shutil
import subprocess
import tempfile
from html import unescape
from pathlib import Path
from urllib.parse import unquote, urljoin, urlparse

import requests
from bs4 import BeautifulSoup

from .models import FirmwareLink, Product, safe_name

CATEGORY_URL = "https://www.netgear.com/support/home/category?name=WiFi+Routers+and+Extenders"
BASE_URL = "https://www.netgear.com"
FIRMWARE_EXTENSIONS = (
    ".zip",
    ".chk",
    ".img",
    ".bin",
    ".trx",
    ".tar",
    ".tgz",
    ".gz",
    ".7z",
)


class NetgearDiscovery:
    def __init__(self, use_browser: bool = False, timeout: int = 45) -> None:
        self.use_browser = use_browser
        self.timeout = timeout
        self.errors: list[str] = []
        self.session = requests.Session()
        self.session.headers.update(
            {
                "User-Agent": (
                    "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 "
                    "Chrome/125.0 Safari/537.36 firmware-audit"
                )
            }
        )

    def discover_products(self, category_url: str = CATEGORY_URL) -> list[Product]:
        products = self._products_from_html(self._get_text(category_url), category_url)
        if self.use_browser:
            products.extend(self._products_from_browser(category_url))
        return _unique_products(products)

    def discover_firmware(self, product: Product) -> list[FirmwareLink]:
        html = self._get_text(product.url)
        links = self._firmware_from_html(html, product)
        if self.use_browser:
            links.extend(self._firmware_from_browser(product))
        return _unique_firmware(links)

    def _get_text(self, url: str) -> str:
        response = self.session.get(url, timeout=self.timeout)
        response.raise_for_status()
        return response.text

    def _products_from_html(self, html: str, base_url: str) -> list[Product]:
        soup = BeautifulSoup(html, "html.parser")
        products: list[Product] = []
        for href in _extract_hrefs(html, soup):
            absolute = urljoin(base_url, href)
            parsed = urlparse(absolute)
            if "/support/product/" not in parsed.path:
                continue
            name = unquote(parsed.path.rstrip("/").split("/")[-1])
            if name and name.lower() not in {"product"}:
                products.append(Product(name=safe_name(name.upper()), url=absolute.split("?")[0]))
        return products

    def _firmware_from_html(self, html: str, product: Product) -> list[FirmwareLink]:
        soup = BeautifulSoup(html, "html.parser")
        links: list[FirmwareLink] = []
        for href in _extract_hrefs(html, soup):
            absolute = urljoin(product.url, unescape(href))
            if not _looks_like_firmware_url(absolute, product.name):
                continue
            filename = _filename_from_url(absolute)
            title = _nearby_text_for_href(soup, href)
            links.append(
                FirmwareLink(
                    product=product.name,
                    url=absolute,
                    filename=filename,
                    title=title,
                    version=_extract_version(title) or _extract_version(filename),
                    release_date=_extract_date(title) or _extract_date(filename),
                )
            )
        return links

    def _products_from_browser(self, category_url: str) -> list[Product]:
        products: list[Product] = []
        if shutil.which("node"):
            try:
                products.extend(self._products_from_playwright(category_url))
            except Exception as exc:
                self._remember_error("Playwright product discovery failed", exc)
        rendered = self._html_from_system_browser(category_url)
        if rendered:
            products.extend(self._products_from_html(rendered, category_url))
        return products

    def _products_from_playwright(self, category_url: str) -> list[Product]:
        from playwright.sync_api import sync_playwright

        hrefs: list[str] = []
        products: list[Product] = []
        with sync_playwright() as p:
            browser = p.chromium.launch(headless=True)
            try:
                page = browser.new_page()
                page.goto(category_url, wait_until="networkidle", timeout=self.timeout * 1000)
                _scroll_page(page)
                hrefs = page.eval_on_selector_all("a[href]", "els => els.map(a => a.href)")
            finally:
                browser.close()
        for href in hrefs:
            parsed = urlparse(href)
            if "/support/product/" in parsed.path:
                name = unquote(parsed.path.rstrip("/").split("/")[-1])
                products.append(Product(name=safe_name(name.upper()), url=href.split("?")[0]))
        return products

    def _firmware_from_browser(self, product: Product) -> list[FirmwareLink]:
        links: list[FirmwareLink] = []
        if shutil.which("node"):
            try:
                links.extend(self._firmware_from_playwright(product))
            except Exception as exc:
                self._remember_error(f"Playwright firmware discovery failed for {product.name}", exc)
        rendered = self._html_from_system_browser(product.url)
        if rendered:
            links.extend(self._firmware_from_html(rendered, product))
        return links

    def _firmware_from_playwright(self, product: Product) -> list[FirmwareLink]:
        from playwright.sync_api import sync_playwright

        seen_urls: set[str] = set()
        links: list[FirmwareLink] = []
        with sync_playwright() as p:
            browser = p.chromium.launch(headless=True)
            try:
                page = browser.new_page(accept_downloads=False)

                def collect_response(response: object) -> None:
                    url = getattr(response, "url", "")
                    if _looks_like_firmware_url(url, product.name):
                        seen_urls.add(url)

                page.on("response", collect_response)
                page.goto(product.url, wait_until="networkidle", timeout=self.timeout * 1000)
                for label in ("Downloads", "Firmware", "Software"):
                    try:
                        page.get_by_text(label, exact=False).first.click(timeout=2000)
                        page.wait_for_load_state("networkidle", timeout=10000)
                    except Exception as exc:
                        self._remember_error(f"Could not click {label!r} for {product.name}", exc)
                _scroll_page(page)
                hrefs = page.eval_on_selector_all("a[href]", "els => els.map(a => a.href)")
                texts = page.eval_on_selector_all("a[href]", "els => els.map(a => a.innerText || a.textContent || '')")
            finally:
                browser.close()
        for href, text in zip(hrefs, texts):
            if _looks_like_firmware_url(href, product.name):
                seen_urls.add(href)
                links.append(_link_from_url(product, href, text))
        for url in seen_urls:
            links.append(_link_from_url(product, url, ""))
        return links

    def _html_from_system_browser(self, url: str) -> str:
        browser = shutil.which("chromium") or shutil.which("google-chrome") or shutil.which("chromium-browser")
        if not browser:
            return ""
        with tempfile.TemporaryDirectory(prefix="netgear-browser-", ignore_cleanup_errors=True) as user_data_dir:
            cmd = [
                browser,
                "--headless",
                "--disable-gpu",
                "--no-sandbox",
                "--disable-dev-shm-usage",
                f"--user-data-dir={user_data_dir}",
                "--virtual-time-budget=12000",
                "--dump-dom",
                url,
            ]
            try:
                result = subprocess.run(cmd, text=True, capture_output=True, timeout=self.timeout)
            except subprocess.TimeoutExpired:
                self.errors.append(f"System browser timed out rendering {url}")
                return ""
        return result.stdout if result.returncode == 0 else ""

    def _remember_error(self, context: str, exc: Exception) -> None:
        self.errors.append(f"{context}: {exc.__class__.__name__}: {exc}")


def _extract_hrefs(html: str, soup: BeautifulSoup) -> set[str]:
    hrefs = {a.get("href", "") for a in soup.find_all("a", href=True)}
    hrefs.update(re.findall(r"https?://[^'\"<>\s]+", html))
    hrefs.update(re.findall(r"/[^'\"<>\s]+", html))
    return {href for href in hrefs if href}


def _looks_like_firmware_url(url: str, product_name: str = "") -> bool:
    lower = unquote(url).lower().split("?")[0]
    if not lower.endswith(FIRMWARE_EXTENSIONS):
        return False
    if any(word in lower for word in ("readyshare", "printer", "genie", "utility", "app_")):
        return False
    if lower.endswith(".zip"):
        product = product_name.lower()
        return "firmware" in lower or (product and f"/{product}/" in lower) or (product and Path(lower).name.startswith(product))
    return "downloads.netgear.com" in lower or "/files/" in lower or "firmware" in lower


def _filename_from_url(url: str) -> str:
    path = unquote(urlparse(url).path)
    return safe_name(Path(path).name)


def _link_from_url(product: Product, url: str, title: str) -> FirmwareLink:
    filename = _filename_from_url(url)
    clean_title = " ".join(title.split())
    return FirmwareLink(
        product=product.name,
        url=url,
        filename=filename,
        title=clean_title,
        version=_extract_version(clean_title) or _extract_version(filename),
        release_date=_extract_date(clean_title) or _extract_date(filename),
    )


def _nearby_text_for_href(soup: BeautifulSoup, href: str) -> str:
    anchor = soup.find("a", href=href)
    if not anchor:
        return ""
    text = anchor.get_text(" ", strip=True)
    parent = anchor.find_parent(["li", "tr", "div", "section"])
    if parent:
        text = f"{text} {parent.get_text(' ', strip=True)}"
    return " ".join(text.split())[:500]


def _extract_version(text: str) -> str:
    text = re.sub(r"\.(zip|chk|img|bin|trx|tar|tgz|gz|7z)\b", "", text, flags=re.I)
    match = re.search(r"\b(?:v(?:er(?:sion)?)?\.?\s*)?([0-9]+(?:\.[0-9A-Za-z_-]+){1,})\b", text, re.I)
    return match.group(1) if match else ""


def _extract_date(text: str) -> str:
    match = re.search(r"\b(20[0-9]{2}[-/][01]?[0-9][-/][0-3]?[0-9])\b", text)
    if match:
        return match.group(1)
    match = re.search(r"\b([01]?[0-9]/[0-3]?[0-9]/20[0-9]{2})\b", text)
    return match.group(1) if match else ""


def _unique_products(products: list[Product]) -> list[Product]:
    unique: dict[str, Product] = {}
    for product in products:
        unique.setdefault(product.name, product)
    return [unique[key] for key in sorted(unique)]


def _unique_firmware(links: list[FirmwareLink]) -> list[FirmwareLink]:
    unique: dict[str, FirmwareLink] = {}
    for link in links:
        unique.setdefault(link.url, link)
    return list(unique.values())


def _scroll_page(page: object) -> None:
    last_height = 0
    for _ in range(12):
        height = page.evaluate("document.body.scrollHeight")
        if height == last_height:
            break
        last_height = height
        page.evaluate("window.scrollTo(0, document.body.scrollHeight)")
        page.wait_for_timeout(1000)
