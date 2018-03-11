#include <stdio.h>
#include <stdlib.h>

void never_use()
{
    system("/bin/sh");
}


void smash()
{
    char buf[40];
    gets(buf);
}

int main()
{
    puts("let start smashing the task\n");
    smash();
    return 0;
}
