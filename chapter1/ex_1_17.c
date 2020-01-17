#include <stdio.h>
#define MAXLINE 1000

int getline1(char line[], int maxline);
void copy(char to[], char from[]);

int main(int argc, char **argv) {
  int len;
  int max;
  char line[MAXLINE];

  max = 0;
  while ((len = getline1(line, MAXLINE)) > 0) {
    if (len > 80) {
      printf("%s\n", line);
    }
  }
  return 0;
}

int getline1(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
