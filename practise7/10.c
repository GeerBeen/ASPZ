#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));

    float r1 = (float)rand() / RAND_MAX; 
    printf("Random number in [0.0, 1.0]: %f\n", r1);

    if (argc >= 2) {
        float n = atof(argv[1]);  
        float r2 = r1 * n;
        printf("Random number in [0.0, %.2f]: %f\n", n, r2);
    } else {
        printf("To random in  [0.0, n], pass n as arg.\n");
    }

    return 0;
}
