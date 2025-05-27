#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int status;
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child (PID = %d) running...\n", getpid());
        sleep(2);
        exit(21);
    }

    pid_t ret = waitpid(pid, &status, WNOHANG);
    if (ret == 0) {
        printf("Parent: Child is still running (non-blocking wait).\n");
    } else if (ret > 0 && WIFEXITED(status)) {
        printf("Parent: Child exited with code %d.\n", WEXITSTATUS(status));
    }

    waitpid(pid, &status, 0);
    return 0;
}
