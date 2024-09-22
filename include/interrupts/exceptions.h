#pragma once

#include "idt.h"

void divide_by_zero_handler(struct InterruptStackFrame *frame);
void invalid_opcode_handler(struct InterruptStackFrame *frame);
void breakpoint_handler(struct InterruptStackFrame *frame);
void double_fault_handler(struct InterruptStackFrame *frame);
void general_protection_fault_handler(struct InterruptStackFrame *frame);
void page_fault_handler(struct InterruptStackFrame *frame);
