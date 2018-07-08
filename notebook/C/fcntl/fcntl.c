#include <fcntl.h>

/*
 * return value
 * sucess：accronding to cmd
 * failed：-1
 *
 */
int fcntl_wrap (
        int fd,                  // 用 open() 所取得的 File descriptor
        int cmd,                 // F_SETLK, F_SETLKW, F_GETLK
        struct flock *stLock);   // flock structure
