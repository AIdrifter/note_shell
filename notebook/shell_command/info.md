# info
- GDB debug information
## info proc
info proc process-id
Summarize available information about any running process. If a process ID is specified by process-id, display information about that process; otherwise display information about the program being debugged. The summary includes the debugged process ID, the command line used to invoke it, its current working directory, and its executable file’s absolute file name.

On some systems, process-id can be of the form ‘[pid]/tid’ which specifies a certain thread ID within a process. If the optional pid part is missing, it means a thread from the process being debugged (the leading ‘/’ still needs to be present, or else GDB will interpret the number as a process ID rather than a thread ID).

## info proc mappings
- Report the memory address space ranges accessible in the program.

## info proc stat

```shell
process 73280
Process: 73280
Exec file: a.out
State: t
Parent process: 73128
Process group: 73280
Session id: 73044
TTY: 34827
TTY owner process group: 73128
Flags: 0x40000000
Minor faults (no memory page): 198
Minor faults, children: 0
Major faults (memory page faults): 1
Major faults, children: 0
utime: 0
stime: 0
utime, children: 0
stime, children: 0
jiffies remaining in current time slice: 20
'nice' value: 0
jiffies until next timeout: 1
---Type <return> to continue, or q <return> to quit---
jiffies until next SIGALRM: 0
start time (jiffies since system boot): 55087799
Virtual memory size: 4313088
Resident set size: 202
rlim: 18446744073709551615
Start of text: 0x555555554000
End of text: 0x555555554a34
Start of stack: 0x7fffffffdcf0
```

## info proc all
Show all the information about the process described under all of the above info proc subcommands.

Reference:
https://sourceware.org/gdb/current/onlinedocs/gdb/Process-Information.html
