const state = {
  data: null,
  filtered: [],
  selectedSha: null,
};

const elements = {
  firmwareCount: document.querySelector("#firmwareCount"),
  findingCount: document.querySelector("#findingCount"),
  highPriorityCount: document.querySelector("#highPriorityCount"),
  archiveSize: document.querySelector("#archiveSize"),
  visibleCount: document.querySelector("#visibleCount"),
  firmwareRows: document.querySelector("#firmwareRows"),
  findingChart: document.querySelector("#findingChart"),
  brandFilter: document.querySelector("#brandFilter"),
  findingFilter: document.querySelector("#findingFilter"),
  sortOrder: document.querySelector("#sortOrder"),
  searchInput: document.querySelector("#searchInput"),
  hasFindingsOnly: document.querySelector("#hasFindingsOnly"),
  refreshButton: document.querySelector("#refreshButton"),
  detailTitle: document.querySelector("#detailTitle"),
  detailMeta: document.querySelector("#detailMeta"),
  detailFindings: document.querySelector("#detailFindings"),
  evidencePaths: document.querySelector("#evidencePaths"),
  priorityBanner: document.querySelector("#priorityBanner"),
  downloadLink: document.querySelector("#downloadLink"),
};

const recommendedActions = {
  "Remote shell services present":
    "Confirm the service is disabled by default, restrict it to trusted LAN/admin paths, require strong authentication, and remove it from production builds if it is not required.",
  "HTTP CGI/admin attack surface":
    "Prioritize authenticated route review, fuzz CGI parameters, check for command injection and auth bypass, and verify WAN access is blocked by default.",
  "Command execution helpers":
    "Trace every caller into this helper, verify user-controlled input cannot reach shell execution, and replace shell calls with argument-safe APIs where possible.",
};

async function loadData() {
  if (window.FIRMWARE_DASHBOARD_DATA) {
    state.data = window.FIRMWARE_DASHBOARD_DATA;
    hydrate();
    return;
  }
  const response = await fetch("data/firmware-dashboard.json", { cache: "no-store" });
  if (!response.ok) {
    throw new Error(`Unable to load dashboard data: ${response.status}`);
  }
  state.data = await response.json();
  hydrate();
}

function hydrate() {
  state.data.firmware = state.data.firmware.map(normalizeRecord);
  state.selectedSha = state.data.firmware[0]?.sha256 || null;
  populateSummary();
  populateBrandFilter();
  populateFindingFilter();
  renderChart();
  applyFilters();
}

function populateSummary() {
  const { summary } = state.data;
  elements.firmwareCount.textContent = summary.firmware;
  elements.findingCount.textContent = summary.findings;
  elements.highPriorityCount.textContent = state.data.severity_counts.High || 0;
  elements.archiveSize.textContent = `${summary.total_size_mb} MB`;
}

function normalizeRecord(record) {
  const version = record.version || versionFromFilename(record.filename) || "Not listed";
  const vendor = vendorName(record);
  const title = displayTitle(record, vendor, version);
  return {
    ...record,
    vendor,
    title,
    version,
    uploaded_at: record.uploaded_at || record.release_date || "",
    first_seen: record.first_seen || record.created_at || "",
    last_seen: record.last_seen || "",
    release_date: record.release_date || "Not listed",
    findings: Array.isArray(record.findings) ? record.findings : [],
    severity: record.severity || {
      label: record.findings?.length ? "Review" : "No findings",
      rank: record.findings?.length ? 1 : 0,
      reason: record.findings?.[0]?.title || "No heuristic findings were identified.",
    },
  };
}

function populateBrandFilter() {
  const current = elements.brandFilter.value;
  const brands = Array.from(new Set(state.data.firmware.map((record) => record.vendor))).sort((a, b) =>
    a.localeCompare(b, undefined, { sensitivity: "base" })
  );
  elements.brandFilter.innerHTML = '<option value="">All brands</option>';
  brands.forEach((brand) => {
    const option = document.createElement("option");
    option.value = brand;
    option.textContent = brand;
    elements.brandFilter.append(option);
  });
  elements.brandFilter.value = brands.includes(current) ? current : "";
}

