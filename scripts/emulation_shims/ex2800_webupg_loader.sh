#!/bin/sh
# User-mode-emulation loader for the EX2800's ET_DYN webupg executable.
# Physical firmware executes webupg directly. Some QEMU/PRoot combinations
# mis-relocate this unusual executable, so invoke its shipping uClibc loader
# explicitly while leaving the original binary unchanged as webupg.bin.
exec /lib/ld-uClibc.so.0 /usr/www/cgi-bin/webupg.bin
