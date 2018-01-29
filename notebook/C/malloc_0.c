#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = NULL;
    printf("before ptr address %p \n",ptr);
    ptr = malloc(0);
    printf("after ptr address %p \n",ptr);
}
