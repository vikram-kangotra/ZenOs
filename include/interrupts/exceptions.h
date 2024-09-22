#pragma once

#include "idt.h"

void divide_by_zero(struct InterruptStackFrame *frame);
void invalid_opcode(struct InterruptStackFrame *frame);
void double_fault(struct InterruptStackFrame *frame);
