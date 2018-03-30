#include <stdio.h>
#include <stdlib.h>

// gcc -DFLAG_1 -DFLAG_2 -E test.c > test_E.c
// All FLAG wil be compiler


// gcc -DFLAG_1=0 -DFLAG_2=0 -E test.c > test_E.c
// FLAG_2 still be compiler....

// gcc -E test.c > test_E.c
// FLAG_3 can compiler sucess even if we don't add -DFLAG_3
// FLAG_3 can compiler sucess 


int main()
{
#if (FLAG_1 == 1)
    printf("FLAG_1 == 1\n");
#endif

// -DFLAG_2=0 still will compielr it
#ifdef FLAG_2
    printf("FLAG_2 == 1\n");
#endif

#if defined FLAG_3 && (FLAG_3 == 1)
    printf("FLAG_3 == 1\n");
#endif

    return 0;
}
