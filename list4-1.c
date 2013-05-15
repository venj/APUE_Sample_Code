#include "apue.h"

int main (int argc, char const *argv[]) {
    struct stat buf;
    char *ptr;
  
    for(size_t i = 1; i < argc; ++i) {
        printf("%s: ", argv[i]);
        if(lstat(argv[i], &buf) < 0) {
            err_ret("lstat error");
            continue;
        }
        mode_t m = buf.st_mode;
        if(S_ISREG(m))
            ptr = "regular";
        else if (S_ISDIR(m))
            ptr = "directory";
        else if (S_ISCHR(m))
            ptr = "character special";
        else if (S_ISBLK(m))
            ptr = "block special";
        else if (S_ISFIFO(m))
            ptr = "fifo";
        else if (S_ISLNK(m))
            ptr = "symbolic link";
        else if (S_ISSOCK(m))
            ptr = "socket";
        else
            ptr = "*** unknown mode ***";
        
        printf("%s\n", ptr);
    }
    
    return 0;
}