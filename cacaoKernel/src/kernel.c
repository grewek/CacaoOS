#include "../../drivers/vga/vga_textmode.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char i8;
typedef signed char i16;
typedef signed char i32;


void main() {
    Clear();
    Kernel_Print("[INFO]\tCacao OS Kernel Booted !\n");
    Kernel_Print("[TEST]\tThis line will overflow the screen size by multiple characters but kernel_print will just increase the line number and print the rest of the text to the next line !");
}