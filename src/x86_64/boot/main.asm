global start

section .text
bits 32
start:
    ; Writing to video memory
    mov dword [0xb8000], 0x2f4b2f4f ; 0x2f4b2f4f = "OK"
    hlt
