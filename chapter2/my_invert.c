/* Exercise 2.7 in K&R */
#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main() {
    unsigned int x = 13;
    int p = 2;
    int n = 2;

    printf("original:\t%u\n", x);
    printf("inverted:\t%u\n", invert(x,p,n));

    return 0;
}

unsigned int invert(unsigned int x, int p, int n) {
    unsigned int left_mask = (~0) << (p+1);
    unsigned int right_mask = ((1 << (p-n+1))-1);
    unsigned int outer_mask = left_mask | right_mask;
    unsigned int inner_mask = ~outer_mask;
    unsigned int temp_x = x;

    temp_x = temp_x & inner_mask;
    // printf("Inner bits:\t%u\n", temp_x);
    // Need to & with inner_mask again due to ~temp_x
    temp_x = ~temp_x & inner_mask;
    // printf("Inverted inner bits:\t%u\n", temp_x);
    x = x & outer_mask;
    // printf("Outer mask:\t%u\n", x);
    return (x | temp_x);
}