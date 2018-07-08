// clear set
int sigemptyset (sigset_t *set)

// add one signal to set group
int sigaddset (
            sigset_t *set,   // signal set
            int signum);     // 要加入的 signal number

// delete one signal form signal set
int sigdelset (
        sigset_t *set,      // signal set
        int signum);        // delete signal number

// set waitting singnals
int sigprocmask (
        int how,                 // wait way : SIG_BLOCK, SIG_UNBLOCK, SIG_SETMASK
        const sigset_t *set,     // 打算等待的哪些 signals (signal set)
        sigset_t *oldset);       // 返回原本的 set，可以是 NULL

int sigwait (*set, int* sig);   // wait set 裡面的all signal(s)

// notice some process ->  signum has already happened
int kill (pid, signum);

