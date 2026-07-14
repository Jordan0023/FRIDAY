FROM ubuntu:24.04

ARG NODE_MAJOR=20
ARG CODEX_CLI_VERSION=0.142.5
ARG GHIDRA_VERSION=12.1.2
ARG GHIDRA_RELEASE_TAG=Ghidra_12.1.2_build
ARG GHIDRA_RELEASE_DATE=20260605
ARG GHIDRA_SHA256=b62e81a0390618466c019c60d8c2f796ced2509c4c1aea4a37644a77272cf99d
ARG GREENHOUSE_REPO=https://github.com/sefcom/greenhouse.git
ARG GREENHOUSE_REF=
ARG GREENHOUSE_REQUIRED=0
ARG GREENHOUSE_BUILD=0
ARG GREENHOUSE_ANGR_TAG=v9.2.60

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
    GREENHOUSE_INSTALL_DIR=/opt/greenhouse \
    FRIDAY_HACKER_AGENT_PROMPT=/opt/friday/hacker-agent-prompt.md \
    PLAYWRIGHT_BROWSERS_PATH=/ms-playwright

ENV PATH="${PATH}:${GHIDRA_INSTALL_DIR}:${GHIDRA_INSTALL_DIR}/support:${GREENHOUSE_INSTALL_DIR}:${GREENHOUSE_INSTALL_DIR}/bin"

COPY docker/patches/greenhouse-loop-kpartx.patch /opt/friday/patches/greenhouse-loop-kpartx.patch
COPY docker/patches/greenhouse-docker-ipam-none.patch /opt/friday/patches/greenhouse-docker-ipam-none.patch

