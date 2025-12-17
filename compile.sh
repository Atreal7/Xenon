#!/bin/bash
cd build
cmake --build .
mkdir -p fat/EFI/BOOT
cp BOOTX64.EFI fat/EFI/BOOT/

dd if=/dev/zero of=uefi.img bs=1M count=64
mkfs.vfat uefi.img
mcopy -i uefi.img -s fat/* ::

