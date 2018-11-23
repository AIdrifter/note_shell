#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

int add_one(int x)
{
    return -~x; // ++x
}

int sub_one(int x)
{
    return ~-x; // --x
}

int main()
{
    int a = 10;
    a = add_one(a);
    a = sub_one(a);

    return 0;
}
