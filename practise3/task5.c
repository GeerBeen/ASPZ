#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

#define BUF_SIZE 512 

void handle_sigxfsz(int sig) {
    fprintf(stderr, "File size limit exceeded\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Program need two arguments\n");
        return 1;
    }


    signal(SIGXFSZ, handle_sigxfsz);

    int src = open(argv[1], O_RDONLY);
    if (src == -1) {
        fprintf(stderr, "Cannot open file %s for reading\n", argv[1]);
        return 1;
    }

    int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest == -1) {
        fprintf(stderr, "Cannot open file %s for writing\n", argv[2]);
        close(src);
        return 1;
    }

    char buffer[BUF_SIZE];
    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(src, buffer, BUF_SIZE)) > 0) {
        bytes_written = write(dest, buffer, bytes_read);
        if (bytes_written == -1) {
            perror("Write error");
            break;
        }
    }

    close(src);
    close(dest);
    return 0;
}
