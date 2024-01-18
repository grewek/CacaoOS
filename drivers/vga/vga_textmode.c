#include "vga_textmode.h"
//TODO(Kay): We got repetition here so we need a general type header like stdint cacaoTypes.h ? :)
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char i8;
typedef signed char i16;
typedef signed char i32;

//Calculates the coordinate of the character 
u16 GenerateVideoCoordinate(u16 x, u16 y) {
    return y * SCREEN_WIDTH + x;    
}
void video_buffer_simple_write() {
    u16 *videoMemory = (u16 *)0xb8000;
    *videoMemory = (u16)0x0f << 8 | (u16) 'A';
}