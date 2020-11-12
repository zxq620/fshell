#include "shell.h"

void Fcd(int argc,char **argv)
{
    chdir(argv[1]);
}

