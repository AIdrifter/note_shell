#include<stdio.h>
#include<ctype.h>

int FindNum(const int array[], int num, int conut);// declare function


// array[] can't change any value
int FindNum(const int array[], int num, int count)
{
    int i;
    int flag = 1;

    for (i = 0; (i < count) && flag; i++)
    {
        if (array[i] == num)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}


void ChangeStr(const char *String)
{
    char *Source = (char *)String;

    while (*Source)
    {
        *Source = toupper(*Source);
        Source++;
    }
}

int main()
{
    /*
     * Be familiar with declaring const pointer
     */
    const char ch = 'a';
    const int a[5] = {1, 2, 3, 4, 5};

    const int *p = a;
    // const "int *p"
    // *p can not change any value in a[5]
    // *p = 10;       /*error*/
    // *(p + 2) = 1;  /*error*/

    int * const p1 = a;
    // "const p1"
    //  p1's content value is const, *p1 = 4 is correct, but you can not change const p1's content value
    *p1 = 2;          /*pass*/
    *(p1 + 1) = 10;   /*pass*/
    //  p1++;             /*error*/

    const int * const p2 = a;
    //  *p2 = 2;             /*error*/
    //  *(p2 + 2) = 10;   /*error*/
    //  p2++;                /*error*/


    /*
     * Although declaring const variable, variable still is possible modified.
     */
    char str[] = "The C programme";

    ChangeStr(str);
    puts(str);

    return 0;
}

