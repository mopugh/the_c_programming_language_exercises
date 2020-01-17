#include <stdio.h>

#define TAB 4

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c != '\t') {
      putchar(c);
    } else {
      for (int i = 0; i < TAB; ++i) {
        putchar(' ');
      }
    }
  }

  return 0;
}
