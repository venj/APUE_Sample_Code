#include "apue.h"

int main (int argc, char const *argv[])
{
    char *ptr;
    int size;
    if(chdir("/Users/venj") < 0)
    {
        err_sys("chdir failed");
    }
    ptr = path_alloc(&size);
    if(getcwd(ptr, size) == NULL)
    {
        err_sys("get_cwd failed");
    }
    printf("cwd = %s\n", ptr);
    free(ptr);
    return 0;
}