#include "apue.h"
#include "list3-5.h"
#include <fcntl.h>

#ifndef BUFFSIZE
#define BUFFSIZE 4096
#endif

int main (int argc, char const *argv[])
{
  int n;
  char buf[BUFFSIZE];
  set_fl(STDOUT_FILENO, O_SYNC);
  
  while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    if (write(STDOUT_FILENO, buf, n) != n)
      err_sys("write error");
  
  if(n < 0)
    err_sys("read error");
  
  return 0;
}
