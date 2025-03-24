#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = malloc(16);
    if (!ptr) {
        perror("malloc failed");
        return 1;
    }
    printf("First allocation: %p\n", ptr);

    
    void *new_ptr = realloc(NULL, 32);
    if (new_ptr) {
        printf("realloc(NULL, 32): %p\n", new_ptr);
        free(new_ptr);
    } else {
        printf("realloc(NULL, 32) failed\n");
    }

    new_ptr = realloc(ptr, 0);
    if (new_ptr == NULL) {
        printf("realloc(ptr, 0): returned NULL (memory freed)\n");
        free(new_ptr);
    } else {
        printf("realloc(ptr, 0): returned %p\n", new_ptr);
        free(new_ptr);
    }

    return 0;
}
