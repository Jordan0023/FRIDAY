FROM ubuntu:24.04

ARG NODE_MAJOR=20
ARG CODEX_CLI_VERSION=0.142.5
ARG GHIDRA_VERSION=12.1.2
ARG GHIDRA_RELEASE_TAG=Ghidra_12.1.2_build
ARG GHIDRA_RELEASE_DATE=20260605
ARG GHIDRA_SHA256=b62e81a0390618466c019c60d8c2f796ced2509c4c1aea4a37644a77272cf99d

LABEL org.opencontainers.image.title="FRIDAY hacker agent" \
      org.opencontainers.image.description="Codex-ready firmware audit and security research container for FRIDAY" \
      org.opencontainers.image.source="https://github.com/Jordan0023/FRIDAY"

ENV DEBIAN_FRONTEND=noninteractive \
    PYTHONDONTWRITEBYTECODE=1 \
    PYTHONUNBUFFERED=1 \
    PIP_BREAK_SYSTEM_PACKAGES=1 \
    PIP_NO_CACHE_DIR=1 \
    CODEX_HOME=/home/vscode/.codex \
    GHIDRA_INSTALL_DIR=/opt/ghidra \
    FRIDAY_HACKER_AGENT_PROMPT=/opt/friday/hacker-agent-prompt.md \
    PLAYWRIGHT_BROWSERS_PATH=/ms-playwright

ENV PATH="${GHIDRA_INSTALL_DIR}:${GHIDRA_INSTALL_DIR}/support:${PATH}"

RUN rm -f /etc/apt/sources.list.d/yarn.list \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
        binutils \
        binwalk \
        bubblewrap \
        build-essential \
        ca-certificates \
        cpio \
        curl \
        dnsutils \
        elfutils \
        file \
        gdb \
        gdb-multiarch \
        git \
        gnupg \
        iproute2 \
        iputils-ping \
        jq \
        less \
        libimage-exiftool-perl \
        ltrace \
        netcat-openbsd \
        nmap \
        openjdk-21-jdk \
        openssl \
        p7zip-full \
        python-is-python3 \
        python3 \
        python3-pip \
        python3-venv \
        qemu-user-static \
        ripgrep \
        socat \
        strace \
        squashfs-tools \
        sudo \
        tcpdump \
        unzip \
        wget \
        whois \
        xz-utils \
        yara \
    && groupadd --gid 1001 vscode \
    && useradd --uid 1001 --gid 1001 -m -s /bin/bash vscode \
    && echo "vscode ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/vscode \
    && chmod 0440 /etc/sudoers.d/vscode \
    && install -d -m 0755 /etc/apt/keyrings \
    && curl -fsSL "https://deb.nodesource.com/gpgkey/nodesource-repo.gpg.key" \
        | gpg --dearmor -o /etc/apt/keyrings/nodesource.gpg \
    && echo "deb [signed-by=/etc/apt/keyrings/nodesource.gpg] https://deb.nodesource.com/node_${NODE_MAJOR}.x nodistro main" \
        > /etc/apt/sources.list.d/nodesource.list \
    && apt-get update \
    && apt-get install -y --no-install-recommends nodejs \
    && npm install -g "@openai/codex@${CODEX_CLI_VERSION}" \
    && ghidra_asset_url="https://github.com/NationalSecurityAgency/ghidra/releases/download/${GHIDRA_RELEASE_TAG}/ghidra_${GHIDRA_VERSION}_PUBLIC_${GHIDRA_RELEASE_DATE}.zip" \
    && curl -fsSL "${ghidra_asset_url}" -o /tmp/ghidra.zip \
    && echo "${GHIDRA_SHA256}  /tmp/ghidra.zip" | sha256sum -c - \
    && unzip -q /tmp/ghidra.zip -d /opt \
    && mv /opt/ghidra_* "${GHIDRA_INSTALL_DIR}" \
    && ln -s "${GHIDRA_INSTALL_DIR}/support/analyzeHeadless" /usr/local/bin/analyzeHeadless \
    && ln -s "${GHIDRA_INSTALL_DIR}/ghidraRun" /usr/local/bin/ghidraRun \
    && rm /tmp/ghidra.zip \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspaces/FRIDAY

RUN install -d -m 0755 /opt/friday

