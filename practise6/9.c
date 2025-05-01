#include <stdio.h>

int* get_local() {
    int x = 42;
    return &x; 
}

int main() {
    int *ptr = get_local();
    printf("Value: %d\n", *ptr); 
    return 0;
}