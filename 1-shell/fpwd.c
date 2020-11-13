#include "shell.h"

char * Fpwd()
{
    char *path=NULL;
    path=getcwd(NULL,0); /*getcwd()会将当前工作目录的绝对路径复制到参数buffer所指的内存空间中,参数maxlen为buffer的空间大小*/
    return path;
}


