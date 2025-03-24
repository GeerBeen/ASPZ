#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = malloc(0); 
    if (ptr) {
        printf("malloc(0) returned: %p\n", ptr);
    } else {
        printf("malloc(0) returnd NULL\n");
    }

    free(ptr); 
    printf("free(ptr) is ok\n");

    return 0;
}
