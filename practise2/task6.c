#include <stdio.h>

static inline int add(int a, int b) {
    return a + b;
}


int process_data(int *data, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] > 0) {
            sum = add(sum, data[i]);
        }
    }
    return sum;
}

int trashFunc(){
    int x = 8;
    x = 7;
    return x;
}

int main() {
    int my_data[] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10};
    int size = sizeof(my_data) / sizeof(my_data[0]);
    int result = process_data(my_data, size);

    if (result > 100){
        printf("Result: %d\n", result);
    }

    return 0;
}
