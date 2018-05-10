# rpath

# linking rpath-link rpath -L

# priority
    1.LD_LIBRARY_PATH
    2./lib
    3./usr/lib
    4./etc/ld.so.conf

Reference: why LD_LIBRARY_PATH is bad

# gcc -R -rpath
    compiler can divide Link-time path and Run-time path
    link 與 run 時間分開

# man ld

-L: 「鏈接」的時候，去找的目錄，也就是所有的 -lFOO 選項裡的庫，都會先從 -L 指定的目錄去找，然後是默認的地方。編譯時的-L選項並不影響環境變量LD_LIBRARY_PATH，-L只是指定了程序編譯連接時庫的路徑，並不影響程序執行時庫的路徑，系統還是會到默認路徑下查找該程序所需要的庫，如果找
不到，還是會報錯，類似cannot open shared object file。

-rpath-link：這個也是用於「鏈接」的時候的，例如你顯示指定的需要 FOO.so，但是 FOO.so 本身是需要 BAR.so 的，後者你並沒有指定，而是 FOO.so 引用到它，這個時候，會先從 -rpath-link 給的路徑裡找。

-rpath: 「運行」的時候，去找的目錄。運行的時候，要找 .so 文件，會從這個選項裡指定的地方去找。對於交叉編譯，交叉編譯鏈接器需已經配置 –with-sysroot 選項才能起作用。也就是說，-rpath指定的路徑會被記錄在生成的可執行程序中，用於運行時查找需要加載的動態庫。-rpath-link 則只用於
鏈接時查找。


1.  Any directories specified by -rpath-link options.
       2.  Any directories specified by -rpath options.  The difference between -rpath and -rpath-link is that directories specified by -rpath options are included in the executable and used at runtime, whereas the -rpath-link option is only effective at link time. Searching -rpath in this way is only supported by native linkers and cross linkers which have been configured with the --with-sysroot option.
       3.  On an ELF system, for native linkers, if the -rpath and -rpath-link options were not used, search the contents of the environment variable "LD_RUN_PATH".
       4.  On SunOS, if the -rpath option was not used, search any directories specified using -L options.
       5.  For a native linker, the search the contents of the environment variable "LD_LIBRARY_PATH".
       6.  For a native ELF linker, the directories in "DT_RUNPATH" or "DT_RPATH" of a shared library are searched for shared libraries needed by it. The "DT_RPATH" entries are ignored if "DT_RUNPATH" entries exist.
       7.  The default directories, normally /lib and /usr/lib.
       8.  For a native linker on an ELF system, if the file /etc/ld.so.conf exists, the list of directories found in that file.
       If the required shared library is not found, the linker will issue a warning and continue with the link.

# Conclusion
    1.rpath-link <=> -L
    2.rpath : run-time

# situation x86

main.c--->libA.so--->libB.so

/lib/libA.so
/usr/lib/libB.so

gcc main.c -o main -L /lib lA -L/usr/lib -lB
#  gcc main.c -o main -L/lib -la

0.-L 都找
1.linnk 階段需要 resolve 所有的 symbols (解決所有 dependency) 要把所有相關的 dependent libraries 全找出來又是不切實際的。
    => GNU ld 的設計中有個預設路徑會去自動搜尋在 link 階段所需要的 library，


# situation embeded system

main.c--->libA.so--->libB.so

/home/some_one/lib/libA.so
/home/some_one/lib/libB.so

mips-linux-gcc main.cpp -o main -L/home/some_one_A/lib -lA -rpath-link /home/some_one_B/lib

-L/home/some_one_A/lib 用來對應 -lA，找 libA.so 時用，
-rpath-link /home/some_one_B/lib 用來補充 mips-linux-gcc 預設路徑，


reference:http://stellvia7.pixnet.net/blog/post/106956896-%5B%E8%BD%89%5Drpath

