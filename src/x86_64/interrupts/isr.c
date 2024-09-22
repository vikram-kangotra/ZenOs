#include "print.h"

void isr_default_handler() {
    print_str("Unhandled interrupt\n");
    while (1);
}
