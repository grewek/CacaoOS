#include "vga_textmode.h"

//TODO(Kay): Give this another shot may it was just the missing entry point that prevented it from working !
static DisplayWriter __DisplayWriter = {
    .currentPosition = (u16 *)VIDEO_MEMPORY_PTR_START,
    .defaultFG = WHITE,
    .defaultBG = BLACK,

    .cellX = 0,
    .cellY = 0,
};

u16 *VideoPtr = (u16 *)VIDEO_MEMPORY_PTR_START;
ColorAttrib ForegroundColor = WHITE;
ColorAttrib BackgroundColor = BLACK;
u16 CurrentCellX = 0;
u16 CurrentCellY = 0;

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

static void Write(const char *str, const u32 len) {
    if(VideoPtr != VIDEO_MEMPORY_PTR_START) {
        kputstr("[CUTHULU] Struct was not initialized as expected !",50, RED, BLACK);
    }

    //TODO(Kay): Should we advance the Videoptr by the amount of consumed bytes ?
    //           or is it better to have the Videoptr constant and only treat the
    //           Videomemory like a linear array ?
    while(*str) {
        VideoPtr[GenerateVideoCoordinate(CurrentCellX, CurrentCellY)] = 
            (((u16)GenerateColorAttribute(ForegroundColor, BackgroundColor) << 8) | ((u16)(*str)));
        CurrentCellX += 1; str++;
    }
}

extern void kernel_putstr(const char *str, u32 len) {
    //kputstr(test_str, 21, WHITE, BLACK);
    Write(str, len);
extern void Clear() {   
    const u16 clearValue = 0x0000;
    for(u16 nextCell = 0; nextCell < SCREEN_WIDTH * SCREEN_HEIGHT; nextCell++) {
        VideoPtr[nextCell] = clearValue;
    }

    CurrentCellX = 0;
    CurrentCellY = 0;
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