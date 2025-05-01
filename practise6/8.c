#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int));
    *ptr = 42;
    free(ptr);
    *ptr = 100; // Запис після звільнення
    return 0;
}