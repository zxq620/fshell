#include"shell.h"

//linux����ָ��rm
int main(int argc, char *argv[])
{
    int rt;
    if(argc != 2){
        exit(2);
    }else{
        if((rt = unlink(argv[1])) != 0) {
            fprintf(stderr, "error\n");
            exit(3);
        }
    }
    return 0;
}
