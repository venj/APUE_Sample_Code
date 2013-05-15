#include "apue.h"
#include <fcntl.h>
#ifndef RWRWRW
#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH )
#endif

int main (int argc, char const *argv[])
{
    umask(0);
    if(creat("foo.tmp", RWRWRW) < 0)
    {
        err_sys("create error for foo");
    }
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if(creat("bar.tmp", RWRWRW) < 0)
    {
        err_sys("create error for bar");
    }
    
    return 0;
}
