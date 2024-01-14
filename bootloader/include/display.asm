;;--- Routine: Write String
;; arguments:
;; bx -> ptr to start of string
print_string:
    pusha
    mov ah, 0x0e
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

print_hex:
    pusha
    add bx, 0x03
.processing:
    cmp dx, 0x0000
    je .done
    mov cl, dl
    and cl, 0x0F
    cmp cl, 0x09
    ja .letter
    jle .number

.number:
    mov [bx], byte 0x00
    add [bx], cl
    add [bx], byte 0x30
    dec bx
    shr dx, 0x04
    jmp .processing

.letter:
    sub cl, 0x09
    mov [bx], byte 0x00
    add [bx], cl
    add [bx], byte 0x40
    dec bx
    shr dx, 0x04
    jmp .processing

.done:
    popa
    ret
