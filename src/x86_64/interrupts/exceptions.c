#include "interrupts/exceptions.h"
#include "print.h"

void print_interrupt_frame(struct InterruptStackFrame *frame) {
    print_str("Interrupt frame at ");
    print_hex((unsigned long)frame);
    print_str("\n");
    print_str("Instruction pointer: ");
    print_hex(frame->instruction_pointer);
    print_str("\n");
    print_str("Code segment: ");
    print_hex(frame->code_segment);
    print_str("\n");
    print_str("CPU flags: ");
    print_hex(frame->cpu_flags);
    print_str("\n");
    print_str("Stack pointer: ");
    print_hex(frame->stack_pointer);
    print_str("\n");
    print_str("Stack segment: ");
    print_hex(frame->stack_segment);
}

void divide_by_zero_handler(struct InterruptStackFrame *frame) {
    print_str("Divide by zero\n");
    print_interrupt_frame(frame);
    while (1);
}

void invalid_opcode_handler(struct InterruptStackFrame *frame) {
    print_str("Invalid opcode\n");
    print_interrupt_frame(frame);
    while (1);
}

void breakpoint_handler(struct InterruptStackFrame *frame) {
    print_str("Breakpoint\n");
    print_interrupt_frame(frame);
    while (1);
}

void double_fault_handler(struct InterruptStackFrame *frame) {
    print_str("Double fault\n");
    print_interrupt_frame(frame);
    while (1);
}

void general_protection_fault_handler(struct InterruptStackFrame *frame) {
    print_str("General protection fault\n");
    print_interrupt_frame(frame);
    while (1);
}

void page_fault_handler(struct InterruptStackFrame *frame) {
    print_str("Page fault\n");
    print_interrupt_frame(frame);
    while (1);
}
