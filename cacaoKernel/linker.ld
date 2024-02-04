ENTRY(_start)

SECTIONS {
    . = 0x1000; /* Set the starting address of the kernel */

    .text : ALIGN(4K) {
        *(.text)         /* Kernel code */
    }

    .rodata : ALIGN(4K) {
        *(.rodata)       /* Read-only data */
    }

    .data : ALIGN(4K) {
        *(.data)         /* Initialized data */
    }

    .bss : ALIGN(4K) {
        *(.bss)          /* Uninitialized data */
    }

    /DISCARD/ : {
        *(.comment)      /* Discard comments in the kernel */
        *(.note.GNU-stack)
        *(.llvm-addrsig)
    }
}