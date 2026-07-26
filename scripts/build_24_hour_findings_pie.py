#!/usr/bin/env python3
"""Build the public 24-hour router finding summary chart."""
from pathlib import Path

import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle


ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "site" / "24-hour-findings-pie-2026-07-26.png"


def main() -> None:
    labels = ["Unauthenticated RCE", "Unauthenticated DoS"]
    counts = [3, 10]
    colors = ["#d1495b", "#087f8c"]

    plt.rcParams.update({"font.family": "DejaVu Sans"})
    fig, ax = plt.subplots(figsize=(14, 7), facecolor="#f7f4ee")
    ax.set_facecolor("#f7f4ee")

    wedges, _, percentages = ax.pie(
        counts,
        colors=colors,
        startangle=90,
        counterclock=False,
        autopct=lambda value: f"{value:.1f}%",
        pctdistance=0.68,
        wedgeprops={"edgecolor": "white", "linewidth": 4},
    )
    for percentage in percentages:
        percentage.set_color("white")
        percentage.set_fontsize(20)
        percentage.set_fontweight("bold")

    swatch_x = 0.145
    key_x = 0.215
    heading_size = 20
    detail_size = 16
    for color, highlight, heading_y, heading, count_text, highlight_width, details in (
        (
            colors[0],
            "#f9d9df",
            0.59,
            labels[0],
            f"— {counts[0]} chains",
            0.245,
            "(NETGEAR EX2800 / EX5000 / EX6110\nRAX9 • GL-X3000 Spitz AX)",
        ),
        (
            colors[1],
            "#d7eef1",
            0.31,
            labels[1],
            f"— {counts[1]} candidates",
            0.255,
            "(Includes RAX9 • MS90)",
        ),
    ):
        fig.add_artist(
            Rectangle(
                (swatch_x, heading_y - 0.025),
                0.055,
                0.05,
                transform=fig.transFigure,
                facecolor=color,
                edgecolor="white",
                linewidth=4,
            )
        )
        fig.add_artist(
            Rectangle(
                (key_x - 0.006, heading_y - 0.028),
                highlight_width + 0.012,
                0.056,
                transform=fig.transFigure,
                facecolor=highlight,
                edgecolor="none",
            )
        )
        fig.text(
            key_x,
            heading_y,
            heading,
            ha="left",
            va="center",
            fontsize=heading_size,
            fontweight="bold",
            color="#111111",
        )
        fig.text(
            key_x,
            heading_y - 0.058,
            count_text,
            ha="left",
            va="top",
            fontsize=18,
            fontweight="bold",
            color="#111111",
        )
        fig.text(
            key_x,
            heading_y - 0.115,
            details,
            ha="left",
            va="top",
            fontsize=detail_size,
            color="#111111",
            linespacing=1.18,
        )
    fig.suptitle(
        "24-Hour FRIDAY Zero-Day Findings",
        fontsize=28,
        fontweight="bold",
        color="#18262d",
        y=0.975,
    )
    fig.text(
        0.5,
        0.895,
        "13 total high-impact chains — 26 JUL 2026",
        ha="center",
        fontsize=13,
        color="#526473",
    )
    fig.text(
        0.5,
        0.018,
        "Impact and reachability vary. Candidates are not vendor-confirmed zero-days.",
        ha="center",
        fontsize=11,
        color="#667784",
    )
    ax.axis("equal")
    ax.set_position([0.52, 0.12, 0.45, 0.72])
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(OUTPUT, dpi=180, bbox_inches="tight", facecolor=fig.get_facecolor())
    plt.close(fig)
    print(f"Wrote {OUTPUT}")


if __name__ == "__main__":
    main()