function populateFindingFilter() {
  const current = elements.findingFilter.value;
  elements.findingFilter.innerHTML = '<option value="">All findings</option>';
  Object.keys(state.data.finding_counts).forEach((finding) => {
    const option = document.createElement("option");
    option.value = finding;
    option.textContent = finding;
    elements.findingFilter.append(option);
  });
  elements.findingFilter.value = current;
}

function renderChart() {
  const entries = Object.entries(state.data.finding_counts).sort((a, b) => b[1] - a[1]);
  const max = Math.max(1, ...entries.map((entry) => entry[1]));
  elements.findingChart.innerHTML = "";

  if (!entries.length) {
    const empty = document.createElement("p");
    empty.className = "muted";
    empty.textContent = "No static findings";
    elements.findingChart.append(empty);
    return;
  }

  entries.forEach(([label, count]) => {
    const row = document.createElement("div");
    row.className = "bar-row";
    row.innerHTML = `
      <span class="bar-label" title="${escapeAttr(label)}">${escapeHtml(label)}</span>
      <strong>${count}</strong>
      <span class="bar-track"><span class="bar-fill" style="width: ${(count / max) * 100}%"></span></span>
    `;
    elements.findingChart.append(row);
  });
}

function applyFilters() {
  const query = elements.searchInput.value.trim().toLowerCase();
  const brand = elements.brandFilter.value;
  const finding = elements.findingFilter.value;
  const findingsOnly = elements.hasFindingsOnly.checked;
  const sortOrder = elements.sortOrder.value;

  state.filtered = state.data.firmware.filter((record) => {
    const haystack = [
      record.title,
      record.vendor,
      record.product,
      record.filename,
      record.version,
      record.uploaded_at,
      record.first_seen,
      record.release_date,
      record.findings.map((item) => `${item.title} ${item.evidence}`).join(" "),
    ]
      .join(" ")
      .toLowerCase();
    const matchesQuery = !query || haystack.includes(query);
    const matchesBrand = !brand || record.vendor === brand;
    const matchesFinding = !finding || record.findings.some((item) => item.title === finding);
    const matchesFindingsOnly = !findingsOnly || record.findings.length > 0;
    return matchesQuery && matchesBrand && matchesFinding && matchesFindingsOnly;
  });
  sortRecords(state.filtered, sortOrder);

  if (!state.filtered.some((record) => record.sha256 === state.selectedSha)) {
    state.selectedSha = state.filtered[0]?.sha256 || null;
  }

  renderRows();
  renderDetail();
}

function renderRows() {
  elements.firmwareRows.innerHTML = "";
  elements.visibleCount.textContent = `${state.filtered.length} shown`;

  state.filtered.forEach((record) => {
    const tr = document.createElement("tr");
    tr.className = record.sha256 === state.selectedSha ? "is-selected" : "";
    tr.tabIndex = 0;
    tr.innerHTML = `
      <td><strong>${escapeHtml(record.product)}</strong><span class="subtext">${escapeHtml(record.title)}</span></td>
      <td><div class="filename">${escapeHtml(record.filename)}</div><span class="subtext">SHA ${escapeHtml(record.sha256.slice(0, 12))}</span></td>
      <td><strong>${escapeHtml(record.version)}</strong></td>
      <td><strong>${escapeHtml(formatDate(record.uploaded_at))}</strong></td>
      <td>${priorityPill(record.severity)}</td>
      <td>${record.findings.length}</td>
    `;
    tr.addEventListener("click", () => selectRecord(record.sha256));
    tr.addEventListener("keydown", (event) => {
      if (event.key === "Enter" || event.key === " ") {
        event.preventDefault();
        selectRecord(record.sha256);
      }
    });
    elements.firmwareRows.append(tr);
  });
}

function selectRecord(sha256) {
  state.selectedSha = sha256;
  renderRows();
  renderDetail();
}

