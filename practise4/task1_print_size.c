#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
	size_t max_alloc = SIZE_MAX;
    printf("Size of size_t: %zu bytes\n", sizeof(max_alloc));
    printf("Max size_t: %zu \n",max_alloc);
    return 0;
}
