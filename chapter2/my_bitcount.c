/* Exercise 2.9 in K&R */
#include <stdio.h>

int bitcount1(unsigned x) {
    int b;

    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) {
            b++;
        }
    }

    return b;
}

int bitcount2(unsigned x) {
    int b;

    for(b = 0; x != 0; b++,x &= x-1)
        ;

    return b;
}

int main() {
    unsigned x = 13;
    printf("bitcount1:\tx = %u has %d bits\n", x, bitcount1(x));
    printf("bitcount2:\tx = %u has %d bits\n", x, bitcount2(x));
    return 0;
}