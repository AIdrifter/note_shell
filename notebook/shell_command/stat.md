# statvfs vfsbuf

```C
// comupter partion size

if(strncmp(pszFName,global_pLicenseStorePath,strlen(global_pLicenseStorePath))==0)
{
    struct statvfs vfsbuf;
    int error;

    // get current folder on
    const char * const delim = "/";
    char buf[256] = {0};
    char buf2[256] = {0};
    memcpy(buf2,global_pLicenseStorePath,strlen(global_pLicenseStorePath));
    strcpy(buf, global_pLicenseStorePath);

    char *substr = NULL;
    char *prev_substr = NULL;
    int count = 0;
    substr = strtok(buf, delim);
    do {
        prev_substr = substr;
        substr = strtok(NULL, delim);

    } while (substr);
    char *dst = strstr(buf2,prev_substr);
    *(dst-1) = '\0';

    error = statvfs(buf2,&vfsbuf);
    if(error <0)
    {
        fprintf(stderr,"statvfs() fialed %d \n",error);
        goto ErrorExit;
    }

    if( write_mode )
    {
        unsigned long u64FreeSpaceInKB = (((U64)vfsbuf.f_bfree * (U64)vfsbuf.f_frsize) / 1024);
        printf("u64FreeSpaceInKB %lu \n",u64FreeSpaceInKB);
        if( u64FreeSpaceInKB < g__Store_Partion_Remainder_Size * 1024 )
        {
            printf("free space is not enough %lu KB < %u KB remove file %s \n",u64FreeSpaceInKB,g__Store_Partion_Remainder_Size*1024,global_pLicenseStorePath);
            unlink(global_pLicenseStorePath);
            goto ErrorExit;
        }
    }
}
```
