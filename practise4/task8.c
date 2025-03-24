#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>

int main() {
    size_t mmap_threshold = 512 * 1024;
    if (mallopt(M_MMAP_THRESHOLD, mmap_threshold) == 0) {
        perror("mallopt failed");
        return 1;
    }

    printf("M_MMAP_THRESHOLD set to %zu bytes\n", mmap_threshold);

    size_t size = 600 * 1024; 
    void *ptr = malloc(size);
    if (!ptr) {
        perror("malloc failed");
        return 1;
    }

    printf("Allocated %zu bytes at %p\n", size, ptr);

    free(ptr);

    return 0;
}
