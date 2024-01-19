#ifndef __VGA_TEXTMODE_H__
#define __VGA_TEXTMODE_H__

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char i8;
typedef signed char i16;
typedef signed char i32;
typedef signed int bool;

#define SCREEN_WIDTH        80
#define SCREEN_HEIGHT       25

void video_test_writes();
void video_buffer_simple_write();

#endif