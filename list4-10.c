#include "apue.h"
#ifdef SOLARIS
#include <sys/mkdev.h>
#endif
// Can not compile under OSX Mountain Lion, 
// so copy the macros from /usr/local/sys/types.h 
// Why not compile??? 
#define	major(x)	((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
#define	minor(x)	((int32_t)((x) & 0xffffff))

int main (int argc, char const *argv[])
{
    int i;
    struct stat buf;
    
    for(size_t i = 0; i < argc; ++i) {
        printf("%s: \n", argv[i]);
        if(stat(argv[i], &buf) < 0) {
            err_ret("stat error");
            continue;
        }
        printf("dev = %d / %d\n", major(buf.st_dev), minor(buf.st_dev));
        if(S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)) {
            printf(" (%s) rdev = %d / %d\n", (S_ISCHR(buf.st_mode)) ? "character" : "block", major(buf.st_rdev), minor(buf.st_rdev));
        }
    }
    
    return 0;
}