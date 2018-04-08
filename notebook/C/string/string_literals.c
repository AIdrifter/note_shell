#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Allocate 11 bytes in the stack and store "hello world" in them */
    char p2[] = "hello world";

    /* Allocate pointer P2 on the stack and point it to a static,
     * read-only buffer containning "hello world"
     * read-only data section can not be modified.
     */
    char *p1 = "hello world";

    /* malloc 5 bytes (which isn't enough to hold "hello" due to the NULL byte) */
    char *heap_string_malloc = malloc(5);

    /* Reset heap_string_malloc to point a static buffer; memory leak */
    heap_string_malloc= "hello";

}
