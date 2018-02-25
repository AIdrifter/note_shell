# how to esitimate stack usage ?
We use -fstack-usage in gcc parameter

```bash
gcc -g -o0 -fstack-usage stack_usage.c
```

You will get stack_usage.su which record stack usage.
This behavior is belong to static analysis.
You don't need to do it on run time

```info
stack_usage.c:5:5:add2  16      static
stack_usage.c:10:5:add3 16      static
stack_usage.c:15:5:add3_local1  48      static
stack_usage.c:23:5:add3_local2  48      static
stack_usage.c:31:5:main 48      static
```

`stack_usage.c:31:5:main 48      static` the result we wante the result we wanted.



