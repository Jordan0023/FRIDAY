# GL.iNet global WebUI lockout campaign

## Outcome

The Brume 3 workflow was generalized to every extracted GL.iNet firmware image
that contains `usr/sbin/gl-ngx-session`. The corpus contains 18 firmware
images. Fourteen contain the complete process-global login lockout state
machine, distributed across five distinct session-script hashes.

This campaign result is a static affected-code classification. It does not
claim model-specific runtime confirmation unless a separate two-client HTTP
transcript exists.

## Confirmed baseline

Two distinct session families now have dynamic confirmation:

- 4.8.6: native AArch64 session-service emulation confirmed the global state.
- 4.9.0: native end-to-end HTTP emulation confirmed that ten invalid
  unauthenticated challenges from client A prevent a valid challenge and a
  correctly computed login response from client B.
- Brume 2 4.7.4: native end-to-end HTTP emulation independently reproduced the
  same cross-client 600-second lockout using session family
  `4df035e835092fcb`. Ordinary HTTP and all native tested services remained
  alive.

The 4.9.0 Brume 3 session implementation is byte-identical to the implementation
found in the extracted 4.9.0 images for Beryl 7, Flint 2, and Flint 3. This is
strong cross-product evidence, but it is not a substitute for model-specific
runtime validation.

## Static affected-code matrix

| Session family | Extracted firmware images |
|---|---|
| `2457cfae05615780` | Beryl 7 4.9.0; Flint 2 4.9.0; Brume 3 4.9.0; Flint 3 4.9.0 |
| `4df035e835092fcb` | Brume 2 4.7.4 |
| `4eb9bdd8b00521de` | Brume 3 4.8.6; Spitz AX 4.8.3; Flint 4.8.3; Puli AX 4.8.3; Slate AX 4.8.3 |
| `6b5aeb3cd9c4644c` | Slate 7 Pro 4.8.4; Opal 4.8.3 |
| `995a08499137b5f7` | Collie 4.5.22; Slate Plus 4.5.22 |

The extracted Mango 4.3.25, Shadow 4.3.27, Spitz 4.3.25, and Mudi 4.3.26
images do not contain all seven markers and are not classified as affected by
this exact state machine.

## Reproduction workflow

Run:

```sh
python3 scripts/audit_glinet_global_lockout.py
```

The scanner:

1. associates each extracted session script with its firmware manifest record;
2. collapses duplicate extraction roots;
3. checks all seven required state-machine markers;
4. separates products listed in the repository EOL dataset;
5. groups matching images by the full SHA-256 of `gl-ngx-session`; and
6. regenerates `matrix.json` and `matrix.md`.

## Dynamic-validation priority

Model-specific HTTP validation should target one image from each session family
not already represented by Brume 3:

1. Slate 7 Pro 4.8.4 or Opal 4.8.3 (`6b5aeb3cd9c4644c`);
2. Slate Plus 4.5.22 or Collie 4.5.22 (`995a08499137b5f7`).

Each test must use an isolated network, native firmware `ubusd`, session daemon,
and Nginx/Lua RPC path, plus two independently addressed clients. A confirmation
requires a successful client-B baseline, ten unauthenticated failures from
client A, denial of a valid client-B authentication attempt, proof that ordinary
HTTP remains responsive, and proof that the native services remain alive.

## Classification limits

- Confirmed on Brume 3: unauthenticated administrative WebUI authentication DoS.
- Not demonstrated: whole-router/network-forwarding DoS.
- Not demonstrated: unauthenticated RCE.
- Not established by this campaign: public novelty or vendor confirmation.
- Matching source and byte-identical session scripts support affected-code
  classification; they do not by themselves prove runtime reachability on every
  listed product.
