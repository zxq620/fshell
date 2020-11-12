#include"shell.h"


int Frm(int argc, char **argv)
{
    int rt;
    if(argc != 2){
        return 0;
    }else{
        if((rt = unlink(argv[1])) != 0) {
            fprintf(stderr, "error\n");
        }
        return 0;
    }

}
