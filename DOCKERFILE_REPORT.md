# Dockerfile Report

Date: 2026-07-07
Updated: 2026-07-08

## Scope

This report reviews the current root `Dockerfile` and `router-agent.sh` wrapper in the workspace. The image was built and sanity-checked after the recommended changes.

## Summary

The Dockerfile builds a FRIDAY firmware audit container from `ubuntu:24.04`. It installs system firmware-analysis and security tooling, Docker CLI/daemon tooling for Docker-in-Docker workflows, Node.js 20, the OpenAI Codex CLI, Ghidra, Python dependencies, Playwright Chromium, and configures the final container to run as the `vscode` user for devcontainer compatibility.

The Dockerfile includes an embedded FRIDAY hacker-agent prompt and a helper command that prints that prompt.

The `router-agent.sh` wrapper now overrides the image default and runs audit jobs as root with privileged Docker capabilities by default. This is required for realistic firmware extraction and emulation workflows.

## Current Dockerfile Configuration

The Dockerfile includes:

- `FRIDAY_HACKER_AGENT_PROMPT=/opt/friday/hacker-agent-prompt.md`
- `/opt/friday/hacker-agent-prompt.md`, copied via Dockerfile heredoc
- `/usr/local/bin/friday-hacker-prompt`, which prints the embedded prompt
- `proot`
- `fakechroot`
- `qemu-user-static`
- `qemu-system-arm`
- `qemu-system-mips`
- `docker.io`
- `python3-capstone`
- `python3-pyelftools`
- `pyghidra`
- `/usr/local/bin/start-dind`
- `CODEX_CLI_VERSION=0.142.5`
- `GHIDRA_VERSION=12.1.2`
- `GHIDRA_RELEASE_TAG=Ghidra_12.1.2_build`
- `GHIDRA_RELEASE_DATE=20260605`
- `GHIDRA_SHA256=b62e81a0390618466c019c60d8c2f796ced2509c4c1aea4a37644a77272cf99d`

## Completed Recommendations

### Router audit tooling blockers resolved

The blockers from the R7000 Docker audit report were addressed:

- Root-only extraction: `router-agent.sh` now runs the audit container as `root` by default.
- Apt/package install blocker: audit runs now have root inside the container.
- `/run` write blocker: privileged root audit runs can write runtime files such as `/run` and `/var/run`.
- Chroot/mount namespace blocker: audit runs now add `--privileged --security-opt seccomp=unconfined` by default.
- Missing user-mode chroot helpers: the image now installs `proot` and `fakechroot`.
- Missing full-system emulator targets: the image now installs `qemu-system-arm` and `qemu-system-mips`.
- Python analysis automation gap: the image now installs `pyghidra`, `python3-capstone`, and `python3-pyelftools`.

The wrapper restores host ownership of generated audit output after each run with a root chown helper container.

The lower-privilege behavior is still available:

```bash
ROUTER_AGENT_USER="$(id -u):$(id -g)" ROUTER_AGENT_PRIVILEGED=0 ./router-agent.sh /path/to/firmware
```

### Greenhouse and Docker-in-Docker support added

The Dockerfile now clones Greenhouse from SEFCOM by default:

```bash
docker build -t friday-hacker-agent .
```

The default can still be overridden:

```bash
docker build -t friday-hacker-agent \
  --build-arg GREENHOUSE_REPO=https://github.com/sefcom/greenhouse.git \
  --build-arg GREENHOUSE_REF=<tag-or-branch> .
```

When `GREENHOUSE_REPO` is set, the image clones the repository into `/opt/greenhouse` and adds `/opt/greenhouse` and `/opt/greenhouse/bin` to `PATH`. `GREENHOUSE_REQUIRED=1` still fails the build if `GREENHOUSE_REPO` is intentionally overridden to an empty value.

The SEFCOM Greenhouse `Makefile` invokes Docker, so the Dockerfile does not run `make -C /opt/greenhouse` during the image build by default. Use `--build-arg GREENHOUSE_BUILD=1` only with a builder setup that intentionally supports Docker from inside build steps. The normal path is to run `start-dind make -C /opt/greenhouse` at container runtime after starting the container with privileged Docker capabilities.

