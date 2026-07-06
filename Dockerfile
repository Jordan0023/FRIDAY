FROM ubuntu:24.04

ARG NODE_MAJOR=20

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
    && npm install -g @openai/codex \
    && ghidra_asset_url="$(curl -fsSL https://api.github.com/repos/NationalSecurityAgency/ghidra/releases/latest \
        | jq -r '.assets[] | select(.name | test("PUBLIC.*\\.zip$")) | .browser_download_url' \
        | head -n 1)" \
    && curl -fsSL "${ghidra_asset_url}" -o /tmp/ghidra.zip \
    && unzip -q /tmp/ghidra.zip -d /opt \
    && mv /opt/ghidra_* "${GHIDRA_INSTALL_DIR}" \
    && ln -s "${GHIDRA_INSTALL_DIR}/support/analyzeHeadless" /usr/local/bin/analyzeHeadless \
    && ln -s "${GHIDRA_INSTALL_DIR}/ghidraRun" /usr/local/bin/ghidraRun \
    && rm /tmp/ghidra.zip \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspaces/FRIDAY

COPY requirements.txt /tmp/friday-requirements.txt
RUN install -d -m 0755 /ms-playwright \
    && python -m pip install -r /tmp/friday-requirements.txt \
    && python -m pip install declib \
    && python -m playwright install --with-deps chromium \
    && rm /tmp/friday-requirements.txt

USER vscode

RUN mkdir -p "${CODEX_HOME}"

CMD ["sleep", "infinity"]
