#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd = open("nonexistent.txt", O_WRONLY);
    if (fd == -1) {
        perror("open");
    }

    const char *msg = "Hello!";
    ssize_t count = write(fd, msg, 6);
    
    if (count == -1) {
        perror("write");
    } else {
        printf("Wrote %zd bytes\n", count);
    }
	printf("write() return value = %ld\n",count);
    return 0;
}
