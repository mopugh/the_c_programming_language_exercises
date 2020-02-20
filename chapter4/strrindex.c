#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould"; /*pattern to search for */

/* find all lines matching pattern */
int
main()
{
    char line[MAXLINE];
    int found = 0;
    int index, rindex;

    while (my_getline(line, MAXLINE) > 0) {
        index = strindex(line, pattern);
        rindex = strrindex(line, pattern);
        printf("Left index:%d\tRight index:%d\n", index, rindex);
        if (index >= 0) {
            printf("Position %d:\t%s\n", index, line);
            found++;
        }
    }
    return found;
}

/* my_getline: get line into s, return length */
int my_getline(char s[], int lim)
{
    int c,i;

    i = 0;
    while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* strrindex: return the rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k;

    for (i = strlen(s)-1; i >= 0; i--) {
        for (j=i, k=strlen(t)-1; j >= 0 && k >= 0 && s[j] == t[k]; j--, k--)
            ;
        if (k == -1)
            return ++j;
    }
    return -1;
}