function sortRecords(records, sortOrder) {
  const byName = (a, b) =>
    String(a.product || "").localeCompare(String(b.product || ""), undefined, {
      numeric: true,
      sensitivity: "base",
    }) || String(a.version || "").localeCompare(String(b.version || ""), undefined, { numeric: true });

  records.sort((a, b) => {
    if (sortOrder === "alpha_asc") {
      return byName(a, b);
    }
    if (sortOrder === "priority_desc") {
      return (b.severity?.rank || 0) - (a.severity?.rank || 0) || byName(a, b);
    }
    if (sortOrder === "priority_asc") {
      return (a.severity?.rank || 0) - (b.severity?.rank || 0) || byName(a, b);
    }
    return dateValue(a.uploaded_at) - dateValue(b.uploaded_at) || byName(a, b);
  });
}

function dateValue(value) {
  if (!value) return Number.MAX_SAFE_INTEGER;
  const time = new Date(value).getTime();
  return Number.isNaN(time) ? Number.MAX_SAFE_INTEGER : time;
}

function renderDetail() {
  const record = state.filtered.find((item) => item.sha256 === state.selectedSha);
  if (!record) {
    elements.detailTitle.textContent = "No Firmware";
    elements.detailMeta.textContent = "No records match the current filters";
    elements.detailFindings.innerHTML = "";
    elements.evidencePaths.innerHTML = "";
    elements.priorityBanner.textContent = "";
    elements.priorityBanner.className = "priority-banner";
    elements.downloadLink.href = "#";
    return;
  }

  elements.detailTitle.textContent = record.title;
  elements.detailMeta.textContent = `${record.product} · version ${record.version} · ${record.size_mb} MB · ${record.sha256.slice(0, 16)}`;
  elements.downloadLink.href = record.url;
  elements.priorityBanner.className = `priority-banner ${priorityClass(record.severity.label)}`;
  elements.priorityBanner.textContent = `${record.severity.label}: ${record.severity.reason}`;

  elements.detailFindings.innerHTML = "";
  if (!record.findings.length) {
    const item = document.createElement("div");
    item.className = "finding-item";
    item.innerHTML = "<h3>No heuristic findings</h3><p>This does not prove the firmware is vulnerability-free.</p>";
    elements.detailFindings.append(item);
  } else {
    record.findings.forEach((finding) => {
      const item = document.createElement("article");
      item.className = "finding-item";
      item.innerHTML = `
        <h3>${escapeHtml(finding.title)}</h3>
        <p>${escapeHtml(finding.description)}</p>
        <div class="recommended-action">
          <strong>Recommended action</strong>
          <p>${escapeHtml(recommendedActionFor(finding))}</p>
        </div>
        <span class="finding-chip">${escapeHtml(finding.evidence || "No evidence string captured")}</span>
      `;
      elements.detailFindings.append(item);
    });
  }

  elements.evidencePaths.innerHTML = `
    <dt>Router</dt><dd>${escapeHtml(record.product)}</dd>
    <dt>Version</dt><dd>${escapeHtml(record.version)}</dd>
    <dt>Uploaded</dt><dd>${escapeHtml(formatDateTime(record.uploaded_at))}</dd>
    <dt>First Seen</dt><dd>${escapeHtml(formatDateTime(record.first_seen))}</dd>
    <dt>Last Seen</dt><dd>${escapeHtml(formatDateTime(record.last_seen))}</dd>
    <dt>Firmware</dt><dd>${escapeHtml(record.path)}</dd>
    <dt>Report</dt><dd>${escapeHtml(record.report_path)}</dd>
    <dt>Source</dt><dd>${escapeHtml(record.url)}</dd>
  `;
}

function priorityPill(severity) {
  return `<span class="priority-pill ${priorityClass(severity.label)}">${escapeHtml(severity.label)}</span>`;
}

function recommendedActionFor(finding) {
  return (
    recommendedActions[finding.title] ||
    "Review the affected component manually, validate whether the code path is reachable, and document either a remediation task or the reason no action is required."
  );
}

function priorityClass(label) {
  return String(label).toLowerCase().replaceAll(" ", "-");
}

function routerTitle(record, version) {
  const product = record.product || "Unknown model";
  const vendor = vendorName(record);
  const displayProduct = productWithoutVendor(product, vendor);
  if (version && version !== "Not listed") {
    return `${vendor} ${displayProduct || "Unknown model"} firmware ${version}`;
  }
  return `${vendor} ${displayProduct || "Unknown model"} firmware`;
}