RUN rm -f /etc/apt/sources.list.d/yarn.list \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
        binutils \
        binwalk \
        afl++ \
        bubblewrap \
        build-essential \
        ca-certificates \
        cpio \
        curl \
        dnsutils \
        docker.io \
        elfutils \
        fakechroot \
        file \
        fuse-overlayfs \
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
        python3-capstone \
        python3-pip \
        python3-pyelftools \
        python3-unicorn \
        python3-venv \
        proot \
        qemu-system-arm \
        qemu-system-mips \
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
    && (getent group docker >/dev/null || groupadd docker) \
    && usermod -aG docker vscode \
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
    && if [ -n "${GREENHOUSE_REPO}" ]; then \
        if [ -n "${GREENHOUSE_REF}" ]; then \
            git clone --depth 1 --branch "${GREENHOUSE_REF}" "${GREENHOUSE_REPO}" "${GREENHOUSE_INSTALL_DIR}"; \
        else \
            git clone --depth 1 "${GREENHOUSE_REPO}" "${GREENHOUSE_INSTALL_DIR}"; \
        fi; \
        if [ -f "${GREENHOUSE_INSTALL_DIR}/Dockerfile" ]; then \
            sed -i '/RUN git clone -q https:\/\/github.com\/angr\/angr-dev/a RUN . /root/venv/bin/activate \&\& pip install "pip==23.3.2" "setuptools==64.0.1" "wheel==0.41.3"' "${GREENHOUSE_INSTALL_DIR}/Dockerfile"; \
            sed -i '/RUN cd \/work\/FirmAE && \.\/install\.sh/a RUN cd /work/FirmAE/binwalk-2.3.3 \&\& python3 -m pip install .' "${GREENHOUSE_INSTALL_DIR}/Dockerfile"; \
            sed -i 's|RUN cd /angr-dev && . /root/venv/bin/activate && ./setup.sh -i -D "archinfo pyvex cle claripy ailment angr angr-doc binaries"|RUN cd /angr-dev \&\& . /root/venv/bin/activate \&\& sed -i -e '"'"'s/^REPOS_CPYTHON=.*/REPOS_CPYTHON=${REPOS_CPYTHON-}/'"'"' -e '"'"'s/--pre capstone scikit-build-core/capstone==5.0.1 scikit-build-core/g'"'"' -e '"'"'s/unicorn==2\\.1\\.4/unicorn==2.0.1.post1/g'"'"' -e '"'"'s/pip install -U pip "setuptools>=66.1.0" setuptools-rust wheel cffi/pip install "pip==23.3.2" "setuptools==64.0.1" setuptools-rust "wheel==0.41.3" cffi/g'"'"' -e '"'"'s/pip3 install -U ipython pylint ipdb nose nose-timer coverage flaky keystone-engine.*/pip3 install "keystone-engine==0.9.2" # skipped optional helper tools for greenhouse build/g'"'"' setup.sh \&\& sed -i '"'"'/info "Installing python packages!"/i for repo in archinfo pyvex cle claripy ailment angr; do if [ -f "$repo/pyproject.toml" ]; then sed -i -E "s/^license = \\\\\\\"([^\\\\\\\"]+)\\\\\\\"/license = {text = \\\\\\\"\\\\1\\\\\\\"}/; /^license-files = /d" "$repo/pyproject.toml"; fi; done'"'"' setup.sh \&\& ! grep -nE -- '"'"'--pre capstone\|unicorn==2\\.1\\.4\|capstone<6\|wheel<0\\.42'"'"' setup.sh \&\& ./setup.sh -i -b "${GREENHOUSE_ANGR_TAG}" -D "archinfo pyvex cle claripy ailment angr binaries"|' "${GREENHOUSE_INSTALL_DIR}/Dockerfile"; \
            sed -i 's#RUN cd /work/FirmAE/analyses/routersploit && git apply /work/FirmAE/analyses/routersploit_patch#RUN cd /work/FirmAE/analyses/routersploit \&\& git apply /work/FirmAE/analyses/routersploit_patch || echo "warning: skipped corrupt routersploit patch"#' "${GREENHOUSE_INSTALL_DIR}/Dockerfile"; \
            sed -i "s/\\\${GREENHOUSE_ANGR_TAG}/${GREENHOUSE_ANGR_TAG}/g" "${GREENHOUSE_INSTALL_DIR}/Dockerfile"; \
        fi; \
        if [ -f "${GREENHOUSE_INSTALL_DIR}/run.sh" ]; then \
            sed -i 's/--max_cycles=26 -rh /--max_cycles=26 -rh -nd /' "${GREENHOUSE_INSTALL_DIR}/run.sh"; \
            sed -i 's#^/gh/test\.sh#if [ -e /testimage.raw ]; then /gh/test.sh; else echo "Skipping Greenhouse test.sh: /testimage.raw fixture missing"; fi#' "${GREENHOUSE_INSTALL_DIR}/run.sh"; \
        fi; \
        if [ -f "${GREENHOUSE_INSTALL_DIR}/FirmAEreplacements/install.sh" ]; then \
            sed -i '/cd binwalk-2\.3\.3 && \\/a\  sed -i "/downloads\\.tuxfamily\\.org/s|^|# skipped unreachable optional StuffIt extractor: |" deps.sh \&\& \\' "${GREENHOUSE_INSTALL_DIR}/FirmAEreplacements/install.sh"; \
            sed -i 's#cd ./analyses/routersploit && patch -p1 < ../routersploit_patch && cd -#cd ./analyses/routersploit \&\& patch -p1 < ../routersploit_patch || echo "warning: skipped corrupt routersploit patch"; cd -#' "${GREENHOUSE_INSTALL_DIR}/FirmAEreplacements/install.sh"; \
        fi; \
        git -C "${GREENHOUSE_INSTALL_DIR}" apply /opt/friday/patches/greenhouse-loop-kpartx.patch; \
        git -C "${GREENHOUSE_INSTALL_DIR}" apply --ignore-whitespace /opt/friday/patches/greenhouse-docker-ipam-none.patch; \
        if [ "${GREENHOUSE_BUILD}" = "1" ] && [ -f "${GREENHOUSE_INSTALL_DIR}/Makefile" ]; then \
            make -C "${GREENHOUSE_INSTALL_DIR}"; \
        elif [ -f "${GREENHOUSE_INSTALL_DIR}/Makefile" ]; then \
            echo "Greenhouse cloned to ${GREENHOUSE_INSTALL_DIR}; skipping make during image build. Run make at runtime after starting Docker-in-Docker."; \
        else \
            echo "Greenhouse cloned to ${GREENHOUSE_INSTALL_DIR}, but no Makefile was found; skipping make."; \
        fi; \
    else \
        if [ "${GREENHOUSE_REQUIRED}" = "1" ]; then \
            echo "GREENHOUSE_REQUIRED=1 but GREENHOUSE_REPO is not set; cannot build a Greenhouse-enabled image." >&2; \
            exit 1; \
        fi; \
        echo "GREENHOUSE_REPO is not set; skipping Greenhouse clone/build."; \
    fi \
    && rm -rf /var/lib/apt/lists/*

RUN if [ -d "${GREENHOUSE_INSTALL_DIR}" ]; then \
        chown -R vscode:docker "${GREENHOUSE_INSTALL_DIR}" \
        && chmod -R g+rwX "${GREENHOUSE_INSTALL_DIR}"; \
    fi

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
3. QEMU user/system emulation, `proot`, `fakechroot`, `binwalk`, and common filesystem extractors.

Greenhouse is cloned from `https://github.com/sefcom/greenhouse.git` by default, unless the Docker image is built with `--build-arg GREENHOUSE_REPO=<repo-url>` to override it. Docker CLI/daemon tooling is available in the image for Greenhouse and nested container workflows; run the image with privileged Docker capabilities when starting a nested daemon. Greenhouse's Makefile uses Docker, so run `start-dind make -C /opt/greenhouse` at runtime after the container starts. `start-dind` tries `overlay2`, `fuse-overlayfs`, then `vfs` unless `DOCKERD_STORAGE_DRIVER` is set. For modular firmware emulation, check `/opt/greenhouse` first and use Greenhouse before falling back to QEMU/proot/fakechroot/chroot.

You can find other related tooling in the /input/.

For firmware confirmation work, run this image as root with privileged Docker capabilities when chroot, mount namespaces, writable `/run`, or package installation are needed. The `router-agent.sh` wrapper does this by default and restores host ownership of generated workspace outputs after the run.

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

1. Use Greenhouse first when `/opt/greenhouse` exists. If Greenhouse is absent and this scan requires Greenhouse, stop and document that the image was built without `GREENHOUSE_REPO`. Only fall back to QEMU/proot/fakechroot/chroot when Greenhouse is unavailable and the user did not require Greenhouse.
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

RUN printf '%s\n' \
    '#!/usr/bin/env bash' \
    'set -euo pipefail' \
    'root_cmd=()' \
    'if [ "$(id -u)" -ne 0 ]; then' \
    '  root_cmd=(sudo)' \
    'fi' \
    'storage_drivers="${DOCKERD_STORAGE_DRIVER:-overlay2 fuse-overlayfs vfs}"' \
    'dockerd_group="${DOCKERD_GROUP:-docker}"' \
    'dockerd_pid=/tmp/dockerd.pid' \
    'dockerd_log=/tmp/dockerd.log' \
    'export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/opt/ghidra:/opt/ghidra/support' \
    '"${root_cmd[@]}" mkdir -p /run /var/lib/docker' \
    '"${root_cmd[@]}" ln -sfn /run /var/run' \
    '"${root_cmd[@]}" rm -f /var/run/docker.sock "$dockerd_pid"' \
    'if ! docker info >/dev/null 2>&1; then' \
    '  for storage_driver in $storage_drivers; do' \
    '    "${root_cmd[@]}" rm -f /var/run/docker.sock "$dockerd_pid"' \
    '    "${root_cmd[@]}" dockerd --host unix:///var/run/docker.sock --group "$dockerd_group" --storage-driver "$storage_driver" --pidfile "$dockerd_pid" > "$dockerd_log" 2>&1 &' \
    '    for _ in $(seq 1 60); do' \
    '      if docker info >/dev/null 2>&1; then' \
    '        echo "dockerd started with storage driver: $storage_driver" >&2' \
    '        break 2' \
    '      fi' \
    '      sleep 1' \
    '    done' \
    '    "${root_cmd[@]}" cat "$dockerd_log" >&2 || true' \
    '    if [ -f "$dockerd_pid" ]; then' \
    '      "${root_cmd[@]}" kill "$(cat "$dockerd_pid")" >/dev/null 2>&1 || true' \
    '      sleep 2' \
    '    fi' \
    '  done' \
    'fi' \
    'if [ -S /var/run/docker.sock ]; then' \
    '  "${root_cmd[@]}" chgrp "$dockerd_group" /var/run/docker.sock 2>/dev/null || true' \
    '  "${root_cmd[@]}" chmod 0666 /var/run/docker.sock 2>/dev/null || true' \
    'fi' \
    'if ! docker info >/dev/null 2>&1; then' \
    '  "${root_cmd[@]}" cat "$dockerd_log" >&2 || true' \
    '  exit 1' \
    'fi' \
    'if [ "$#" -gt 0 ]; then' \
    '  exec "$@"' \
    'fi' \
    'exec bash' \
    > /usr/local/bin/start-dind \
    && chmod 0755 /usr/local/bin/start-dind

COPY requirements.txt /tmp/friday-requirements.txt
RUN install -d -m 0755 /ms-playwright \
    && python -m pip install -r /tmp/friday-requirements.txt \
    && python -m pip install declib \
    && python -m pip install pyghidra \
    && python -m playwright install --with-deps chromium \
    && rm /tmp/friday-requirements.txt

USER vscode

RUN mkdir -p "${CODEX_HOME}"

CMD ["sleep", "infinity"]
