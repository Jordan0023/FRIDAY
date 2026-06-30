FROM mcr.microsoft.com/devcontainers/python:1-3.12-bookworm

ARG NODE_MAJOR=20

ENV PYTHONDONTWRITEBYTECODE=1 \
    PYTHONUNBUFFERED=1 \
    PIP_NO_CACHE_DIR=1 \
    PLAYWRIGHT_BROWSERS_PATH=/ms-playwright

RUN rm -f /etc/apt/sources.list.d/yarn.list \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
        binwalk \
        bubblewrap \
        build-essential \
        ca-certificates \
        cpio \
        curl \
        file \
        git \
        gnupg \
        jq \
        less \
        p7zip-full \
        qemu-user-static \
        ripgrep \
        squashfs-tools \
        sudo \
        unzip \
        wget \
        xz-utils \
    && install -d -m 0755 /etc/apt/keyrings \
    && curl -fsSL "https://deb.nodesource.com/gpgkey/nodesource-repo.gpg.key" \
        | gpg --dearmor -o /etc/apt/keyrings/nodesource.gpg \
    && echo "deb [signed-by=/etc/apt/keyrings/nodesource.gpg] https://deb.nodesource.com/node_${NODE_MAJOR}.x nodistro main" \
        > /etc/apt/sources.list.d/nodesource.list \
    && apt-get update \
    && apt-get install -y --no-install-recommends nodejs \
    && npm install -g @openai/codex \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspaces/FRIDAY

COPY requirements.txt /tmp/friday-requirements.txt
RUN install -d -m 0755 /ms-playwright \
    && python -m pip install --upgrade pip \
    && python -m pip install -r /tmp/friday-requirements.txt \
    && python -m playwright install --with-deps chromium \
    && rm /tmp/friday-requirements.txt

USER vscode

RUN mkdir -p /home/vscode/.codex

CMD ["sleep", "infinity"]
