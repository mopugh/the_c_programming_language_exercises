#include <stdio.h>

#define IN  1
#define OUT 0

int main(int argc, char **argv) {
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if ((c == ' ' || c == '\n' || c == '\t' || c == '\n') && (state == IN)) {
      putchar('\n');
      state = OUT;
    }
    else if ((c != ' ') && (c != '\n') && (c != '\t')) {
      putchar(c);
      state = IN;
    }
  }

  return 0;
}
