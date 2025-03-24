#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    size_t max_alloc = SIZE_MAX;
    printf("Allocating %zu bytes\n", max_alloc);

    void *ptr = malloc(max_alloc);
    if (ptr) {
        printf("Allocation yes\n");
        free(ptr);
    } else {
        printf("Allocation failed\n");
    }

    return 0;
}
