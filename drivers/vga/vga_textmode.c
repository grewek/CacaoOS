#include "vga_textmode.h"
//TODO(Kay): We got repetition here so we need a general type header like stdint cacaoTypes.h ? :)


//Calculates the coordinate of the character 
u16 GenerateVideoCoordinate(u16 x, u16 y) {
    return y * SCREEN_WIDTH + x;    
}

//This is a test function as i currently have no way of writing tests i probably have to do manual testing
void video_test_writes() {
    //Check if we can write onto the start of the video buffer in consecutive order without gaps !
    u16 *videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(0, 0));
    *videoMemory = (u16)0x0f << 8 | (u16) 'S';

    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(1, 0));
    *videoMemory = (u16)0x0f << 8 | (u16) 'T';

    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(2, 0));
    *videoMemory = (u16)0x0f << 8 | (u16) 'A';

    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(3, 0));
    *videoMemory = (u16)0x0f << 8 | (u16) 'R';

    videoMemory = (u16 *)0xb8000 + (GenerateVideoCoordinate(4, 0));
    *videoMemory = (u16)0x0f << 8 | (u16) 'T';

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


    u16 *videoMemory = (u16 *)0xb8000;
    *videoMemory = (u16)0x0f << 8 | (u16) 'A';
}