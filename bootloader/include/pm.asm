;;%include "include/gdt.asm"
switch_to_pm:
    cli
    lgdt [gdt_descriptor]

    ;;Prepare cr0
    mov eax, cr0
    or eax, 0x1   ;;Set the first bit of cr0
    mov cr0, eax

    jmp CODE_SEG:start_protected_mode

