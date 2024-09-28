#include "print.h"
#include "kernel/serial.h"
#include "kernel/io.h"
#include "interrupts/idt.h"
#include "multiboot2/multiboot2.h"

void kernel_main(unsigned long magic, unsigned long addr) {

    init_serial();

    print_clear();

    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);

    if (magic != MULTIBOOT2_BOOTLOADER_MAGIC) {
        kprintf("Invalid magic number: %x", magic);
        return;
    }

    if (addr & 7) {
        kprintf("unaligned mbi: %x", addr);
        return;
    }

    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    kprintf("Welcome to ZenOS Kernel\n");
    idt_init();
    sti();

    struct multiboot_tag *tag;
    for (tag = (struct multiboot_tag *)(addr + 8);
         tag->type != MULTIBOOT_TAG_TYPE_END;
         tag = (struct multiboot_tag *)((unsigned char *)tag + ((tag->size + 7) & ~7))) {
        
        if (tag->type == MULTIBOOT_TAG_TYPE_FRAMEBUFFER) {
            struct multiboot_tag_framebuffer *fb = (struct multiboot_tag_framebuffer *)tag;
            unsigned int *framebuffer = (unsigned int *)fb->common.framebuffer_addr;
            unsigned int width = fb->common.framebuffer_width;
            unsigned int height = fb->common.framebuffer_height;
            unsigned int pitch = fb->common.framebuffer_pitch;

            write_serial_string("Framebuffer found: ");
            write_serial_hex((unsigned long)framebuffer);
            write_serial_string("\n");
            write_serial_string("Width: ");
            write_serial_hex(width);
            write_serial_string("\n");
            write_serial_string("Height: ");
            write_serial_hex(height);
            write_serial_string("\n");
            write_serial_string("Pitch: ");
            write_serial_hex(pitch);
            write_serial_string("\n");

            for (unsigned int y = 0; y < height; y++) {
                for (unsigned int x = 0; x < width; x++) {
                    framebuffer[x + y * pitch / 4] = 0x00FFFF00; // causing a page fault
                }
            }

        }
    }

 }
