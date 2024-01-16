typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char i8;
typedef signed char i16;
typedef signed char i32;

void main() {
    u8 *videoMemory = (u8 *)0xb8001;
    *videoMemory = 'X';

    //*videoMemory++ = 0x0f;
}