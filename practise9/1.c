#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define UID_THRESHOLD 1000

int main() {
    FILE *fp = popen("getent passwd", "r");
    if (fp == NULL) {
        perror("popen");
        return 1;
    }

    char line[1024];
    uid_t my_uid = getuid();

    while (fgets(line, sizeof(line), fp)) {
        char *username = strtok(line, ":");
        strtok(NULL, ":");
        char *uid_str = strtok(NULL, ":");
        if (username && uid_str) {
            int uid = atoi(uid_str);
            if (uid >= UID_THRESHOLD && uid != my_uid) {
                printf("User: %s UID=%d\n", username, uid);
            }
        }
    }

    pclose(fp);

    return 0;
}
