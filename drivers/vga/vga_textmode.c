#include "vga_textmode.h"
//TODO(Kay): We got repetition here so we need a general type header like stdint cacaoTypes.h ? :)
static DisplayWriter __DisplayWriter = {
    .currentPosition = (u16 *)VIDEO_MEMPORY_PTR_START,
    .defaultFG = WHITE,
    .defaultBG = BLACK,

    .cellX = 0,
    .cellY = 0,
};

static const char* test_str = "This is a test string";

//Calculates the coordinate of the character 
u16 GenerateVideoCoordinate(u16 x, u16 y) {
    return y * SCREEN_WIDTH + x;    
}

u8 GenerateColorAttribute(ColorAttrib fg, ColorAttrib bg) {
    u8 result = ((u8)bg << 4 | (u8)fg);
    return result;
}

void kputstr(const char *str, u32 strlen, ColorAttrib fg, ColorAttrib bg) {
    u16 *videoMemory = (u16 *)0xb8000;
    
    for(i32 i = 0; i < strlen; i++) {
        *videoMemory++ = (u16)GenerateColorAttribute(fg, bg) << 8 | str[i];
    }
}

static void Write(DisplayWriter *writer, const char *str, const u32 len) {
    //TODO(Kay): This is not working as i would expect it to work this is either due to me
    //           not doing the initialization of the struct correctly (which might be a possibility)
    //           or things are not correctly laid out in memory which might be very possible as well:
    //              SOLUTIONS:
    //                  1.) Figure out how we initialize a global variable that is static to the current file
    //                  2.) Write a Linkerscript that makes sure that has a alignment for .data, .bss as well !
    //                  3.) Despair if none of the above works !
    if(writer->currentPosition != VIDEO_MEMPORY_PTR_START) {
        kputstr("[CUTHULU] Struct was not initialized as expected !",50, RED, BLACK);
    }
    //kputstr(test_str, 21, WHITE, BLACK);
    //NOT WORKING ?!
    //while(*str) {
    //    writer->currentPosition[GenerateVideoCoordinate(writer->cellX, writer->cellY)] = 
    //        (((u16)GenerateColorAttribute(writer->defaultFG, writer->defaultBG) << 8) | ((u16)(*str)));
    //    writer->cellX += 1;
    //}
}

extern void kernel_putstr(const char *str, u32 len) {
    Write(&__DisplayWriter, str, len);
}

void test_kputstr() {
    const char *hello = "Hello World of Kernel Programming !";
    kputstr(hello, 35, WHITE, BLACK);
}

//This is a test function as i currently have no way of writing tests i probably have to do manual testing
void video_test_writes() {
    //Check if we can write onto the start of the video buffer in consecutive order without gaps !
    u16 *videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(0, 0));
    *videoMemory = (u16)GenerateColorAttribute(WHITE, BLUE) << 8 | (u16) 'S';

    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(1, 0));
    *videoMemory = (u16)GenerateColorAttribute(WHITE, BLUE) << 8 | (u16) 'T';

    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(2, 0));
    *videoMemory = (u16)GenerateColorAttribute(WHITE, BLUE) << 8 | (u16) 'A';

    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(3, 0));
    *videoMemory = (u16)GenerateColorAttribute(WHITE, BLUE) << 8 | (u16) 'R';

    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(4, 0));
    *videoMemory = (u16)GenerateColorAttribute(WHITE, BLUE) << 8 | (u16) 'T';

    //Check if the we can move our "cursor" onto the next line and write there with no gaps !
    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(0, 1));
    *videoMemory = (u16)0x0f << 8 | (u16) 'L';

    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(1, 1));
    *videoMemory = (u16)0x0f << 8 | (u16) 'I';

    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(2, 1));
    *videoMemory = (u16)0x0f << 8 | (u16) 'N';

    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(3, 1));
    *videoMemory = (u16)0x0f << 8 | (u16) 'E';

    //Check if we can write to the middle of the screen
    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(40, 12));
    *videoMemory = (u16)0x0f << 8 | (u16) 'C';
}

void video_buffer_simple_write() {
    //u16 *videoMemory = (u16 *)0xb8000;
    //*videoMemory = (u16)0x0f << 8 | (u16) 'A';
}