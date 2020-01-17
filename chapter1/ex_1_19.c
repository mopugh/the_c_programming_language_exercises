#include <stdio.h>
#define MAXLINE 1000

int getline1(char line[], int maxline);
void reverse1(char line[], char rev[], int len);

int main(int argc, char **argv) {
  int len;
  char rev[MAXLINE];
  char line[MAXLINE];
  
  while ((len = getline1(line, MAXLINE)) > 0) {
    reverse1(line, rev, len);
    printf("Original:\t%s\nReversed:\t%s\n", line, rev);
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

void reverse1(char s[], char rev[], int l) {
  int j = 0;
  for (int i = l-1; i >= 0; --i) {
    rev[j] = s[i];
    j++;
  }
  rev[j+1] = '\0';
}
