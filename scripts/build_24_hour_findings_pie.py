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

    fig.legend(
        wedges,
        [
            (
                f"{labels[0]} — {counts[0]} chains\n"
                "NETGEAR EX2800 / EX5000 / EX6110\n"
                "RAX9 • GL-X3000 Spitz AX"
            ),
            (
                f"{labels[1]} — {counts[1]} candidates\n"
                "Includes RAX9 • MS90"
            ),
        ],
        loc="center left",
        bbox_to_anchor=(0.105, 0.47),
        frameon=False,
        fontsize=16,
        ncol=1,
        labelspacing=1.45,
        handlelength=2.4,
        handletextpad=0.9,
    )
    fig.suptitle(
        "24-Hour Router Security Findings",
        fontsize=28,
        fontweight="bold",
        color="#18262d",
        y=0.975,
    )
    fig.text(
        0.5,
        0.895,
        "13 distinct high-impact chains • firmware and emulation evidence • 26 Jul 2026",
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
    ax.set_position([0.42, 0.10, 0.55, 0.76])
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(OUTPUT, dpi=180, bbox_inches="tight", facecolor=fig.get_facecolor())
    plt.close(fig)
    print(f"Wrote {OUTPUT}")


if __name__ == "__main__":
    main()
