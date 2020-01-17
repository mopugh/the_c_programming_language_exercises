#include <stdio.h>

#define NUM_ALPHA 26
#define NUM_NUM 10

int main(int argc, char **argv) {
  int c, nt, nl, nw;
  c = nt = nl = nw = 0;

  int nalpha[NUM_ALPHA];
  int letters[NUM_ALPHA];
  int nnum[NUM_NUM];

  for (int i = 0; i < NUM_ALPHA; ++i) {
    nalpha[i] = 0;
    letters[i] = i + 'a';
  }

  for (int i = 0; i < NUM_NUM; ++i) {
    nnum[i] = 0;
  }

  while((c = getchar()) != EOF) {
    if (c == '\n') {
      ++nl;
    } else if (c == '\t') {
      ++nt;
    } else if (c == ' ') {
      ++nw;
    } else if (c >= '0' && c <= '9') {
      ++nnum[c-'0'];
    } else if (c >= 'a' && c <= 'z') {
      ++nalpha[c-'a'];
    } else if (c >= 'A' && c <= 'Z') {
      ++nalpha[c-'A'];
    }
  }

  for (int i = 0; i < NUM_ALPHA; ++i) {
    putchar(letters[i]);
    printf(":\t%d\n", nalpha[i]);
  }
  for (int i = 0; i < NUM_NUM; ++i) {
    printf("%d:\t%d\n", i, nnum[i]);
  }
  printf("\\t:\t%d\n", nt);
  printf("\\n:\t%d\n", nl);
  printf("SPACE:\t%d\n", nw);

  return 0;
}
