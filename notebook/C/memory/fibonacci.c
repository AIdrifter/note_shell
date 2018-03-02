#include <stdio.h>
#include <stdlib.h>


//
// fibonacci
// fn = fn-1 + fn-2 , n >= 2
//

int fib(int n)
{
    if (n == 1)
        return 0;
    if (n == 2 )
        return 1;

    return fib(n-1) + fib(n-2) + fib(n-3);

}

int main()
{
    printf("My fibonacci number is %u \n",fib(100));
}
