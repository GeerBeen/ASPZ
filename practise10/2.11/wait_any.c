#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        sleep(1);
        exit(42);
    }

    int status;
    wait(NULL); 
    printf("Child exited (wait)\n");
    return 0;
}
