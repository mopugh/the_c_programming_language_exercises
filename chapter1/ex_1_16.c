#include <stdio.h>
#define MAXLINE 1000

int getline1(char line[], int maxline);
void copy(char to[], char from[]);

int main(int argc, char **argv) {
  int len;
  int max;
  int c;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getline1(line, MAXLINE)) > 0) {
    if (max == MAXLINE && (line[MAXLINE-1] != '\n' || line[MAXLINE-1] != EOF)) {
      while( (c = getchar()) != EOF || c != '\n') {
        ++len;
      } 
    }
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0){
    printf("Longest length: %d\n%s\n", max, longest);
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

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
