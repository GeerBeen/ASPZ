#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Child %d (PID = %d) running...\n", i, getpid());
            sleep(1 + i);
            exit(10 + i);
        }
    }

    int status;
    pid_t pid;
    while ((pid = wait(&status)) > 0) {
        if (WIFEXITED(status)) {
            printf("Parent: Child %d exited with code %d.\n", pid, WEXITSTATUS(status));
        }
    }

    printf("All children are done.\n");
    return 0;
}
