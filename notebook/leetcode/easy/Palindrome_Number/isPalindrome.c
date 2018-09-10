#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

bool isPalindrome(int x) {
    int len=0;
    int i=0;
    if(x<0)
        return false;

    char buf[256]={0};
    sprintf(buf,"%d",x);

    len=strlen(buf)-1;
    while(buf[i]==buf[len])
    {

        if(i==len)
            return true;
        if(i==strlen(buf)/2)
            return true;
        i++;len--;
    }

    return false;
}

int main()
{
    printf("%d",isPalindrome(11));
    return 0;
}


