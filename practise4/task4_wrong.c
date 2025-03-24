#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = NULL;
    int i = 0, n = 16;

    while (i < 3) {
        if (!ptr){ 
            ptr = malloc(n);
            printf("Memory allocated\n");
            }
        
        printf("Iteration %d: ptr = %p\n", i, ptr);

        ((char *)ptr)[0] = 'A'; 

        free(ptr);
        i++;
    }

    return 0;
}
