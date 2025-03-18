#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#define SIZE_49 7 
#define SIZE_36 6  

void handle_cpu_limit(int sig) {
    printf("\nCPU time limit exceeded. Exit\n");
    exit(1);
}

void generate_unique_numbers(int *arr, int size, int max) {
    int used[max + 1];  
    
    long long waste_time = 0;
    for (long long i = 0; i < 1e9; i++) {
    waste_time += i;
    }

    for (int i = 0; i <= max; i++) used[i] = 0;

    for (int i = 0; i < size; i++) {
        int num;
        do {
            num = rand() % max + 1; 
        } while (used[num]); 

        arr[i] = num;
        used[num] = 1;
    }
}

int main() {
    signal(SIGXCPU, handle_cpu_limit);  
    srand(time(NULL)); 

    int numbers_49[SIZE_49];
    int numbers_36[SIZE_36];

    generate_unique_numbers(numbers_49, SIZE_49, 49);
    generate_unique_numbers(numbers_36, SIZE_36, 36);

    printf("Lottery numbers (7 from 49): ");
    for (int i = 0; i < SIZE_49; i++)
        printf("%d ", numbers_49[i]);

    printf("\nLottery numbers (6 from 36): ");
    for (int i = 0; i < SIZE_36; i++)
        printf("%d ", numbers_36[i]);

    printf("\n");
    return 0;
}
