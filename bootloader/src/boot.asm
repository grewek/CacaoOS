[org 0x7C00]

;;--- Setup the stack !
mov bp, 0x8000
mov sp, bp

lea bx, cacao_bootloader_msg ;;Our starting address
call print_string

;;--- Debug Function for Printing hex values
lea bx, hex_template
add bx, 0x04
mov dx, 0x1fb6
call print_hex

lea bx, hex_template
call print_string


lea bx, cacao_log_msg
call print_string

jmp $

%include "include/display.asm"

cacao_bootloader_msg: 
db "Bootloader Cacao_OS is booting please wait !",0
cacao_log_msg:
db 13,10,"[INFO] Bootloader reached Stage 0",0

hex_template:
db 13,10,"0x0000",0

times 510-($-$$) db 0

dw 0xaa55

