#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *filename = "/tmp/access_test_file";

    printf("Creating %s\n", filename);
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    write(fd, "Temporary file\n", 15);
    close(fd);
    printf("File created.\n");

    // chmod chown
    printf("Changing ownership\n");
    int chown_status = system("sudo chown root:wheel /tmp/access_test_file");
    int chmod_status = system("sudo chmod 600 /tmp/access_test_file");

    if (chown_status != 0 || chmod_status != 0) {
        printf("Failed to change ?\n");
        return 1;
    }

    printf("Permissions changed.\n");

    // try read
    printf("Open for reading.\n");
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open for reading");
    } else {
        printf("Read OK\n");
        close(fd);
    }

    // try write
    printf("Open for writing\n");
    fd = open(filename, O_WRONLY);
    if (fd == -1) {
        perror("open for writing");
    } else {
        printf("Write OK\n");
        close(fd);
    }

    return 0;
}
