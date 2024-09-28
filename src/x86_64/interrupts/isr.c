#include "print.h"

void isr_default_handler() {
    kprintf("Unhandled interrupt\n");
    while (1);
}
