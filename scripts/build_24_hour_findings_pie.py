#!/usr/bin/env python3
"""Build the public 24-hour router finding summary chart."""
from pathlib import Path

import matplotlib.pyplot as plt


ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "site" / "24-hour-findings-pie-2026-07-26.png"


def main() -> None:
    labels = ["Unauthenticated RCE", "Unauthenticated DoS"]
    counts = [3, 10]
    colors = ["#d1495b", "#087f8c"]

    plt.rcParams.update({"font.family": "DejaVu Sans"})
    fig, ax = plt.subplots(figsize=(12, 8), facecolor="#f7f4ee")
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

    ax.legend(
        wedges,
        [
            (
                f"{labels[0]} — {counts[0]} chains "
                "(NETGEAR EX2800 / EX5000 / EX6110, RAX9, GL-X3000 Spitz AX)"
            ),
            f"{labels[1]} — {counts[1]} candidates (includes RAX9 and MS90)",
        ],
        loc="lower center",
        bbox_to_anchor=(0.5, -0.17),
        frameon=False,
        fontsize=14,
        ncol=1,
    )
    ax.set_title(
        "24-Hour Router Security Findings",
        fontsize=28,
        fontweight="bold",
        color="#18262d",
        pad=24,
    )
    fig.text(
        0.5,
        0.91,
        "13 distinct high-impact chains • firmware and emulation evidence • 26 Jul 2026",
        ha="center",
        fontsize=13,
        color="#526473",
    )
    fig.text(
        0.5,
        0.025,
        "Impact and reachability vary. Candidates are not vendor-confirmed zero-days.",
        ha="center",
        fontsize=11,
        color="#667784",
    )
    ax.axis("equal")
    fig.subplots_adjust(top=0.82, bottom=0.25, left=0.08, right=0.92)
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(OUTPUT, dpi=180, bbox_inches="tight", facecolor=fig.get_facecolor())
    plt.close(fig)
    print(f"Wrote {OUTPUT}")


if __name__ == "__main__":
    main()
