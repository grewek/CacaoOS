[bits 32]

VIDEO_MEMORY equ 0xb8000
BW_MODE equ 0x0f

print_string_pm:
    pusha 
    mov edx, VIDEO_MEMORY

.print_string_pm_loop:
    mov al, [ebx]
    mov ah, BW_MODE
    cmp al, 0
    je .done

    mov [edx], ax
    add ebx, 1
    add edx, 2

    jmp .print_string_pm_loop

.done:
    popa 
    ret