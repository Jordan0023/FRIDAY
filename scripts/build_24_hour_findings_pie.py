#!/usr/bin/env python3
"""Build the public 24-hour router finding summary chart."""
from pathlib import Path

import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
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

    key_x = 0.105
    heading_size = 20
    detail_size = 16
    for color, heading_y, heading, details in (
        (
            colors[0],
            0.59,
            f"{labels[0]} — {counts[0]} chains",
            "NETGEAR EX2800 / EX5000 / EX6110\nRAX9 • GL-X3000 Spitz AX",
        ),
        (
            colors[1],
            0.40,
            f"{labels[1]} — {counts[1]} candidates",
            "Includes RAX9 • MS90",
        ),
    ):
        fig.add_artist(
            Rectangle(
                (0.035, heading_y - 0.025),
                0.055,
                0.05,
                transform=fig.transFigure,
                facecolor=color,
                edgecolor="white",
                linewidth=4,
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
        fig.add_artist(
            Line2D(
                [key_x, key_x + 0.30],
                [heading_y - 0.026, heading_y - 0.026],
                transform=fig.transFigure,
                color="#111111",
                linewidth=1.8,
            )
        )
        fig.text(
            key_x,
            heading_y - 0.055,
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
    ax.set_position([0.42, 0.10, 0.55, 0.76])
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(OUTPUT, dpi=180, bbox_inches="tight", facecolor=fig.get_facecolor())
    plt.close(fig)
    print(f"Wrote {OUTPUT}")


if __name__ == "__main__":
    main()
