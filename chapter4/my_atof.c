#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int my_getline(char s[], int lim);
double my_atof(char s[]);

int main () {
    double sum;
    char line[MAXLINE];
    
    sum = 0;
    while (my_getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += my_atof(line));
    return 0;
}

int my_getline(char s[], int lim)
{
    int c,i;

    i = 0;
    while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

double my_atof(char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++) // Skip whitespace
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}