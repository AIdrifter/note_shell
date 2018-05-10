# advanced multi process

## Preview Process and Thread concept
./vudu (binary)

vudu 1000(main thread)(process)
player 1001(player threads)

process : program stack, heap , virtual memory is indepdant
thread : global varuable can shread
cpu執行單位 : threads

## inter-process communication
1.pipe
    Usually use for parent process and child process
    only exist in kernel(OS)
    one write, one read => usually parent

2.name pipe

3.complex IP
    system V Message queue
    Dbus
    Unix socket

4.Shared memory
5.System V is not recommand
6.Binder IPC


## Thread commucation

1.global variables
    Threads are inside same process
    main thread create monitorThread to monitor sometings
    `this` is global variable to know which time terminate.
    => pthread_creat(&monitorThread,NULL,monitorThreadFun,this)

2.wait and signal

3.wait and signal with command


## Synchronization
1.Peterson's solution
2.Synchronization HardWare
3.mutex
    *lock/unlock
    *誰搶到誰先進去

    1.phread_spin_lock or other spin lock
    => 鎖死cpu 不建議 ??

```C
    /* spin lock */
    read()
    {
        pthread_mutex_lock(pmutex);
        reaebytes(A);
        pthread_mutex_unlock(pmutex);
    }

    write()
    {
        pthread_mutex_lock(pmutex);
        Writebytes(&A);
        pthread_mutex_unlock(pmutex);
    }

```

3.semaphore
    wait and post
    Semaphore with waiting queue
    can counting

4.common case
    Thread: pthread mutex lock
    Process: sempaphore
    =>mutex and semaphore don't occupy cpu resource via context switch out

5.
