/* Exercise 2.10 in K&R */
#include <stdio.h>

int my_lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

int main() {
    int c1 = 'K';
    int c2 = 'j';

    printf("c1 = %c, lower = %c\n", c1, my_lower(c1));
    printf("c2 = %c, lower = %c\n", c2, my_lower(c2));

    return 0;
}