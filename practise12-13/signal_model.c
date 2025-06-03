#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

#define NUM_WORKERS 5

pid_t workers[NUM_WORKERS];

void handle_done(int sig, siginfo_t *info, void *ucontext) {
    printf("Master: got end PID %d (result %d)\n", info->si_pid, info->si_value.sival_int);
}

void worker_handler(int sig, siginfo_t *info, void *ucontext) {
    int task = info->si_value.sival_int;
    printf("Worker %d: got job %d\n", getpid(), task);

    sleep(1);

    union sigval val;
    val.sival_int = task * 10; 
    sigqueue(getppid(), SIGUSR2, val);
}

int main() {
    struct sigaction sa_master = {0}, sa_worker = {0};

    sa_master.sa_sigaction = handle_done;
    sa_master.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sa_master, NULL);

    for (int i = 0; i < NUM_WORKERS; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            sa_worker.sa_sigaction = worker_handler;
            sa_worker.sa_flags = SA_SIGINFO;
            sigaction(SIGUSR1, &sa_worker, NULL);
            printf("Worker %d: started\n", getpid());
            while (1) pause();
        } else {
            workers[i] = pid;
        }
    }

    sleep(1); 

    for (int i = 0; i < NUM_WORKERS; ++i) {
        union sigval val;
        val.sival_int = i + 1;
        sigqueue(workers[i], SIGUSR1, val);
    }

    while (1) pause();
}
