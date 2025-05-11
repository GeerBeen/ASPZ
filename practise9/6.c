#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *dirs[] = { "/home/geerbeen", "/usr/bin", "/etc" };
    for (int i = 0; i < 3; ++i) {
        printf("Listing files in: %s\n", dirs[i]);
        char command[256];
        snprintf(command, sizeof(command), "ls -l %s", dirs[i]);
        system(command);
        printf("\n");
    }

    const char *test_files[] = { "/home/geerbeen/.profile", "/usr/bin/ls", "/etc/passwd" };
    for (int i = 0; i < 3; ++i) {
        printf("Checking file: %s\n", test_files[i]);
        if (access(test_files[i], R_OK) == 0)
            printf("  Read access: OK\n");
        else
            printf("  Read access: DENIED\n");

        if (access(test_files[i], W_OK) == 0)
            printf("  Write access: OK\n");
        else
            printf("  Write access: DENIED\n");

        if (access(test_files[i], X_OK) == 0)
            printf("  Execute access: OK\n");
        else
            printf("  Execute access: DENIED\n");

        printf("\n");
    }

    return 0;
}
