#include <stdio.h>
#include <stdlib.h>

int global_initialized_var = 10; //  should go to data
int global_uninitialized_var; //  should go to bss

void stack_growth_test() {
	// both should go to stack
    int large_array1[1000];
    int large_array2[1000] = {0}; 

    // fill so compiler not delete
    for (int i = 0; i < 1000; i++) {
        large_array1[i] = i;
        large_array2[i] = i * 2;
    }

    int local_int_in_function; // should be nearer to stack top
    printf("Stack top inside function is near %p\n", &local_int_in_function);
     printf("large_array1 inside function is near %p\n", &large_array1);
      printf("large_array2 inside function is near %p\n", &large_array2);
}

int main() {
    int local_var_in_main;
    printf("Stack top in main is near %p\n", &local_var_in_main);

    printf("Address of global_initialized_var in data: %p\n", &global_initialized_var);
    printf("Address of global_uninitialized_var in bss: %p\n", &global_uninitialized_var);

    // function main adress should be in text
    printf("Address of main function in text: %p\n", main);

    // for heap adress using malloc
    int *heap_var = (int *)malloc(sizeof(int));
    if (heap_var == NULL) {
        fprintf(stderr, "Failed to allocate memory on the heap.\n");
        return 1;
    }
    printf("Address of heap_var in heap: %p\n", heap_var);

    stack_growth_test();

    return 0;
}
