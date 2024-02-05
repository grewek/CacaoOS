#ifndef __IO_H__
#define __IO_H__

//NOTE(Kay): Three times we copied this stuff now time for a header !
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char i8;
typedef signed char i16;
typedef signed char i32;


u8 port_communication_byte_in(u16 port);

#endif
