#include "../../drivers/vga/vga_textmode.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char i8;
typedef signed char i16;
typedef signed char i32;


void main() {
    kernel_putstr("Hello World !", 13);
    //test_kputstr();
}