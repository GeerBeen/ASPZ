#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    arr[100] = 42; // Запис за межами масиву
    printf("arr[100] = %d\n", arr[100]);
    return 0;
}