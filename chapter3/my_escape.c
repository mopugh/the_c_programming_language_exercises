/* Exercise 3.2 in K&R */
#include <stdio.h>
#define MAXLINE 1000

void escape(const char s[], char t[]);

int main() {
    char copy[MAXLINE+1];
    const char line[] = "hello,\tworld!\nHello again!";

    printf("Original: %s\n", line);
    escape(line, copy);
    printf("Escaped Version: %s\n", copy);
}

void escape(const char s[], char t[]) {
    int i,j;

    for (i = j = 0; s[i] != '\0'; i++, j++) {
        switch (s[i]) {
            case '\t':
                t[j] = '\\';
                t[++j] = 't';
                break;
            case '\n':
                t[j] = '\\';
                t[++j] = 'n';
                break;
            default:
                t[j] = s[i];
                break;
        }
    }

    t[j] = '\0';
}