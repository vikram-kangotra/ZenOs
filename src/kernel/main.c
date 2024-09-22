#include "print.h"
#include "interrupts/idt.h"
#include "multiboot2/multiboot2.h"

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

    idt_init();

    asm volatile("sti");
}
