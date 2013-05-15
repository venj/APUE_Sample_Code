#include "apue.h"
#include <unistd.h>

#define BUFSIZE 4096

int main (int argc, char const *argv[])
{
    if(argc != 2)
    {
        err_sys("usage: a.out <pathname>");
    }
    
    char buf[BUFSIZE];
    
    ssize_t size = readlink(argv[1], buf, BUFSIZE);
    buf[size] = '\0';
    
    printf("%s\n", buf);
    
    return 0;
}