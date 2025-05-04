#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror(".");
        return 1;
    }

    struct dirent *entry;
    char answer[4];

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".c")) {
            printf("File: %s — Give permissions? (y/n): ", entry->d_name);
            fgets(answer, sizeof(answer), stdin);

            if (answer[0] == 'y' || answer[0] == 'Y') {
                if (chmod(entry->d_name, S_IROTH) == 0) {
                    printf("Succes: %s\n", entry->d_name);
                } else {
                    perror("Error");
                }
            }
        }
    }

    closedir(dir);
    return 0;
}
