#include <stdio.h>
#include <stdlib.h>

int main() {
    int negative_size = -100; 
    size_t converted_size = (size_t)negative_size; 

    printf("Before: %d\n", negative_size);
    printf("After: %zu\n", converted_size);

    void *ptr = malloc(negative_size); 
    if (ptr) {
        printf("malloc yes\n");
        free(ptr);
    } else {
        printf("malloc failed\n");
    }

    return 0;
}
