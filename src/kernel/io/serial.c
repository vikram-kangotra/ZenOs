#include "kernel/io.h"

#define PORT 0x3f8

int init_serial() {
    outportb(PORT + 1, 0x00);    // Disable all interrupts
    outportb(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
    outportb(PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
    outportb(PORT + 1, 0x00);    //                  (hi byte)
    outportb(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
    outportb(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
    outportb(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
    outportb(PORT + 4, 0x1E);    // Set in loopback mode, test the serial chip
    outportb(PORT + 0, 0xAE);    // Test serial chip (send byte 0xAE and check if serial returns same byte)
    if (inportb(PORT) != 0xAE) {
        return 1;
    }
    outportb(PORT + 4, 0x0F);    // Test passed, (normal operation mode)
    return 0;
}
