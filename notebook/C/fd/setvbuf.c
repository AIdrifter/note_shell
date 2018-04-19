#include <stdio.h>

int main ()
{
    FILE *pFile;
    char buffer[] = "1234567890_111111111111_22222222222_333333333333_44444444444444444";
    pFile=fopen ("myfile.txt","w");

    /* Full buffering: On output, data is written once the buffer is full (or flushed). On Input, the buffer is filled when an input operation is requested and the buffer is empty. */
    setvbuf ( pFile , NULL , _IOFBF , 1024 );

    /*
     * Line buffering: On output, data is written when a newline character is inserted into the stream
     * or when the buffer is full (or flushed), whatever happens first. On Input,
     * the buffer is filled up to the next newline character when an input operation is requested and the buffer is empty.
     */
    setvbuf ( pFile , NULL , _IOLBF , 1024 );

    /* No buffering: No buffer is used. Each I/O operation is written as soon as possible. In this case, the buffer and size parameters are ignored. */
    setvbuf ( pFile , NULL , _IONBF , 1024 );

    // File operations here
    fwrite (buffer, 1, sizeof(buffer), pFile);

    fclose (pFile);
    return 0;
}
