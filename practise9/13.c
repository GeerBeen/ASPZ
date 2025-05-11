#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("What a fool hahahahahah\n");

    FILE *f = fopen("/home/geerbeen/projects/practise9/spyinfo.txt", "a");
    if (f) {
        fprintf(f, "ls run by user: %s\n", getenv("USER"));
        fclose(f);
    }

    return 0;
}
