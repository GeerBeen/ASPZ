#include <stdlib.h>

int *ptr;

int main() {
    ptr = malloc(100 * sizeof(int)); // виділення пам'яті
    ptr[0] = 42;                          // використання
    return 0; // Немає free(ptr)
}
