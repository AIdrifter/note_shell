#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>

void *malloc(size_t size)
{
    static size_t total_count = 0;
    static size_t total_malloc_size = 0;
    char buf[256];
    static void *(*real_malloc)(size_t) = NULL;
    if (real_malloc == NULL) {
        real_malloc = dlsym(RTLD_NEXT, "malloc");
    }
    sprintf(buf, "malloc called, size = %zu  total count = %zu total malloc size = %zu\n"
                                    , size, total_count++, total_malloc_size += size);
    write(2, buf, strlen(buf));
    return real_malloc(size);
}

