#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

void *aa(void *arg)
{
    pid_t ppid=0;

    // Get parent pid
    ppid = getppid();
    printf(" %s is working \n",__func__);

    // aa finished, notice via signal
    kill (ppid, SIGUSR1);
}

int main() {
    pthread_t tid;  sigset_t set;
    int sig=0;

    // Init set (only wait SIGUSR1)
    sigemptyset (&set);
    sigaddset (&set, SIGUSR1);
    sigprocmask (SIG_SETMASK, &set, NULL);

    // Create thread aa
    pthread_create (&tid, NULL, aa, NULL);



    // Wait aa's signal terminate (SIGUSR1)
    sigwait (&set, &sig);
    // aa was already finished , continue ...
    // …
    printf(" %s is working \n",__func__);

    return 0;
}
