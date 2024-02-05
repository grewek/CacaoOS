clang -m32 -fno-stack-protector -ffreestanding -fno-pie -c io/io.c -o ./bin/io.o
clang -m32 -fno-stack-protector -ffreestanding -fno-pie -c vga/vga_textmode.c -o ./bin/vga_textmode.o