#include <stdio.h>
#include <dirent.h>
#include <string.h>

void list(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror(path);
        return;
    }

    struct dirent *entry;
    char subpath[1024];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        printf("%s/%s\n", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            snprintf(subpath, sizeof(subpath), "%s/%s", path, entry->d_name);
            list(subpath);
        }
    }

    closedir(dir);
}

int main() {
    list(".");
    return 0;
}

