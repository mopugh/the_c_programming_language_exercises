#include <stdio.h>
#define MAXLINE 1000

int getline1(char line[], int maxline);
int trim(char line[], int len);

int main(int argc, char **argv) {
  int len;
  char line[MAXLINE];
  
  while ((len = getline1(line, MAXLINE)) > 0) {
    /* printf("line length: %d\n", len); */
    len = trim(line, len);
    /* printf("trim length: %d\n", len); */
    if (line[0] != '\0') {
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

int trim(char s[], int l) {
  int i;
  for(i = l-1; i >= 0 && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '); --i) {
    ;
  }
  s[i+1] = '\0';
  return i+1;
}
