#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    printf("arr[10] = %d\n", arr[10]); // Читання за межами виділеної пам’яті
    free(arr);
    return 0;
}