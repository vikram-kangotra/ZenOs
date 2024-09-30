#pragma once

int init_serial();
void write_serial_char(char a);
void write_serial_string(const char* a);
void write_serial_hex(unsigned long hex);
