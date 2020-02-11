/* Exercise 2.6 in K&R */
#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(int argc, char **argv) {
    int x = 15;
    int y = 6;
    int p = 2;
    int n = 2;

    printf("bits set:\t%u\n", setbits(x,p,n,y));
}

int setbits(int x, int p, int n, int y) {
    unsigned int left_mask = (~0) << (p+1);
    // printf("Left mask:\t%u\n", left_mask);
    unsigned int right_mask = ((1 << (p-n+1)) - 1);
    // printf("Right mask:\t%u\n", right_mask);

    unsigned int mask = left_mask | right_mask;
    // printf("x original:\t%u\n", x);
    x = x & mask;
    // printf("mask:\t%u\n", mask);
    // printf("x mask:\t%u\n", x);

    unsigned int y_mask = ((1 << n) - 1);
    // printf("y mask:\t%u\n", y_mask);
    // printf("y:\t%u\n", y);
    y = y & y_mask;
    // printf("y masked:\t%u\n", y);
    y = y << (p-n+1);
    // printf("y masked and shifted:\t%u\n", y);

    return (x | y);
}