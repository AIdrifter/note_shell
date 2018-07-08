// Create one no-named Semaphore
// sucess: return 0
// failed: return -1
int sem_init (
        sem_t *sem,             // 要使用的 Semaphore
        int pshared,            // 0: 不能跨 proc 使用，非0: 可以跨 proc
        unsigned int value );   // 一開始的 resource count

// Create one named Semaphore
// sucess: return 0
// failed: return -1
sem_t sem_open (
        const char *name,       // 取名字，透過名字共用
        int oflag,              // O_CREAT，O_CREAT | O_EXCL
        mode_t mode,            // S_IRWXU，S_IRUSR…，S_IRWXG,  S_IWGRP…，S_IRWXO，S_IXOTH…
        unsigned int value );   //一開始的 resource count

int sem_post (sem_t *sem);     // increase resource. unlimited , never sleep
int sem_wait (sem_t *sem);     // decrease resource，sleep when  resource count = 0
int sem_trywait (sem_t *sem);  // decrease resource，Don't slee[

int sem_getvalue (sem_t *sem, int *sval); // 取得目前 count (放 sval)

int sem_close (sem_t *sem);     // close sem_t from sem_open()
int sem_destroy (sem_t *sem);   // destory sem_t from  sem_init()
int sem_unlink (sem_t *sem);    // release sem_t's resource from sem_open()


