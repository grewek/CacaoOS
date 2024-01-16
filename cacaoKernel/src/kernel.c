typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char i8;
typedef signed char i16;
typedef signed char i32;

void main() {
    u16 *videoMemory = (u16 *)0xb8000;
    *videoMemory = (u16)0x0f << 8 | (u16) 'X';

    //*videoMemory++ = 0x0f;
}