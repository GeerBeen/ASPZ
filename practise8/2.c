#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.bin", 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    unsigned char data[10] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};
    write(fd, data, 10);

    lseek(fd, 0, SEEK_SET);

    lseek(fd, 3, SEEK_SET);

    unsigned char buffer[4];
    read(fd, buffer, 4);

    printf("Read: ");
    for (int i = 0; i < 4; ++i) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    close(fd);
    return 0;
}
