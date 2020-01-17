#include <stdio.h>

#define MAXLINE 1000
#define TAB 3

int getline1(char line[], int maxline);
void entabline(char line[], char entabline[]);

int main(int argc, char **argv) {
    int len;
    char line[MAXLINE];
    char tabLine[MAXLINE];

    while ((len = getline1(line, MAXLINE)) > 0) {
        entabline(line, tabLine);
        printf("Original line:\t%s", line);
        printf("En-tabbed line:\t%s", tabLine);
    }
}

int getline1(char s[], int lim) {
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void entabline(char s[], char out[]) {
    int i, j, tc;
    tc = 0;
    j = 0;

    for(i = 0; s[i] != '\0'; ++i) {
        if (s[i] == ' ') {
            ++tc;
            if (tc == TAB) {
                j = j - TAB + 1;
                out[j] = '\t';
                tc = 0;
            } else {
                out[j] = s[i];
            }
        } else {
            out[j] = s[i];
            tc = 0;
        }
        ++j;
    }
    out[j] = '\0';
}