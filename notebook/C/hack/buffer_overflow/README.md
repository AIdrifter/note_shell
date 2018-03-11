# buffer overflow attack

gdb --nh buffer_overfow

# Protection
## ALSR(Address Space Layout Randomization)
linux:
0: disable ASLR
1: stack ,shared memory, mmap()
2: (1)+brk()

````shel
cat /proc/sys/kernel/randomize_va_space
cat /proc/self/maps
```


## Stack Guard(Stack Canary)
```shell
gcc -fno-stack-protector
readelf -s {binary} | grep __stack_chk_fail
```

## RELRO(Relocation Read Only)
```shell
gcc 0Wl,-z,norelo
```

# PIE:Position indepent Executable
* Disable PIE(Position Independent Executable)
data and text will be affected by ASLR
```shell
gcc -no-pie
readelf -h {binary} | grep Type
```

```info
多種檢查一次滿足的好工具
checksec in pwntools
```


# attack way
## Return to text
gcc  buffer_overflow.c -o buffer_overflow -fno-stack-protector -no-pie
./buffer_overflow  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbb
objdump -d buffer_overflow
```assembly
00000000004005b6 <never_use>:
  4005b6:       55                      push   %rbp
  4005b7:       48 89 e5                mov    %rsp,%rbp
  4005ba:       bf 94 06 40 00          mov    $0x400694,%edi
  4005bf:       e8 bc fe ff ff          callq  400480 <system@plt>
  4005c4:       90                      nop
  4005c5:       5d                      pop    %rbp
  4005c6:       c3                      retq
```
```gdb
<gdb> lay asm
<gdb> fin
<gdb> ni
<gdb> x/40wx $esp
<gdb> x/4wx  $eax
<gdb> x/i $address
<gdb> x/i never_use
   0x4005b6 <never_use>:        push   %rbp
```

* remember
Endianness
little endian


## Return to libc + ROP


