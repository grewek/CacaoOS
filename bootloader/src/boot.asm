

[org 0x7C00]
[bits 16]
KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl
;;--- Setup the stack !
mov bp, 0x8000
mov sp, bp

;;--- Testing areas for all kind of functions !
xor bx, bx
xor dx, dx
mov es, bx ;Clear ES as we are using it to load our kernel to ES:BX !

lea bx, cacao_log_msg
call print_string

call load_kernel
call switch_to_pm

load_kernel:

lea bx, load_kernel_msg
call print_string

mov bx, KERNEL_OFFSET
mov dh, 15
mov dl, [BOOT_DRIVE]
call disk_load

ret

%include "include/display.asm"
%include "include/disk.asm"
%include "include/gdt.asm"
%include "include/pm.asm"
%include "include/video.asm"

[bits 32]
start_protected_mode:
mov ax, DATA_SEG
mov ds, ax
mov ss, ax
mov es, ax
mov fs, ax
mov gs, ax

mov ebp, 0x90000
mov esp, ebp

call BEGIN_PM

BEGIN_PM:
    mov ebx, protected_mode
    call print_string_pm

    ;mov bx, hex_template
    ;mov dx, [KERNEL_OFFSET + 0x01] ;;Check if we did indeed load our kernel
    ;call print_string_pm

    call KERNEL_OFFSET

    jmp $


cacao_log_msg:
db 13,10,"[INFO] Bootloader reached Real Mode Booting Stage",0

load_kernel_msg:
db 13,10,"[INFO] Loading Kernel into Memory",0

protected_mode:
db "[INFO] Bootloader enabled Protected Mode",0

hex_template:
db "0000",0

BOOT_DRIVE: db 0

times 510-($-$$) db 0
dw 0xaa55