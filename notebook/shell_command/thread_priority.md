# Thread priority

http://man7.org/linux/man-pages/man3/pthread_setschedparam.3.html

```C
struct sched_param tTargetParam = m_tBackupParam;

    tTargetParam.sched_priority = tPriority;
    if(0 != pthread_setschedparam(pthread_self(), tPolicy, &tTargetParam))
    {
        printf("error while setting thread tPolicy : %u, priority to %d",tPolicy, tPriority);
    }
    printf("setting thread tPolicy : %u, priority to %d success!!!",tPolicy, tPriority);
```

- 請直接在function entry做這個調整, 調整成`FIFO 90+`
- 另外加個static變數儲存 thread id
- 相同的thread就不用重複設定了

```info
int tPolicy = SCHED_FIFO;
int tPriority = 90;
```


