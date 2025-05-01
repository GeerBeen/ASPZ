#include <stdio.h>

int arr[3] = {1,2,3};

int main() {
    printf("arr[1000] = %d\n", arr[1000]); // Читання за межами масиву
    return 0;
}