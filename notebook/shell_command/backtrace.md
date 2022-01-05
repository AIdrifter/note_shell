# backtrace

# Android backtrace                                                                                                                                                                                                                                                    [2/1097]
http://janbarry0914.blogspot.tw/2014/07/androiddump-call-stack.html

#include <utils/CallStack.h>

CallStack stack;
stack.update();
//stack.dump();
stack.log("XXX");


# after Android 4.4
#include <utils/CallStack.h>
...
CallStack stack;
stack.update();
stack.log();

# Linux backtrace
https://panthema.net/2008/0901-stacktrace-demangled/

arm-none-linux-gnueabi-addr2line -e symbols/applications/bin/xxxx 0x41018b40
arm-none-linux-gnueabi-addr2line -e symbols/applications/bin/xxxx 0x69115c

r2-elf-addr2line



#include <unistd.h>
#include <execinfo.h>
#define backtrace do{\
   void *array[10];\
   uint32_t size;\
   size = backtrace(array, 10);\
   backtrace_symbols_fd(array, size, STDERR_FILENO);\
}while(0)

# Roku

#include <Base/Backtrace.h>
 logger.logConsole("pierre", "%s %s", __func__, Backtrace::getString().c_str());
https://confluence.portal.roku.com:8443/pages/viewpage.action?pageId=59939083#Core+gdbusefulcommands-Backtraceatruntime
