#
nasm src/entry.asm -f elf -o bin/entry.o 
clang -m32 -ffreestanding -fno-pie -c src/kernel.c -o bin/kernel.o
ld -m elf_i386 -no-pie -o bin/kernel.bin -Ttext 0x1000 bin/entry.o ../drivers/bin/vga_textmode.o bin/kernel.o --oformat binary -v