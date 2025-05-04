#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &file_stat) == 0) {
            if (access(entry->d_name, R_OK) == 0) printf("r ");
            if (access(entry->d_name, W_OK) == 0) printf("w ");

            printf("%ld %s\n", (long)file_stat.st_size, entry->d_name);
        }
    }

    closedir(dir);
    return 0;
}