The image also installs `docker.io` so Greenhouse and related workflows can use Docker from inside the audit container. It includes `/usr/local/bin/start-dind`, which starts `dockerd`, waits for Docker to become ready, and then runs the command passed to it. Nested Docker daemon usage still requires running the container with privileged Docker capabilities. `start-dind` now tries `overlay2`, then `fuse-overlayfs`, then `vfs`, so normal runs avoid the very slow `vfs` path unless the kernel/container runtime requires it.

`start-dind` now normalizes `PATH` so `/usr/bin/docker` is found before Ghidra's `/opt/ghidra/docker` directory. Without this, Greenhouse's Makefile can fail with `make: docker: Permission denied` even though the nested Docker daemon is running.

The Greenhouse clone is patched during image build to avoid known upstream build blockers: the old angr dependency path is pinned to a compatible toolchain, the optional `angr-management`/helper installs are skipped, the unreachable TuxFamily StuffIt extractor download is skipped cleanly, and the corrupt bundled routersploit patch is warning-only instead of build-fatal.

Greenhouse-required scans can now be launched through `router-agent.sh`:

```bash
ROUTER_AGENT_IMAGE=friday-hacker-agent:greenhouse \
ROUTER_AGENT_GREENHOUSE_REPO=https://github.com/sefcom/greenhouse.git \
ROUTER_AGENT_GREENHOUSE_REF=<tag-or-branch> \
ROUTER_AGENT_REQUIRE_GREENHOUSE=1 \
./router-agent.sh known_firmware/firmware/R7000/R7000-V1.0.12.216.zip -- "use Greenhouse for emulation before any fallback"
```

`ROUTER_AGENT_REQUIRE_GREENHOUSE=1` passes `GREENHOUSE_REQUIRED=1` into the Docker build. If no `ROUTER_AGENT_GREENHOUSE_REPO` is supplied, the wrapper uses `https://github.com/sefcom/greenhouse.git`.

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
- `docker build -t friday-hacker-agent:greenhouse-dind-check .`

Sanity checks:

- `docker run --rm friday-hacker-agent codex --version` returned `codex-cli 0.142.5`.
- `docker run --rm friday-hacker-agent analyzeHeadless` started Ghidra headless analyzer and printed usage.
- `docker run --rm friday-hacker-agent friday-hacker-prompt` printed the corrected embedded prompt.
- `docker build -t friday-hacker-agent:greenhouse-dind-check .` cloned `https://github.com/sefcom/greenhouse.git` into `/opt/greenhouse` and skipped `make` during image build because Greenhouse's Makefile requires a Docker daemon.
- `docker run --rm friday-hacker-agent:greenhouse-dind-check ...` verified `/opt/greenhouse`, `docker`, `dockerd`, `/usr/local/bin/start-dind`, and default-user membership in the `docker` group.
- `docker run --rm --privileged friday-hacker-agent start-dind ...` verified the nested Docker socket is created, `docker` resolves to `/usr/bin/docker`, and `docker run --rm hello-world` succeeds from the default `vscode` user.
- `docker run --rm --user root --privileged friday-hacker-agent start-dind ...` verified Greenhouse's `make build` now reaches `docker build -t greenhouse:usenix-eval-jul2023 .`; a 45 second bounded smoke test timed out later during the large Ubuntu dependency install, not on Docker socket or `docker` executable permissions.
- `docker run --rm --user root --privileged --security-opt seccomp=unconfined friday-hacker-agent ...` verified:
  - effective UID `0`
  - `proot`, `fakechroot`, `qemu-arm-static`, `qemu-system-arm`, `qemu-system-mips`, and `binwalk` are present
  - `/run` is writable
  - `chroot / /bin/true` succeeds
  - privileged mount namespace operations succeed
  - `import pyghidra, capstone, elftools` succeeds
- `analyzeHeadless` successfully ran a minimal Java post-script (`Smoke.java`) and printed `SMOKE_OK`.
- `binwalk -e --run-as=root` against `R7000-V1.0.12.216.zip` extracted the ZIP members.
- `binwalk -e --run-as=root` against `R7000-V1.0.12.216_10.2.122.chk` extracted `21E5E6.squashfs` and `squashfs-root`.
