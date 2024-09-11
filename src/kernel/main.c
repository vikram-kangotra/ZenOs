#include "print.h"
#include "multiboot2/multiboot2.h"

#define to_hex(c) ((c) >= 10 ? 'A' + ((c) - 10) : '0' + (c))

void print_hex(unsigned long num) {
    char hex_digits[16];
    int i = 0;

    print_str("0x");

    if (num == 0) {
        print_str("0");
        return;
    }

    while (num != 0) {
        int rem = num % 16;
        hex_digits[i++] = to_hex(rem);
        num = num / 16;
    }

    while (i > 0) {
        print_char(hex_digits[--i]);
    }
}

void kernel_main(unsigned long magic, unsigned long addr) {
    print_clear();

    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);

    if (magic != MULTIBOOT2_BOOTLOADER_MAGIC) {
        print_str("Invalid magic number: ");
        print_hex(magic);
        return;
    }

    if (addr & 7) {
        print_str("unaligned mbi: ");
        print_hex(addr);
        return;
    }

    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Welcome to ZenOS Kernel");
}
