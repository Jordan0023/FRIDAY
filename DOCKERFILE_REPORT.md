# Dockerfile Report

Date: 2026-07-07

## Scope

This report reviews the current root `Dockerfile` in the workspace. It is a source-level review only; the image was not built as part of this report.

## Summary

The Dockerfile builds a FRIDAY firmware audit container from `ubuntu:24.04`. It installs system firmware-analysis and security tooling, Node.js 20, the OpenAI Codex CLI, Ghidra, Python dependencies, Playwright Chromium, and configures the final container to run as the `vscode` user.

The current uncommitted Dockerfile change adds an embedded FRIDAY hacker-agent prompt and a helper command that prints that prompt.

## Current Dockerfile Change

The uncommitted change adds:

- `FRIDAY_HACKER_AGENT_PROMPT=/opt/friday/hacker-agent-prompt.md`
- `/opt/friday/hacker-agent-prompt.md`, copied via Dockerfile heredoc
- `/usr/local/bin/friday-hacker-prompt`, which prints the embedded prompt

## Findings

### Greenhouse is referenced but not installed

The embedded prompt says Greenhouse is pre-installed and available for firmware emulation, but the Dockerfile does not install a `greenhouse` binary or copy one into the image.

Impact: agents running in this image may fail when they try to use Greenhouse, or they may produce reports based on an inaccurate tool inventory.

Relevant lines:

- `Dockerfile:114`
- `Dockerfile:150`

### Ghidra install is not reproducible

The Dockerfile downloads Ghidra from the latest GitHub release at build time.

Impact: two builds from the same Dockerfile can install different Ghidra versions, which can change decompiler behavior and break reproducibility.

Relevant lines:

- `Dockerfile:77`
- `Dockerfile:80`

### Codex CLI install is not pinned

The Dockerfile installs `@openai/codex` globally without a version pin.

Impact: builds can pick up different Codex CLI behavior over time.

Relevant line:

- `Dockerfile:76`

### Dockerfile heredoc requires modern builder support

The prompt is copied with `COPY <<'EOF'`, which requires a modern Docker/BuildKit-compatible builder.

Impact: this should work in current Docker environments, but older CI or Docker installations may fail.

Relevant line:

- `Dockerfile:92`

### Prompt typos may affect agent quality

The embedded prompt has several typos, including:

- `analysts`
- `sever-end`
- `stoped`
- `vulnerabilties`
- `wether`
- `juse`

Impact: these are not build-breaking, but this prompt drives agent behavior, so clarity matters.

Relevant lines:

- `Dockerfile:94`
- `Dockerfile:123`
- `Dockerfile:126`
- `Dockerfile:144`
- `Dockerfile:151`
- `Dockerfile:153`

## Build Inputs

The Dockerfile copies `requirements.txt` into the image and installs:

- `beautifulsoup4>=4.12.0`
- `requests>=2.31.0`
- `playwright>=1.44.0`

The `.dockerignore` excludes `.git`, virtualenv/cache directories, and large firmware/download/extraction artifacts under `known_firmware`.

## Recommended Next Steps

1. Decide whether Greenhouse should be installed in the image or removed from the prompt.
2. Pin Ghidra and Codex CLI versions if reproducible builds matter.
3. Clean up the embedded prompt wording.
4. Build the image once after those changes to verify the Dockerfile still works end to end.
