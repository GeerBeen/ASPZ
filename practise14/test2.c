#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t count = 0;
volatile sig_atomic_t keep_running_main_loop = 1;

void handler_slow(int sig, siginfo_t *si, void *uc) {
    count++;
    for (volatile int i = 0; i < 10000000; i++) { 
        int a = 8 * 312;
        int b = a / 345;
        b++;
    };
}

void handler_fast(int sig, siginfo_t *si, void *uc) {
    count++;
}

void main_loop_stopper(int sig) {
    keep_running_main_loop = 0;
}

int main() {
    struct sigaction sa_rt = {0};
    sa_rt.sa_flags = SA_SIGINFO;

    sa_rt.sa_sigaction = handler_fast;
    
    sigemptyset(&sa_rt.sa_mask);
    if (sigaction(SIGRTMIN, &sa_rt, NULL) == -1) {
        perror("sigaction SIGRTMIN");
        exit(EXIT_FAILURE);
    }

    struct sigaction sa_alarm = {0};
    sa_alarm.sa_handler = main_loop_stopper;
    sigemptyset(&sa_alarm.sa_mask);
    if (sigaction(SIGALRM, &sa_alarm, NULL) == -1) {
        perror("sigaction SIGALRM");
        exit(EXIT_FAILURE);
    }

    timer_t tid;
    struct sigevent sev = {0};
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    if (timer_create(CLOCK_MONOTONIC, &sev, &tid) == -1) {
        perror("timer_create");
        exit(EXIT_FAILURE);
    }

    struct itimerspec its;
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 100000; // 0.1 ms (10,000 сигналів/сек)
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 100000;

    if (timer_settime(tid, 0, &its, NULL) == -1) {
        perror("timer_settime SIGRTMIN");
        timer_delete(tid);
        exit(EXIT_FAILURE);
    }
	int seconds = 2;
    printf("Test running for %d seconds\n",seconds);
    printf("Using %s handler.\n", (sa_rt.sa_sigaction == handler_slow) ? "SLOW" : "FAST");
    alarm(seconds);

    while (keep_running_main_loop) {
        pause(); 
    }

    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;
    if (timer_settime(tid, 0, &its, NULL) == -1) {
        perror("Warning: timer_settime to disarm SIGRTMIN timer failed");
    }
    if (timer_delete(tid) == -1) {
         perror("Warning: timer_delete for SIGRTMIN timer failed");
    }

    printf("Signals handled: %ld\n", (long)count);

    long expected_signals_total = seconds * 10000;
    printf("Expected signals: %ld\n", expected_signals_total);
    

    return 0;
}
