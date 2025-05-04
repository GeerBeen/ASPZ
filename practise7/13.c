#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

void check_executables(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    struct stat st;
    char fullpath[1024];

    printf("checking dir: %s\n", path);

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (stat(fullpath, &st) == -1) continue;

        if (S_ISREG(st.st_mode) && access(fullpath, X_OK) == 0) {
            if ((st.st_mode & 0777) == 0777) {
                printf("⚠ %s — executable file with suspicious permissions (777)\n", fullpath);
            } else {
                printf("- %s — executable file\n", fullpath);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s dir1 dirx\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        check_executables(argv[i]);
    }

    return 0;
}
