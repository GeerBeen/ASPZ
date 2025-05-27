#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int status;
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child (PID = %d) running...\n", getpid());
        sleep(1);
        exit(13);
    }

    pid_t ret = waitpid(-1, &status, 0);
    if (ret > 0 && WIFEXITED(status)) {
        printf("Parent: Child %d exited with code %d (.\n", ret, WEXITSTATUS(status));
    }

    return 0;
}
