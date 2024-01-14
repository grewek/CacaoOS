#!/bin/sh
qemu-system-i386 -m 128 -no-reboot -drive format=raw,media=disk,file=bootloader/bin/boot.bin -serial stdio -smp 1 -usb -vga std
