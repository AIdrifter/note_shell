#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int reverse(int x)
{
    bool nagative = false;
    char buf[256] = {0};
    char final_buf[256] = {0};
    int i;
    long res;
    if (x < 0)
    {
        x = -x;
        nagative = true;
    }

    sprintf(buf,"%d",x);

    for(i=0; i<strlen(buf) ;i++ )
    {
        final_buf[i] = buf[strlen(buf)-1-i];
    }
    res = atol(final_buf);

    if (nagative)
    {
        if(-res < INT_MIN)
            return 0;
        else
            return -res;
    }
    else
    {
        if (res > INT_MAX)
            return 0;
        else
            return res;
    }
}


int main()
{
    int ret = 0;

    if(reverse(1534236469) !=  0)
    {
        ret = -1;
        printf("failed %u\n",__LINE__);
    }

    if(reverse(-123) != - 321)
    {
        ret = -1;
        printf("failed %u\n",__LINE__);
    }

    if(reverse(120) !=  21)
    {
        ret = -1;
        printf("failed %u\n",__LINE__);
    }

Error:
    if(ret==0)
        printf("PASS! \n");
    else
        printf("FAILED!");
    return ret;;

}
