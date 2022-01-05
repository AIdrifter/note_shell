# gdb
make -j`nproc` BUILD_PLATFORM=trinidad BOARD_TYPE=mtk-roku rootfs port-image port-emmc_mfg PAX_DEBUG=on
## Client
noreset; gdbserver :5555 --attach $(ps -a | grep Application | head -1 | cut -c 2-5)


## server
cgdb -d gdb-multiarch  ./firmware/port/mediatek/r819/trinidad/dist/rootfs.rescue/bin/Application
gdb-multiarch   ./firmware/port/mediatek/r819/trinidad/dist/rootfs.rescue/bin/Application

set pagination off
set sysroot ./firmware/port/mediatek/r819/trinidad/dist/rootfs.rescue/
set solib-absolute-prefix ./firmware/port/mediatek/r819/trinidad/dist/rootfs.rescue/
add-auto-load-safe-path ./firmware/port/mediatek/r819/trinidad/dist/rootfs.rescue/
handle SIG32 SIG33 SIG53 SIGUSR2 SIGCHLD nostop noprint
target remote 192.168.10.7:5555


