/* Exercise 2.8 in K&R */
#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main() {
    unsigned int x = 15;
    int n = 2;

    printf("Size of unsigned int:\t%lu\n", sizeof(unsigned int));
    printf("Original:\t%u\n", x);
    printf("Rotated:\t%u\n", rightrot(x,n));

    return 0;
}

unsigned int rightrot(unsigned int x, int n) {
    unsigned int first_n;
    unsigned int mask = ((1 << (n+1))-1);
    
    first_n = x & mask;
    first_n = first_n << (8*sizeof(unsigned int) - n);
    x = x >> n;
    x = first_n | x;

    return x;
}