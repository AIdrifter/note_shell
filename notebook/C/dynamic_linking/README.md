# Dynamic linking

# How to get malloc() and free() count ?
- The issue here is that `RTLD_NEXT` is not defined by the posix standard.
  So the GNU people don't enable it unless you
  `#define _GNU_SOURCE or -D_GNU_SOURCE.`
  https://stackoverflow.com/questions/1777397/rtld-next-undeclared

```bash
gcc -D_GNU_SOURCE -shared -ldl -fPIC -o  libmcount.so malloc_count.c
LD_PRELOAD=./libmcount.so ls
```
