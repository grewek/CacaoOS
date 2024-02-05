#include "io.h"

//TODO(Kay): We should never try to inline this as it could potentially trash our registers ?!
// Retrieves a byte from the specified port
u8 port_communication_byte_in(u16 port) {
    u8 result;

    //NOTE(Kay): Now this is cuthullu stuff right here AT&T syntax and -masm=intel does nothing
    //  thank you compiler devs :) aka "MY EYES THE GOGGLES DO NOTHING..." (simpsons ;) )
    __asm__ ("in %%dx, %%al" : "=a"(result) : "d"(port));
    
    return result;
}

//TODO(Kay): Write data on port !