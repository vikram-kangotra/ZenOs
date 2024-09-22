#include "print.h"

void isr_default_handler() {
    print_str("Unhandled interrupt\n");
    while (1);
}

void isr_divide_by_zero() {
    print_str("Divide by zero\n");
    while (1);
}
