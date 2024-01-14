[org 0x7C00]

;;--- Setup the stack !
mov bp, 0x8000
mov sp, bp

;;--- Prepare writing to the screen
mov ah, 0x0e                 ;;Teletype please !
mov bx, cacao_bootloader_msg ;;Our starting address
call print_string

mov bx, cacao_log_msg
call print_string
jmp $

;;--- Routine: Write String
print_string:                       ;;Write "Syscall"
    pusha
    call .print_char
    popa
    ret

.print_char:
    cmp al, 0x00
    je .done
    mov al, [bx]
    int 0x10
    inc bx
    jmp .print_char
.done:
    ret

cacao_bootloader_msg: 
db "Bootloader Cacao_OS is booting please wait !",0
cacao_log_msg:
db 13,10,"[INFO] Bootloader reached Stage 0",0

times 510-($-$$) db 0

dw 0xaa55

