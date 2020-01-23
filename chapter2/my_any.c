/* Exercise 2.5 in K&R */
#include <stdio.h>

int myAny(const char s1[], const char s2[]) {
    int i, j;

    for(i = 0; s1[i] != '\0'; ++i) {
        for(j = 0; s2[j] != '\0'; ++j) {
            if(s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return -1;
}

int main(int argc, char **argv) {
    char s1[] = "Hello World!";
    char s2[] = "aeiou";
    char s3[] = "qz";

    printf("First occurrence of %s in %s: %d\n", s2, s1, myAny(s1,s2));
    printf("First occurrence of %s in %s: %d\n", s3, s1, myAny(s1,s3));

    return 0;
}