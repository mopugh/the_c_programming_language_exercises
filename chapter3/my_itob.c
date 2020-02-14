/* Exercise 3.5 in K&R */
/* Assuming positive numbers */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void my_itob(int n, char s[], int b);
void my_reverse(char s[]);

int main() {
    int x = 21;
    char s[MAXLINE+1];

    printf("Original x:\t%d\n", x);
    my_itob(x, s, 2);
    printf("Binary x:\t%s\n", s);
    my_itob(x, s, 16);
    printf("Base 16 x:\t%s\n", s);

}

void my_reverse(char s[]) {
    int i, j, c;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// Assuming n is positive
void my_itob(int n, char s[], int b) {
    int i;

    i = 0;
    do {
        s[i++] = (n % b) + '0';
    } while ((n /= b) > 0);
    s[i] = '\0';
    my_reverse(s);
}