function displayTitle(record, vendor, version) {
  const title = record.title || routerTitle(record, version);
  const product = record.product || "";
  const displayProduct = productWithoutVendor(product, vendor);
  const duplicate = `${vendor} ${product}`;
  if (product && title.toLowerCase().startsWith(duplicate.toLowerCase())) {
    return `${vendor} ${displayProduct}${title.slice(duplicate.length)}`;
  }
  return title;
}

function vendorName(record) {
  const product = record.product || "";
  const url = String(record.url || "").toLowerCase();
  const path = String(record.path || "").toLowerCase();
  if (product.startsWith("ASUS ") || url.includes("asus.com") || path.includes("/asus_")) return "ASUS";
  if (product.startsWith("TP-Link ") || url.includes("tp-link.com") || path.includes("/tp-link_")) return "TP-Link";
  if (product.startsWith("GL.iNet ") || url.includes("gl-inet.com") || path.includes("/gl.inet_")) return "GL.iNet";
  if (product.startsWith("OpenWrt ") || url.includes("downloads.openwrt.org") || path.includes("/openwrt_")) return "OpenWrt";
  return "Netgear";
}

function productWithoutVendor(product, vendor) {
  const prefixes = {
    ASUS: "ASUS ",
    "TP-Link": "TP-Link ",
    "GL.iNet": "GL.iNet ",
    OpenWrt: "OpenWrt ",
    Netgear: "Netgear ",
  };
  const prefix = prefixes[vendor] || "";
  if (prefix && String(product).toLowerCase().startsWith(prefix.toLowerCase())) {
    return String(product).slice(prefix.length).trim() || product;
  }
  return product;
}

function versionFromFilename(filename) {
  const patterns = [
    /(?:^|[-_])V(?:ersion[_-]?)?(\d+(?:\.\d+)+(?:_\d+(?:\.\d+)*)?)/i,
    /(?:^|[-_])v(\d+(?:\.\d+)+(?:_\d+(?:\.\d+)*)?)/i,
    /Firmware[_ -]Version[_ -](\d+(?:\.\d+)+(?:_\d+(?:\.\d+)*)?)/i,
  ];
  for (const pattern of patterns) {
    const match = String(filename || "").match(pattern);
    if (match) return match[1];
  }
  return "";
}

function formatDateTime(value) {
  if (!value) return "Not listed";
  const date = new Date(value);
  if (Number.isNaN(date.getTime())) return value;
  return date.toLocaleString(undefined, {
    year: "numeric",
    month: "short",
    day: "numeric",
    hour: "numeric",
    minute: "2-digit",
  });
}

function formatDate(value) {
  if (!value) return "Not listed";
  const date = new Date(value);
  if (Number.isNaN(date.getTime())) return value;
  return date.toLocaleDateString(undefined, {
    year: "numeric",
    month: "short",
    day: "numeric",
  });
}

function formatTime(value) {
  if (!value) return "";
  const date = new Date(value);
  if (Number.isNaN(date.getTime())) return "";
  return date.toLocaleTimeString(undefined, {
    hour: "numeric",
    minute: "2-digit",
  });
}

function escapeHtml(value) {
  return String(value)
    .replaceAll("&", "&amp;")
    .replaceAll("<", "&lt;")
    .replaceAll(">", "&gt;")
    .replaceAll('"', "&quot;")
    .replaceAll("'", "&#039;");
}

function escapeAttr(value) {
  return escapeHtml(value).replaceAll("`", "&#096;");
}

elements.searchInput.addEventListener("input", applyFilters);
elements.brandFilter.addEventListener("change", applyFilters);
elements.findingFilter.addEventListener("change", applyFilters);
elements.sortOrder.addEventListener("change", applyFilters);
elements.hasFindingsOnly.addEventListener("change", applyFilters);
elements.refreshButton.addEventListener("click", () => loadData().catch(showError));

function showError(error) {
  elements.firmwareRows.innerHTML = `<tr><td colspan="6">${escapeHtml(error.message)}</td></tr>`;
}

loadData().catch(showError);
