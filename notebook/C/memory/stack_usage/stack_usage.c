#include <stdio.h>
#include <stdlib.h>


int add2(int a, int b)
{
    return a + b;
}

int add3(int a, int b, int c)
{
    return a + b + c;
}

int add3_local1(int a, int b, int c)
{
    int local_1 = add2(a,b);

    return local_1;
}


int add3_local2(int a, int b, int c)
{
    int local_1 = add2(a,b);
    int local_2 = add3(a,b,c);

    return local_1 + local_2 ;
}

int main()
{
    int a = 10, b = 20, c = 30;
    add2(a,b);
    add3(a,b,c);

    printf("all stack usage is .......add2() %d add3() %d \n", add2(a,b), add3(a,b,c));
}
