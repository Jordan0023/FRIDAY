#!/bin/sh
# Deterministic, network-free output matching the router's BusyBox ping parser.
printf '%s\n' \
  'PING 34.196.94.121 (34.196.94.121): 56 data bytes' \
  '64 bytes from 34.196.94.121: seq=0 ttl=64 time=0.100 ms' \
  '' \
  '--- 34.196.94.121 ping statistics ---' \
  '2 packets transmitted, 2 packets received, 0% packet loss'
