import argparse
import importlib.util
import sys
import unittest
from pathlib import Path


SCRIPT = Path(__file__).parents[1] / "scripts" / "ex2800_telnet_login_fuzzer.py"
SPEC = importlib.util.spec_from_file_location("ex2800_telnet_login_fuzzer", SCRIPT)
MODULE = importlib.util.module_from_spec(SPEC)
assert SPEC.loader
sys.modules[SPEC.name] = MODULE
SPEC.loader.exec_module(MODULE)


class EX2800TelnetLoginFuzzerTests(unittest.TestCase):
    def test_corpus_is_bounded_and_named_uniquely(self) -> None:
        cases = MODULE.corpus()
        self.assertLessEqual(len(cases), MODULE.MAX_CASES)
        self.assertEqual(len(cases), len({case.name for case in cases}))
        self.assertTrue(all(len(case.username) <= MODULE.MAX_FIELD for case in cases))

    def test_non_loopback_target_is_rejected(self) -> None:
        with self.assertRaises(argparse.ArgumentTypeError):
            MODULE.loopback("192.0.2.1")

    def test_loopback_target_is_accepted(self) -> None:
        self.assertIn(MODULE.loopback("127.0.0.1"), {"127.0.0.1"})

    def test_results_do_not_claim_rce(self) -> None:
        result = MODULE.run_case("127.0.0.1", 9, MODULE.Case("closed", b"A"), 0.1)
        self.assertTrue(str(result["outcome"]).startswith("connection_error"))
        self.assertFalse(result["possible_shell_prompt"])


if __name__ == "__main__":
    unittest.main()
