#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    arr[10] = 42;
    printf("arr[10] = %d\n", arr[10]);
    free(arr);
    return 0;
}