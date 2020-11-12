#include "shell.h"

char * Fpwd()
{
    char *path=NULL;
    path=getcwd(NULL,0);
    return path;
}


