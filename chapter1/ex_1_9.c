#include <stdio.h>

int main(int argc, char **argv) {
  int c, blank_flag;
  blank_flag = 0;

  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
      blank_flag = 0;
    }
    if (c == ' ' && blank_flag == 0) {
      putchar(c);
      blank_flag = 1;
    }
  }

  return 0;
}
