#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s ./program\n", argv[0]);
        return 1;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    int status = system(argv[1]);

    gettimeofday(&end, NULL);

    long msec = (end.tv_sec - start.tv_sec) * 1000L
              + (end.tv_usec - start.tv_usec) / 1000L;

    printf("Time: %ld ms\n", msec);
    return status;
}
