# GL.iNet global WebUI lockout firmware matrix

- Extracted firmware images: 18
- Current/non-EOL images: 18
- EOL images excluded from active validation: 0
- Current images containing the complete vulnerable state machine: 14
- Distinct vulnerable `gl-ngx-session` implementations: 5

| Product | Version | EOL | Vulnerable logic | Session family |
|---|---:|:---:|:---:|---|
| GL.iNet GL-MT5000 Brume 3 | 4.8.6 | no | yes | `4eb9bdd8b00521de` |
| GL.iNet GL-MT300N-V2 Mango | 4.3.25 | no | no | `5579c23b7ea42025` |
| GL.iNet GL-X300B Collie | 4.5.22 | no | yes | `995a08499137b5f7` |
| GL.iNet GL-MT2500/GL-MT2500A Brume 2 | 4.7.4 | no | yes | `4df035e835092fcb` |
| GL.iNet GL-AR300M16 Shadow | 4.3.27 | no | no | `5579c23b7ea42025` |
| GL.iNet GL-MT3600BE Beryl 7 | 4.9.0 | no | yes | `2457cfae05615780` |
| GL.iNet GL-MT6000 Flint 2 | 4.9.0 | no | yes | `2457cfae05615780` |
| GL.iNet GL-BE10000 Slate 7 Pro | 4.8.4 | no | yes | `6b5aeb3cd9c4644c` |
| GL.iNet GL-X3000 Spitz AX | 4.8.3 | no | yes | `4eb9bdd8b00521de` |
| GL.iNet GL-AX1800 Flint | 4.8.3 | no | yes | `4eb9bdd8b00521de` |
| GL.iNet GL-XE3000 Puli AX | 4.8.3 | no | yes | `4eb9bdd8b00521de` |
| GL.iNet GL-X750 Spitz | 4.3.25 | no | no | `5579c23b7ea42025` |
| GL.iNet GL-MT5000 Brume 3 | 4.9.0 | no | yes | `2457cfae05615780` |
| GL.iNet GL-E750/GL-E750V2 Mudi | 4.3.26 | no | no | `5579c23b7ea42025` |
| GL.iNet GL-BE9300 Flint 3 | 4.9.0 | no | yes | `2457cfae05615780` |
| GL.iNet GL-A1300 Slate Plus | 4.5.22 | no | yes | `995a08499137b5f7` |
| GL.iNet GL-SFT1200 Opal | 4.8.3 | no | yes | `6b5aeb3cd9c4644c` |
| GL.iNet GL-AXT1800 Slate AX | 4.8.3 | no | yes | `4eb9bdd8b00521de` |

Static classification proves code presence, not model-specific runtime reachability. Dynamic HTTP confirmation must be recorded separately.
