#include "interrupts/exceptions.h"
#include "print.h"
#include "kernel/serial.h"

void print_interrupt_frame(struct InterruptStackFrame *frame) {
    kprintf("Interrupt frame at %x \n", (unsigned long)frame);
    kprintf("Instruction pointer: %x \n", frame->instruction_pointer);
    kprintf("Code segment: %x \n", frame->code_segment);
    kprintf("CPU flags: %x \n", frame->cpu_flags);
    kprintf("Stack pointer: %x \n", frame->stack_pointer);
    kprintf("Stack segment: %x", frame->stack_segment);
}

void error(const char* err) {
    kprintf(err);
    write_serial_string(err);
}

void divide_by_zero_handler(struct InterruptStackFrame *frame) {
    error("Divide by zero\n");
    print_interrupt_frame(frame);
    while (1);
}

void invalid_opcode_handler(struct InterruptStackFrame *frame) {
    error("Invalid opcode\n");
    print_interrupt_frame(frame);
    while (1);
}

void breakpoint_handler(struct InterruptStackFrame *frame) {
    error("Breakpoint\n");
    print_interrupt_frame(frame);
    while (1);
}

void double_fault_handler(struct InterruptStackFrame *frame) {
    error("Double fault\n");
    print_interrupt_frame(frame);
    while (1);
}

void general_protection_fault_handler(struct InterruptStackFrame *frame) {
    error("General protection fault\n");
    print_interrupt_frame(frame);
    while (1);
}

void page_fault_handler(struct InterruptStackFrame *frame) {
    error("Page fault\n");
    print_interrupt_frame(frame);

    unsigned long cr2;
    asm volatile("mov %%cr2, %0" : "=r"(cr2));

    write_serial_string("Page fault at address ");
    write_serial_hex(cr2);

    while (1);
}
