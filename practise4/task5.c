#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 1024 * 1024 * 1024; 
    size_t multiplier = 1024 * 100; // straight to 100 TB
    void *ptr = malloc(1024);

    if (!ptr) {
        perror("malloc failed");
        return 1;
    }

    printf("Memory allocated 1kb: %p\n", ptr);

    
    void *new_ptr = realloc(ptr, size * multiplier); 

    if (!new_ptr) {
        perror("realloc failed with 100tb");
        printf("Old pointer is still valid: %p\n", ptr);
        free(ptr);
    } else {
        printf("Memory successfully reallocated: %p\n", new_ptr);
        free(new_ptr);
    }

    return 0;
}
