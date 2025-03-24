#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int main() {
    int xa = INT_MAX;
    int xb = 2;  
    int num = xa * xb;

    printf("xa: %d, xb: %d, num: %d\n", xa, xb, num);

    void *ptr = malloc(num);
    if (ptr) {
        printf("malloc yes\n");
        free(ptr);
    } else {
        printf("malloc failed\n");
    }

    return 0;
}
