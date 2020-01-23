/* Exercise 2.4 in K&R */
#include <stdio.h>

void mySqueeze(char s1[], const char s2[]) {
    int i,j, k;
    for(i = 0; s2[i] != '\0'; i++) {
        for(j = k = 0; s1[j] != '\0'; j++) {
            if(s1[j] != s2[i]) {
                s1[k++] = s1[j];
            }
        }
        s1[k] = '\0';
    }
}

int main(int argc, char **argv) {
    char s1[] = "Hello world!";
    char s2[] = "eop";

    mySqueeze(s1, s2);

    printf("Squeezed: %s\n", s1);

    return 0;
}