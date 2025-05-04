#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror(".");
        return 1;
    }

    struct dirent *entry;
    char *names[MAX];
    int count = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR &&
            strcmp(entry->d_name, ".") != 0 &&
            strcmp(entry->d_name, "..") != 0) {

            names[count] = strdup(entry->d_name);
            count++;
        }
    }

    closedir(dir);

    qsort(names, count, sizeof(char *), (int(*)(const void*, const void*)) strcmp);

    for (int i = 0; i < count; i++) {
        printf("%s/\n", names[i]);
        free(names[i]);
    }

    return 0;
}
