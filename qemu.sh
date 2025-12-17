#!/bin/bash
qemu-system-x86_64 \
  -m 256M \
  -machine q35 \
  -drive if=pflash,format=raw,readonly=on,file=/usr/share/OVMF/OVMF_CODE_4M.fd \
  -drive if=pflash,format=raw,file=/usr/share/OVMF/OVMF_VARS_4M.fd \
  -drive file=build/uefi.img,format=raw \
  -serial stdio


