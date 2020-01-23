/* Exercise 2.3 in K&R */

#include <stdio.h>

int my_htoi(const char h[]) {
    int intVal = 0;
    int i, c;

    for(i = 0; h[i] != '\0'; ++i) {
        c = h[i];

        if(c >= '0' && c <= '9') {
            intVal = 16 * intVal + (c - '0');
        } else if(c >= 'a' && c <= 'f') {
            intVal = 16 * intVal + (c - 'a' + 10);
        } else if(c >= 'A' && c <= 'F') {
            intVal = 16 * intVal + (c - 'A' + 10);
        } else if(c == 'x' || c == 'X') {
            intVal = 0;
        } 
    }

    return intVal;
}

int main(int argc, char **argv) {
    char hexString[] = "0xa9";
    printf("%s is %d\n", hexString, my_htoi(hexString));

    return 0;
}