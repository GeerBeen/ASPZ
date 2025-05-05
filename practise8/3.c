#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void generate_sorted(int *arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = i;
}

void generate_reversed(int *arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = size - i;
}

void generate_identical(int *arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = 42;
}

void generate_random(int *arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100000;
}

void generate_alternating(int *arr, int n) {
    int low = 1;
    int high = n;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            arr[i] = low++;
        else
            arr[i] = high--;
    }
}

void run_test(void (*gen_func)(int *, int), const char *label) {
    int *arr = malloc(SIZE * sizeof(int));
    if (!arr) {
        perror("malloc");
        return;
    }

    gen_func(arr, SIZE);

    clock_t start = clock();
    qsort(arr, SIZE, sizeof(int), compare);
    clock_t end = clock();

    printf("%s: %lf sec\n", label, (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
}

int main() {
    srand(time(NULL));
    run_test(generate_sorted,   "Sorted");
    run_test(generate_reversed, "Reverse");
    run_test(generate_identical,"Identical");
    run_test(generate_random,   "Random");
    run_test(generate_alternating, "Altering");

    return 0;
}
