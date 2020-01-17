#include <stdio.h>

#define IN  1
#define OUT 0
#define MAX_CHAR 20

int main(int argc, char **argv) {
  int c, cc, state;
  int nchar[MAX_CHAR];

  for (int i = 0; i < MAX_CHAR; ++i) {
    nchar[i] = 0;
  }

  c = cc = 0;
  state = OUT;

  while((c = getchar()) != EOF) {
    if ((c == ' ' || c == '\t' || c == '\n') && (state == IN)) {
      state = OUT;
      if (cc >= MAX_CHAR) {
        nchar[MAX_CHAR-1] += 1;
      } else {
        nchar[cc-1] += 1;
      }
      cc = 0;
    } else if (c != ' ' && c != '\t' && c != '\n') {
      state = IN;
      ++cc;
    }
  }

  for (int i = 0; i < MAX_CHAR; ++i) {
    printf("%d characters:\t%d\n", i+1, nchar[i]);
  }

  return 0;
}
