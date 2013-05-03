#include "apue.h"
#include <dirent.h>

int main (int argc, char const *argv[])
{
  DIR *dp;
  struct dirent *dirp;
  
  if(argc != 2) {
    /* code */
    err_quit("usage: ls directory_name");
  }
  if((dp = opendir(argv[1])) == NULL) {
    /* code */
    err_sys("can not open %s", argv[1]);
  }
  while ((dirp = readdir(dp)) != NULL)
    printf("%s \t %d\n", dirp->d_name, dirp->d_reclen);
  
  closedir(dp);
  return 0;
}
