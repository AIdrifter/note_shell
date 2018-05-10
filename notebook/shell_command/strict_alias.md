# strict alias
http://blog.csdn.net/dbzhang800/article/details/6720141

```C
#include <stdio.h>

int a;
int f(float *b)
{
    a = 1;
    *b = 0;
    return a;
}
```

```C
int main()
{
    printf("%d\n", f((float*)&a));
    return 0;
}
```


用GCC4.4 加 -O3 编译(GCC4.5似乎看不到这个效果，fixme)：

debao@ubuntu:~/ttt$ gcc-4.4 -Wall -O3 hello.c

```bash
hello.c: In function ‘main’:
hello.c:7: warning: dereferencing pointer ‘a.16’ does break strict-aliasing rules
hello.c:13: note: initialized from here
```
