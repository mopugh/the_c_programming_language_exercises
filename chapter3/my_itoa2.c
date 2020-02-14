/* Exercise 3.6 in K&R */
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void my_itoa(int n, char s[], int len);
void my_reverse(char s[]);

int main() {
    char s[MAXLINE+1];
    int x = -13;

    printf("Original x:\t%d\n", x);
    my_itoa(x,s,10);
    printf("Stringified x:\t%s\n", s);
}

void my_reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void my_itoa(int n, char s[], int len) {
    int i, sign;
    sign = n;

    i = 0;
    if (n > 0) {
        do {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0);
    } else {
        do {
            s[i++] = -(n % 10) + '0';
        } while ((n /= 10) < 0);
        s[i++] = '-';
    }

    while (i < len) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    my_reverse(s);
}
