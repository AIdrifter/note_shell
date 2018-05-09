#include <stdio.h>
#include <stdlib.h>

void digInStack(const char * string)
{
    int i;
    long sneak[1];

    printf("[ %s ] \n",string);
    /* feel free to adjust the search limits */
    for( i = -32; i <= 32; ++i) {
        printf("offset %3d: data 0x%08X\n", i, sneak[i]);
    }
    puts("...................\n");
}

int add2(int a, int b)
{
    digInStack(__func__);
    printf("[%s]  0x%08X \n",__func__,__builtin_return_address(0));
    return a + b ;
}

int add3(int a, int b, int c)
{
    digInStack(__func__);
    printf("[%s] 0x%08X \n",__func__,__builtin_return_address(0));
    return add2(a,b) + c;
}


int add4(int a, int b, int c, int d)
{
    digInStack(__func__);
    printf("[%s] 0x%08X \n",__func__,__builtin_return_address(0));
    return (add2(a,b) + add2(c,d));
}


int main()
{
    int a=4,b=5,c=3;
    int res1,res2;
    res1 = add2(a,b);
    res2 = add3(a,b,c);
    printf("show all fucntion address add2 0x%08X  add3 0x%08X  add4 0x%08X \n",add2 ,add3 ,add4 );
    digInStack(__func__);
    printf("[%s] 0x%08X \n",__func__,__builtin_return_address(0));
    return 0;
}
