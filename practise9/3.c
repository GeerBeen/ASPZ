#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *filename = "/home/geerbeen/projects/practise9/3file";
    const char *copy = "/home/geerbeen/projects/practise9/3copy";

    // create
    printf("Creating %s \n", filename);
    FILE *f = fopen(filename, "w");
    if (!f) {
        perror("Fail");
        return 1;
    }
    fprintf(f, "Created\n");
    fclose(f);

    // copy
    printf("Copying to %s as root\n", copy);
    if (system("sudo cp /tmp/testfile /home/geerbeen/projects/practise9/3copy") != 0) {
        printf("Fail copy\n");
        return 1;
    }

    // mod
    printf("Modifying file\n");
    FILE *f2 = fopen(copy, "a");
    if (f2) {
        fclose(f2);
        printf("Modified\n");
    } else {
        perror("Fail mod");
    }

    // del copy
    printf("Deleting\n");
    int del = system("rm /home/geerbeen/projects/practise9/3copy");
    if (del != 0) {
        printf("Fail to delete \n");
    } else {
        if (access(copy, F_OK) == -1) {
            printf("Deleted\n");
        } else {
            printf("Fail del\n");
        }
    }

    return 0;
}