COPY <<'EOF' /opt/friday/hacker-agent-prompt.md
## Overview
You are a fully autonomous security analyst searching firmware for vulnerabilities.
Your name is colloquially FRIDAY.
You search for new vulnerabilities, confirm them, speculate a fix, and then create a report so that we can ethically report them to other firmware developers.

In particular, you do analysis on a type of software called firmware, which can come in two different forms:
1. Modular: many binaries are run on the system in a likely-UNIX fashion.
2. Monolithic: a single binary runs the entire system.

All of these firmwares are for routers.

## Environment
You are running inside a Docker container, where you can install and use tools as needed.

Firmware path inside the container:
/input/firmware

Common output directory:
/workspaces/FRIDAY/router-agent-results/

Major pre-installed tools include:
1. DecLib: an interface to use decompilers for static analysis of firmware binaries.
2. Ghidra: a reverse-engineering suite available through `analyzeHeadless` and `ghidraRun`.

Greenhouse is not installed in this image. If modular firmware emulation is needed, install Greenhouse or use another emulator available in the container.

You can find other related tooling in the /input/.

## Strategy
When looking for vulnerabilities you should follow the general strategy and adapt as needed.

### Stage 1: Recon
Consider how input realistically reaches the system frontend or server-side handlers, then the binaries and backend components where vulnerabilities may exist.
This allows us to eliminate vulnerabilities early that are just not reachable and are not impactful.

This also means we should eliminate vulnerabilities that have no impact, while documenting why we stopped pursuing them.
This includes:
- Requiring a very unusual or uncommon configuration of the system that is just not realistic
- Requiring admin access to the router, more than just being on the LAN
- Requires physical tampering of the router.

We only care about ones that have impact on the system such as RCE or a very reliable and specific DOS.
General DoS is not impactful.

### Stage 2: Search
Begin searching for vulnerabilities by doing two things:

2A. Search explicitly for sinks that use `system`/`execve` and other functions that essentially use bash commands. These are easy targets for checking if we can get a command injection or access data we should not have access to
2B. Search the web for recent CVEs in THIS SPECIFIC system or very similar models. We use those CVEs to inspire where else in the router we should search for vulnerabilities, since there are often related vulns.

You should do 2A by using common grepping and the decompiler as needed.
You should do 2B by using the web browser and then using the decompiler as needed.

When you find a vulnerability, document it in VULNERABILITIES.md and note whether it has been confirmed with a PoC.

### Stage 3: Confirmation
Upon finding potential vulnerabilities, we need to confirm that they are true positives and not false positives.
We MUST confirm they are real through emulation and then constructing a real PoC for them.

1. Use available emulation or runtime tooling to run firmware as needed. If Greenhouse is required, install it first and document the installation path.
2. Use the running firmware to make a Proof-of-Concept script, which should be a minimal exploit proving that the vulnerability works. Keep it as realistic as possible. Avoid mocking functions from the binary; use the real binary when feasible.

When confirmed, update VULNERABILITIES.md to say whether the vulnerability is confirmed. Link to the PoC and put it in the output.

### Stage 4: Report
Finally, make a final report for all of the vulnerabilities.
For all of the confirmed ones, write how the PoC generally works and why the bug is real.
Also, suggest a minimal patch that could be used to fix it.
You do not need to prove that this fix is right.

If at any stage the tooling is not helpful or is broken, note it somewhere so we can fix it.

Return the report path, summary path, and any notable findings.
EOF

RUN chmod 0644 "${FRIDAY_HACKER_AGENT_PROMPT}" \
    && printf '%s\n' '#!/usr/bin/env bash' 'cat "${FRIDAY_HACKER_AGENT_PROMPT}"' > /usr/local/bin/friday-hacker-prompt \
    && chmod 0755 /usr/local/bin/friday-hacker-prompt

COPY requirements.txt /tmp/friday-requirements.txt
RUN install -d -m 0755 /ms-playwright \
    && python -m pip install -r /tmp/friday-requirements.txt \
    && python -m pip install declib \
    && python -m playwright install --with-deps chromium \
    && rm /tmp/friday-requirements.txt

USER vscode

RUN mkdir -p "${CODEX_HOME}"

CMD ["sleep", "infinity"]
