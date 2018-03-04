# Basic concept
## How to get your assembly language
- [ ] [godbolt]
(http://gcc.godbolt.org/): See assembly language in website

## Memory Layout
<img style="display:block; margin:auto;" src="https://pinglinblog.files.wordpress.com/2016/10/e89ea2e5b995e5bfabe785a7-2016-10-18-e4b88be58d889-22-19.png?w=560"></img>

- text segment
```C
int main(){};
```

- initalized data segment
All of global and static varaiable have initailzed value.

- uninitalized data segment
uninitialized global varibale is stored in uninitialized data segment(bss segment: block started by symbol)
  program loader initialize memory to zero when run time
```C
static char mbuf[10240000]={0};  \\ 8.7K
static char mbuf[10240000];      \\ 8.7K
static char mbuf[10240000]={1};  \\ 9.8M
```

- stack segment
1.stack frame
2.local variable in function
3.parameter
4.argument
5.return address

- heap segment
C   : malloc
C++ : new
program break can be setted via brk() and sbrk()


- TLP sample code
```C
#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* Uninitialized data segment */
int primes[] = { 2, 3, 5, 7 };  /* Initialized data segment */

static int
square(int x)                   /* Allocated in frame for square() */
{
    int result;                 /* Allocated in frame for square() */

    result = x * x;
    return result;              /* Return value passed via register */
}

static void
doCalc(int val)                 /* Allocated in frame for doCalc() */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* Allocated in frame for doCalc() */

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char *argv[])    /* Allocated in frame for main() */
{
    static int key = 9973;      /* Initialized data segment */
    static char mbuf[10240000]; /* Uninitialized data segment */
    char *p;                    /* Allocated in frame for main() */

    p = malloc(1024);           /* Points to memory in heap segment */

    doCalc(key);

    exit(EXIT_SUCCESS);
}


```

## How does funtion work ?

register
* ebp:     frame pointer(base pointer)
* esp:     stack pointer
* eax:     accumulator => add and mul operation
* ebx:     base memory address
* ecx:     couter => work for REP and LOOP
* esi/edi: source/destination index  => for string operation
* leave:
* ret:

instruction
* mov ：資料傳送指令，也是最基本的程式設計指令，用於將一個數據從源地址傳送到目標地址（暫存器間的資料傳送本質上也是一樣的）
* sub：減法指令
* lea：取偏移地址
* push：實現壓入操作的指令是PUSH指令
* pop：實現彈出操作的指令
* call：用於儲存當前指令的下一條指令並跳轉到目標函式


```C
#include <stdio.h>

int main() {
    int x = 1;
    int y;
    y = f1(x);
    printf("y=%d\n", y);
    return 1;
}
int f1(int t) {
    int b = f2(&t);
    return b+b;
}
int f2(int *p) {
    int r= *p+5;
    return r;
}
```

```C
File:ch03/f2.s                                               ; File:ch03/f2.c
        .file    "f2.c"                                      ; #include <stdio.h>
    .def    ___main;    .scl    2;    .type    32;    .endef ;
    .section .rdata,"dr"                                     ;
LC0:                                                         ;
    .ascii "y=%d\12\0"                                       ;
    .text                                                    ;
.globl _main                                                 ;
    .def    _main;    .scl    2;    .type    32;    .endef   ;
_main:                                                       ; int main() {
    pushl    %ebp                                            ; // 保存框架指標
    movl    %esp, %ebp                                       ; // 設定堆疊指標
    subl    $24, %esp                                        ; // 分配區域變數空間
    andl    $-16, %esp                                       ;
    movl    $0, %eax                                         ;
    addl    $15, %eax                                        ;
    addl    $15, %eax                                        ;
    shrl    $4, %eax                                         ;
    sall    $4, %eax                                         ;
    movl    %eax, -12(%ebp)                                  ;
    movl    -12(%ebp), %eax                                  ;
    call    __alloca                                         ; // 分配堆積(heap)空間
    call    ___main                                          ;
    movl    $1, -4(%ebp)                                     ;     int x = 1;
    movl    -4(%ebp), %eax                                   ;     int y;
    movl    %eax, (%esp)                                     ;
    call    _f1                                              ;     y = f1(x);
    movl    %eax, -8(%ebp)                                   ; // y = eax
    movl    -8(%ebp), %eax                                   ; // eax = y
    movl    %eax, 4(%esp)                                    ; // 參數 y (推入堆疊)
    movl    $LC0, (%esp)                                     ; // 參數 "y=%d\n"
    call    _printf                                          ;     printf("y=%d\n", y);
    movl    $1, %eax                                         ; // 設定傳回值 eax=1
    leave                                                    ;
    ret                                                      ;     return 1;
.globl _f1                                                   ; }
    .def    _f1;    .scl    2;    .type    32;    .endef     ;
_f1:                                                         ; int f1(int t) {
    pushl    %ebp                                            ; // 保存框架指標
    movl    %esp, %ebp                                       ; // 設定堆疊指標
    subl    $8, %esp                                         ; // 分配區域變數空間
    leal    8(%ebp), %eax                                    ; // eax = 8(%ebp) 的位址
    movl    %eax, (%esp)                                     ; // esp 上移 8 byte
    call    _f2                                              ;     int b = f2(&t);
    movl    %eax, -4(%ebp)                                   ; // -4(%ebp) 就是 b
    movl    -4(%ebp), %eax                                   ; // eax = b
    addl    -4(%ebp), %eax                                   ; // eax = eax + b
    leave                                                    ;
    ret                                                      ;     return b+b;
.globl _f2                                                   ; }
    .def    _f2;    .scl    2;    .type    32;    .endef     ;
_f2:                                                         ; int f2(int *p) {
    pushl    %ebp                                            ; // 保存框架指標
    movl    %esp, %ebp                                       ; // 設定堆疊指標
    subl    $4, %esp                                         ; // 分配區域變數空間
    movl    8(%ebp), %eax                                    ;
    movl    (%eax), %eax                                     ;
    addl    $5, %eax                                         ;     int r= *p+5;
    movl    %eax, -4(%ebp)                                   ; // 設定傳回值 eax=r
    movl    -4(%ebp), %eax                                   ;
    leave                                                    ;
    ret                                                      ;     return r;
    .def    _f2;    .scl    3;    .type    32;    .endef     ; }
    .def    _printf;    .scl    3;    .type    32;    .endef ;
    .def    _f1;    .scl    3;    .type    32;    .endef     ;

```


## How to esitimate stack usage ?
- linux run time
```bash
$ sudo cat /proc/1/maps | grep stack
7fff7e13f000-7fff7e160000 rw-p 00000000 00:00 0 [stack]
```
- static analysis
We use -fstack-usage in gcc parameter

```bash
gcc -g -o0 -fstack-usage stack_usage.c
```

You will get stack_usage.su which record stack usage.
This behavior belongs to static analysis.

```info
stack_usage.c:5:5:add2  16      static
stack_usage.c:10:5:add3 16      static
stack_usage.c:15:5:add3_local1  48      static
stack_usage.c:23:5:add3_local2  48      static
stack_usage.c:31:5:main 48      static
```

`stack_usage.c:31:5:main 48      static` the result we wanted.


## avstack.pl
- you must ensure that your object files are compiled with -fstack-usage
- replace avr-objdump accroding to your toolchain

```info
Cost: peak stack usage during a call to the function.
Frame: stack frame size, obtained from the .su file, plus the call-cost constant.( function's original stack frame size.
Height: height in call graph -- calculated as the maximum height of any callee, plus one.
```

## reference
* https://dlbeer.co.nz/oss/avstack.html
* https://pinglinblog.wordpress.com/2016/10/18/linux-%E7%A8%8B%E5%BA%8F%E7%9A%84-memory-layout-%E5%88%9D%E6%B7%BA%E8%AA%8D%E8%AD%98/
* http://www.cnblogs.com/linsanshu/p/3925960.html
* http://hackmd.io/s/SJ6hRj-zg
* http://ccckmit.wikidot.com/gnu:csubroutine
* https://tw.saowen.com/a/3b760fad5a931523d6b7ed68856a9c17ae7bc1812a8d21955c55fbfd64d84278
* https://tw.saowen.com/a/2a090fdae670660b76c287a8336e708c8c21c7922a6027034797f36d0a1a5b2c
