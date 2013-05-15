#include "apue.h"

int main (int argc, char const *argv[])
{
    struct stat statbuf;
    
    if(stat("foo.tmp", &statbuf) < 0)
    {
        err_sys("stat error for foo");
    }
    if(chmod("foo.tmp", statbuf.st_mode | S_ISUID ) < 0)
    {
        err_sys("chmod error for foo");
    }
    if(chmod("bar.tmp", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP) < 0)
    {
        err_sys("chmod error for bar");
    }
    
    return 0;
}