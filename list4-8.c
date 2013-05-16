#include "apue.h"

int main (int argc, char const *argv[])
{
    if(chdir("/tmp") < 0)
    {
        err_sys("chdir failed");
    }
    printf("chdir to /tmp succeeded\n");
    return 0;
}