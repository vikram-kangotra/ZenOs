extern inline unsigned char inportb(int portnum) {
    unsigned char data;
    asm volatile("inb %1, %0" : "=a" (data) : "d" (portnum));
    return data;
}


extern inline void outportb(int portnum, unsigned char data) {
    asm volatile("outb %0, %1" : : "a" (data), "d" (portnum));
}
