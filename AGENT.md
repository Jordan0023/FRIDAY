# Agent Operating Notes

## Development Environment

- Do project work from the devcontainer defined in `.devcontainer/devcontainer.json`.
- Put new system packages, CLIs, browsers, language runtimes, and Python dependencies into `Dockerfile` instead of installing them ad hoc on the host or interactively inside a running container.
- After changing dependencies, rebuild the devcontainer so future sessions inherit the same environment.
- Codex CLI is installed in the image with `npm install -g @openai/codex`.
- Codex authentication is inherited by bind-mounting the host `${HOME}/.codex` directory to `/home/vscode/.codex` in the devcontainer. If auth fails, run `codex login` on the host or inside the devcontainer to refresh the mounted credentials.

## Common Commands

```bash
python netgear_full_download.py --use-browser --analyze
python netgear_watch_new.py --use-browser --analyze
python scripts/build_site_data.py
cd site && python3 -m http.server 8000
```

## Dependency Policy

- Prefer editing `Dockerfile` for install changes, then rebuilding the container.
- Keep generated firmware archives, extracted filesystems, logs, and heavyweight analysis outputs out of Git.
- The image includes Chromium for Playwright, Codex CLI, QEMU user emulation helpers, binwalk, squashfs tools, archive utilities, and basic shell/dev tools.
