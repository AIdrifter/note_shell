# gdb
# remote gdb learning

# board Server
{System::Run} /applications/bin/process
ps | grep lunch
gdbserver :5566 --attach $(PID)


# client
# 1. your binary file
.$(toolchain)-gdb ./symbols/applications/
 arm-none-linux-gnueabi-gdb

# 2. we need non-striped symbol , find symbol here
set solib-absolute-prefix ./lib/

# 3.connect
target remote 172.16.22.23:5566

set solib-search-path  /tools/arm/arm-2012.09/arm-none-linux-gnueabi/libc/lib
b _DRM_BCERTFORMAT_ParseCertificate
b DRM_BCERTFORMAT_SetExpirationDate
b Oem_GetDRMFullPathName

# ignore event
handle SIG38 nostop

# info
ilistsize
whatis variable_name

# break pooint
break IdleAppFrame::OnKey

break $function_name
brak file.cpp:100
break *0x80408123

break <where>
    set a new breakpoint
delete <breakpoint#>
    Remove a breakpoint
clear
    Delete all breakpioints
enable <breakpoint#>
    Enable a disabled breakpoint
disable <breakpoint#>
    Disable a breakpoint


# continue
continue

# next (一行一行)
n

# printf variable
# print/format <what>
p variabble

printf/x $pc 'print program counter'
ex:pc is 0x7c3e20
x/4xb 0x7c3e20

# GDB COMMAND
以下是 gdb 的常見指令（其中 () 內為簡短指令）：

- help (h)：顯示指令簡短說明。例：help breakpoint

- file：開啟檔案。等同於 gdb filename

- run (r)：執行程式，或是從頭再執行程式。

- kill：中止程式的執行。

- backtrace (bt)：堆疊追蹤。會顯示出上層所有的 frame 的簡略資訊。

- print (p)：印出變數內容。例：print i，印出變數 i 的內容。

- list (l)：印出程式碼。若在編譯時沒有加上 -g 參數，list 指令將無作用。

- whatis：印出變數的型態。例： whatis i，印出變數 i 的型態。

- breakpoint (b, bre, break)：設定中斷點
           使用 info breakpoint (info b) 來查看已設定了哪些中斷點。
           在程式被中斷後，使用 info line 來查看正停在哪一行。
- continue (c, cont)：繼續執行。和 breakpoint 搭配使用。

- frame：顯示正在執行的行數、副程式名稱、及其所傳送的參數等等 frame 資訊。
     　frame 2：看到 #2，也就是上上一層的 frame 的資訊。

- next (n)：單步執行，但遇到 frame 時不會進入 frame 中單步執行。

- step (s)：單步執行。但遇到 frame 時則會進入 frame 中單步執行。

- until：直接跑完一個 while 迴圈。

- return：中止執行該 frame（視同該 frame 已執行完畢），
      　並返回上個 frame 的呼叫點。功用類似 C 裡的 return 指令。

- finish：執行完這個 frame。當進入一個過深的 frame 時，如：C 函式庫，
      　可能必須下達多個 finish 才能回到原來的進入點。

- up：直接回到上一層的 frame，並顯示其 stack 資訊，如進入點及傳入的參數等。

- up 2：直接回到上三層的 frame，並顯示其 stack 資訊。

- down：直接跳到下一層的 frame，並顯示其 stack 資訊。
    　必須使用 up 回到上層的 frame 後，才能用 down 回到該層來。

- display：在遇到中斷點時，自動顯示某變數的內容。

- undisplay：取消 display，取消自動顯示某變數功能。

- commands：在遇到中斷點時要自動執行的指令。

- info：顯示一些特定的資訊。如： info break，顯示中斷點，
    　info share，顯示共享函式庫資訊。

- disable：暫時關閉某個 breakpoint 或 display 之功能。

- enable：將被 disable 暫時關閉的功能再啟用。

- clear/delete：刪除某個 breakpoint。

- set：設定特定參數。如：set env，設定環境變數。也可以拿來修改變數的值。

- unset：取消特定參數。如：unset env，刪除環境變數。

- show：顯示特定參數。如：show environment，顯示環境變數。

- attach PID：載入已執行中的程式以進行除錯。其中的 PID 可由 ps 指令取得。

- detach PID：釋放已 attach 的程式。

- shell：執行 Shell 指令。如：shell ls，呼叫 sh 以執行 ls 指令。

- quit：離開 gdb。或是按下 <Ctrl><C> 也行。

- <Enter>：直接執行上個指令

# hacker gdb
```bash
gdb -nh buffer_overflow
```

```gdb
<gdb> b main
<gdb> set disassembly-flavor intel
<gdb> lay asm  # show asm language
<gdb> lay src  # show source code
<gdb> record
<gdb> ni  # run one assembly language
<gdb> n   # run one C language
<gdb> fin
<gdb> x/40wx $esp # real linux machine
<gdb> x/40wx $rsp # vmware ubuntu replace real linux machine
<gdb> x/40wx $sp  # GDB provides $sp pseudo-register that is automatically mapped to correct stack pointer register for a given platform.
<gdb> x/4wx  $eax
<gdb> x/i $address
<gdb> x/i never_use
   0x4005b6 <never_use>:        push   %rbp

<gdb> p/x 0xffffcf0c - 0xffffcef4 # 0x18
<gdb> p/d 0xffffcf0c - 0xffffcef4 # 24
```

# referecne
http://b8807053.pixnet.net/blog/post/336154079-%5B%E8%BD%89%E8%B2%BC%5Dgdb-%E4%BB%8B%E7%B4%B9
https://blog.csdn.net/yusiguyuan/article/details/28480691
