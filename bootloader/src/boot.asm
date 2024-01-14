[org 0x7C00]

mov [BOOT_DRIVE], dl
;;--- Setup the stack !
mov bp, 0x8000
mov sp, bp

;;--- Testing areas for all kind of functions !
xor bx, bx
xor dx, dx

mov bx, 0x9000
mov dh, 5
mov dl, [BOOT_DRIVE]
call disk_load

lea bx, hex_template
mov dx, [0x9000]
call print_hex

lea bx, hex_template
call print_string

lea bx, hex_template
mov dx, [0x9000 + 512]
call print_hex

lea bx, hex_template
call print_string

lea bx, cacao_log_msg
call print_string

jmp $

%include "include/display.asm"
%include "include/disk.asm"

;cacao_bootloader_msg: 
;db "Bootloader Cacao_OS is booting please wait !",0
cacao_log_msg:
db 13,10,"[INFO] Bootloader reached Stage 0",0

hex_template:
db "0000",0

BOOT_DRIVE: db 0

times 510-($-$$) db 0
dw 0xaa55

times 256 dw 0xdada
times 256 dw 0xface

