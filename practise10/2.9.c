#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    int status;

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        printf("Child process (PID %d)\n", getpid());
        exit(42);
    } else {
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child exited with code %d\n", WEXITSTATUS(status));
        } else {
            printf("Child did not exit normally\n");
        }
    }

    return 0;
}
