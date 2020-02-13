/* Exericse 3.1 in K&R */
#include <stdio.h>

int binsearch1(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main() {
    int x[5] = {0,1,2,3,4};

    for (int i = 0; i < 6; i++) {
        printf("Bin Search 1: %d is in position %d\n", i, binsearch1(i,x,5));
        printf("Bin search 2: %d is in position %d\n", i, binsearch2(i,x,5));
    }

    return 0;
}

int binsearch1(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        // printf("low: %d\tmid: %d\thigh: %d\n", low, mid, high);
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid+1;
    }

    if (v[mid] == x)
        return mid;
    else if (v[mid-1] == x && mid > 0)
        return mid - 1;
    else
        return -1;
}