#include <stdio.h>

#define MAX_LINE 1024
#define PAGE_SIZE 20

void show_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror(filename);
        return;
    }

    char line[MAX_LINE];
    int count = 0;

    while (fgets(line, MAX_LINE, file)) {
        printf("%s", line);
        count++;

        if (count >= PAGE_SIZE) {
            printf("---- More ----");
            getchar();  
            count = 0;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file> [file2] ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        printf("\n==== %s ====\n", argv[i]);
        show_file(argv[i]);
    }

    return 0;
}
