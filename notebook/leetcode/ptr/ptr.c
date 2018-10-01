#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>


int main()
{
    /*
     *   Priority:
     *     deference > Add operation
     *     *p++   =   *(p++)
     *     *++p   =   *(++p)
     *     ++*p   =   ++(*p)
     *     (*p)++
     */

    char s[]="0113256";
    char *p = s;

    *p++;
    *(p++);
    (*p)++;
    *++p;
    *(++p);
    ++*p;
    ++(*p);

    puts(s);
    return 0;
}
