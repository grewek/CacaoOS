#ifndef __VGA_TEXTMODE_H__
#define __VGA_TEXTMODE_H__

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char i8;
typedef signed char i16;
typedef signed char i32;
typedef signed int bool;

#define VIDEO_MEMPORY_PTR_START     (u16 *)0xb8000
#define SCREEN_WIDTH                80
#define SCREEN_HEIGHT               25

typedef enum ColorAttrib {
    BLACK = 0x00,
    BLUE = 0x01,
    GREEN = 0x02,
    CYAN = 0x03,
    RED = 0x04,
    MAGENTA = 0x05,
    BROWN = 0x06,
    LIGHT_GRAY = 0x07,

    DARK_GRAY = 0x08,
    LIGHT_BLUE = 0x09,
    LIGHT_GREEN = 0x0a,
    LIGHT_CYAN = 0x0b,
    LIGHT_RED = 0x0c,
    PINK = 0x0d,
    YELLOW = 0x0e,
    WHITE = 0x0f,
} ColorAttrib;

typedef struct DisplayWriter {
    u16 *currentPosition; //Field should always be initalized with VIDEO_MEMORY_PTR_START
    
    ColorAttrib defaultFG; //Determines what color the Display writer uses for the foreground by default
    ColorAttrib defaultBG; //Determines what color the Display writer uses for the background by default

    u16 cellX; //Indicates the next X(Columns) Position that can be written into.
    u16 cellY; //Indicates the next Y(Row) Position that can be written into.
} DisplayWriter;

void video_test_writes();
void kputstr(const char *str, u32 strlen, ColorAttrib fg, ColorAttrib bg);
void test_kputstr();
void video_buffer_simple_write();

#endif