section .multiboot_header
align 4
header_start:
    ; magic number
    dd 0xe85250d6 ; multiboot2
    ; architecture
    dd 0 ; protected mode i386
    ; header_length
    dd header_end - header_start
    ; checksum
    dd 0x100000000 - (0xe85250d6 + 0 + header_end - header_start)
header_end:

align 8
framebuffer_tag_start:
    ; type
    dw 5
    ; flags
    dw 0
    ; size
    dd framebuffer_tag_end - framebuffer_tag_start
    ; width
    dd 1024
    ; height
    dd 768
    ; depth
    dd 32
framebuffer_tag_end:

align 8
    dw 0
    dw 0
    dd 8
