#!/usr/bin/env python3
"""Defensive regression model for authenticated X3000 push commands.

This does not communicate with a router or vendor service. It models the
minimum checks a repaired device must perform before dispatching a bounded
operation.
"""

import argparse
import hashlib
import hmac
import json
import time
import unittest


DEVICE_A = "synthetic-device-a"
DEVICE_B = "synthetic-device-b"
KEY_A = bytes.fromhex("11" * 32)
KEY_B = bytes.fromhex("22" * 32)
ALLOWED_OPERATIONS = {"sync_state", "refresh_profile"}


def canonical(message):
    signed = {
        "device_id": message["device_id"],
        "expires_at": message["expires_at"],
        "nonce": message["nonce"],
        "operation": message["operation"],
        "parameters": message.get("parameters", {}),
    }
    return json.dumps(signed, sort_keys=True, separators=(",", ":")).encode()


def sign(message, key):
    message = dict(message)
    message["signature"] = hmac.new(key, canonical(message), hashlib.sha256).hexdigest()
    return message


class CommandValidator:
    def __init__(self, device_id, key, now):
        self.device_id = device_id
        self.key = key
        self.now = now
        self.seen_nonces = set()

    def validate(self, message):
        required = {"device_id", "expires_at", "nonce", "operation", "signature"}
        if not required.issubset(message):
            return False, "missing-field"
        if message["device_id"] != self.device_id:
            return False, "wrong-device"
        if message["operation"] not in ALLOWED_OPERATIONS:
            return False, "operation-not-allowed"
        if not isinstance(message["expires_at"], int) or message["expires_at"] < self.now:
            return False, "expired"
        if message["expires_at"] > self.now + 300:
            return False, "expiry-too-distant"
        nonce = message["nonce"]
        if not isinstance(nonce, str) or len(nonce) < 16:
            return False, "invalid-nonce"
        if nonce in self.seen_nonces:
            return False, "replay"
        expected = hmac.new(self.key, canonical(message), hashlib.sha256).hexdigest()
        if not hmac.compare_digest(message["signature"], expected):
            return False, "invalid-signature"
        self.seen_nonces.add(nonce)
        return True, "accepted"


def base_message(device=DEVICE_A, nonce="0011223344556677", now=2_000_000_000):
    return {
        "device_id": device,
        "expires_at": now + 60,
        "nonce": nonce,
        "operation": "sync_state",
        "parameters": {},
    }


class SecurityRegressionTests(unittest.TestCase):
    NOW = 2_000_000_000

    def validator(self, device=DEVICE_A, key=KEY_A):
        return CommandValidator(device, key, self.NOW)

    def test_valid_device_bound_command_is_accepted(self):
        accepted, reason = self.validator().validate(sign(base_message(), KEY_A))
        self.assertEqual((accepted, reason), (True, "accepted"))

    def test_unsigned_command_is_rejected(self):
        accepted, reason = self.validator().validate(base_message())
        self.assertEqual((accepted, reason), (False, "missing-field"))

    def test_cross_device_command_is_rejected(self):
        message = sign(base_message(device=DEVICE_B), KEY_B)
        accepted, reason = self.validator().validate(message)
        self.assertEqual((accepted, reason), (False, "wrong-device"))

    def test_wrong_device_key_is_rejected(self):
        message = sign(base_message(), KEY_B)
        accepted, reason = self.validator().validate(message)
        self.assertEqual((accepted, reason), (False, "invalid-signature"))

    def test_replay_is_rejected(self):
        validator = self.validator()
        message = sign(base_message(), KEY_A)
        self.assertEqual(validator.validate(message), (True, "accepted"))
        self.assertEqual(validator.validate(message), (False, "replay"))

    def test_expired_command_is_rejected(self):
        message = base_message()
        message["expires_at"] = self.NOW - 1
        accepted, reason = self.validator().validate(sign(message, KEY_A))
        self.assertEqual((accepted, reason), (False, "expired"))

    def test_tampered_command_is_rejected(self):
        message = sign(base_message(), KEY_A)
        message["operation"] = "refresh_profile"
        accepted, reason = self.validator().validate(message)
        self.assertEqual((accepted, reason), (False, "invalid-signature"))

    def test_shell_operation_is_rejected_even_when_signed(self):
        message = base_message()
        message["operation"] = "sh_exec"
        accepted, reason = self.validator().validate(sign(message, KEY_A))
        self.assertEqual((accepted, reason), (False, "operation-not-allowed"))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--json", action="store_true", help="emit a compact result")
    args, unittest_args = parser.parse_known_args()
    suite = unittest.defaultTestLoader.loadTestsFromTestCase(SecurityRegressionTests)
    result = unittest.TextTestRunner(verbosity=0).run(suite)
    if args.json:
        print(
            json.dumps(
                {
                    "tests_run": result.testsRun,
                    "failures": len(result.failures),
                    "errors": len(result.errors),
                    "passed": result.wasSuccessful(),
                },
                sort_keys=True,
            )
        )
    return 0 if result.wasSuccessful() else 1


if __name__ == "__main__":
    raise SystemExit(main())
