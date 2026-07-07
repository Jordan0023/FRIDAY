# Dockerfile Report

Date: 2026-07-07
Updated: 2026-07-07

## Scope

This report reviews the current root `Dockerfile` in the workspace. The image was built and sanity-checked after the recommended changes.

## Summary

The Dockerfile builds a FRIDAY firmware audit container from `ubuntu:24.04`. It installs system firmware-analysis and security tooling, Node.js 20, the OpenAI Codex CLI, Ghidra, Python dependencies, Playwright Chromium, and configures the final container to run as the `vscode` user.

The Dockerfile includes an embedded FRIDAY hacker-agent prompt and a helper command that prints that prompt.

## Current Dockerfile Configuration

The Dockerfile includes:

- `FRIDAY_HACKER_AGENT_PROMPT=/opt/friday/hacker-agent-prompt.md`
- `/opt/friday/hacker-agent-prompt.md`, copied via Dockerfile heredoc
- `/usr/local/bin/friday-hacker-prompt`, which prints the embedded prompt
- `CODEX_CLI_VERSION=0.142.5`
- `GHIDRA_VERSION=12.1.2`
- `GHIDRA_RELEASE_TAG=Ghidra_12.1.2_build`
- `GHIDRA_RELEASE_DATE=20260605`
- `GHIDRA_SHA256=b62e81a0390618466c019c60d8c2f796ced2509c4c1aea4a37644a77272cf99d`

## Completed Recommendations

### Greenhouse prompt mismatch resolved

The embedded Dockerfile prompt no longer says Greenhouse is pre-installed. It now states that Greenhouse is not installed in this image and should be installed first if required.

The matching prompt in `router-agent.sh` was also updated so runtime agent instructions stay consistent with the image.

Relevant lines:

- `Dockerfile:121`
- `Dockerfile:156`
- `router-agent.sh:72`
- `router-agent.sh:108`

### Ghidra install pinned

The Dockerfile no longer downloads Ghidra from the latest GitHub release at build time. It pins Ghidra to `12.1.2`, downloads the corresponding release asset, and verifies the published SHA-256 before extraction.

Impact: repeated builds use the same Ghidra version unless the build args are intentionally changed.

Relevant lines:

- `Dockerfile:5`
- `Dockerfile:8`
- `Dockerfile:82`
- `Dockerfile:84`

### Codex CLI install pinned

The Dockerfile now installs `@openai/codex@0.142.5`.

Impact: repeated builds use the same Codex CLI version unless the build arg is intentionally changed.

Relevant line:

- `Dockerfile:4`
- `Dockerfile:81`

### Dockerfile heredoc documented

The prompt is copied with `COPY <<'EOF'`, which requires a modern Docker/BuildKit-compatible builder.

Impact: this should work in current Docker environments, but older CI or Docker installations may fail.

Relevant line:

- `Dockerfile:96`

### Prompt typos may affect agent quality

The embedded Dockerfile prompt and the matching `router-agent.sh` prompt were cleaned up to remove the previously noted typos and clarify the confirmation workflow.

Impact: the agent receives clearer and more accurate instructions.

Relevant lines:

- `Dockerfile:98`
- `Dockerfile:129`
- `Dockerfile:132`
- `Dockerfile:150`
- `Dockerfile:157`
- `Dockerfile:159`
- `router-agent.sh:49`
- `router-agent.sh:80`
- `router-agent.sh:83`
- `router-agent.sh:101`
- `router-agent.sh:109`
- `router-agent.sh:111`

## Build Inputs

The Dockerfile copies `requirements.txt` into the image and installs:

- `beautifulsoup4>=4.12.0`
- `requests>=2.31.0`
- `playwright>=1.44.0`

The `.dockerignore` excludes `.git`, virtualenv/cache directories, and large firmware/download/extraction artifacts under `known_firmware`.

## Build Verification

The image was built successfully with:

- `docker build -t friday-hacker-agent /home/jordan/FRIDAY`

Sanity checks:

- `docker run --rm friday-hacker-agent codex --version` returned `codex-cli 0.142.5`.
- `docker run --rm friday-hacker-agent analyzeHeadless` started Ghidra headless analyzer and printed usage.
- `docker run --rm friday-hacker-agent friday-hacker-prompt` printed the corrected embedded prompt.
