// create Condition Variable
int pthread_cond_init (
        pthread_cond_t *cond,        // Create Condition Variable
        pthread_condattr_t *attr );  // 建立的设定，可以给 NULL 就好

// wait some Condition Variable
int pthread_cond_wait (
        pthread_cond_t *cond,       // Wait Condition Variable
        pthread_mutex_t *mutex);    // Accompany wait 所使用的 mutex

// 通知一個wait的 thread
int pthread_cond_signal (
        pthread_cond_t *cond);

 // 通知所有wait的 threads
int pthread_cond_broadcast (
        pthread_cond_t *cond);

// release
// sucess : return 0
// failed : Error num > 0
int pthread_cond_destroy (pthread_cond_t *cond);

