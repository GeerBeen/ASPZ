#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE 5*1024  

int get_file_size(const char *filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

int main() {
    const char *filename = "dice_results.txt";
    FILE *fp = fopen(filename, "a");

    srand(time(NULL)); 

    while (1) {
        if (get_file_size(filename) >= MAX_FILE_SIZE) {
            printf("File size limit. Exit\n");
            break;
        }

        int dice_roll = rand() % 6 + 1;
        fprintf(fp, "%d\n", dice_roll);
    }
    printf("Expected file size:%d\nReal file size:%d\n",MAX_FILE_SIZE, get_file_size(filename));
    fclose(fp);
    return 0;
}
