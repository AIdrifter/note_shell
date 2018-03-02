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

`stack_usage.c:31:5:main 48      static` the result we wanted.


# avstack.pl
1.you must ensure that your object files are compiled with -fstack-usage
2.replace avr-objdump accronding to your toolchain

```info
Cost: peak stack usage during a call to the function.
Frame: stack frame size, obtained from the .su file, plus the call-cost constant.
Height: height in call graph -- calculated as maximum height of any callee, plus one.
```

## reference
https://dlbeer.co.nz/oss/avstack.html




