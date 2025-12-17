cmake_minimum_required(VERSION 3.20)
project(uefi_boot C)

# Tell CMake to use cross-compiler
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)


add_executable(BOOTX64.EFI boot/boot.c)


target_link_options(BOOTX64.EFI PRIVATE
    -nostdlib
    -Wl,--subsystem,10
    -Wl,--entry,efi_main
    -Wl,--image-base,0
    -Wl,--disable-dynamicbase
    -Wl,--no-seh
)


target_compile_options(BOOTX64.EFI PRIVATE
    -ffreestanding
    -fno-stack-protector
    -fno-pic
    -fno-pie
    -mno-red-zone
    -fno-asynchronous-unwind-tables
    -fno-unwind-tables
)

