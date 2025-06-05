#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t count = 0;

void handler(int sig, siginfo_t *si, void *uc) {
    count++;
}

int main() {
    struct sigaction sa = {0};
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigaction(SIGRTMIN, &sa, NULL);

    timer_t tid;
    struct sigevent sev = {0};
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    timer_create(CLOCK_MONOTONIC, &sev, &tid);

    struct itimerspec its;
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 1000000;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 1000000;

    timer_settime(tid, 0, &its, NULL);

    time_t start = time(NULL);
    while (time(NULL) - start < 2);

    printf("Signals handled: %d\n", count);
}
