#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void slow_function_simulation() {
    for (volatile int i = 0; i < 10000000; i++) {
        int a = 8 * 312;
        int b = a / 345;
        b++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <num of calls>\n", argv[0]);
        return 1;
    }

    int iterations = atoi(argv[1]);
    if (iterations <= 0) {
        printf("Error: %d\n", iterations);
        return 1;
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < iterations; i++) {
        slow_function_simulation();
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed = (end.tv_sec - start.tv_sec) +
                     (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Calls: %d\nSum time: %.6f sec\nAvg time: %.6f sec\n",
           iterations, elapsed, elapsed / iterations);

    return 0;
}
