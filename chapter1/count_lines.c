#include <stdio.h>

int main(int argc, char **argv) {
  int c, nl, nt, nb;

  nl = 0;
  nt = 0;
  nb = 0;
  while ((c = getchar()) != EOF){
    if (c == '\n') {
      ++nl;
    } else if (c == '\t') {
      ++nt;
    } else if (c == ' ') {
      ++nb;
    }
  }
  printf("Number of new lines: %d\n", nl);
  printf("Number of tabs: %d\n", nt);
  printf("Number of blanks: %d\n", nb);

  return 0;
}
