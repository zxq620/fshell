#include"shell.h"

extern int errno;

#define MODE (S_IRWXU | S_IRWXG | S_IRWXO)

int mk_dir(char *dir){
    DIR *mydir = NULL;
    if((mydir= opendir(dir))==NULL){//判断目录
      int ret = mkdir(dir, MODE);//创建目录
      if (ret != 0){
          return -1;
      }
      printf("%s created sucessfully!\n", dir);
    }else{
        printf("%s exist!\n", dir);
    }

    return 0;
}

int mk_all_dir(char *dir)
{
    int flag = 1;
    char *pDir = dir;
    while (flag) {
        char *pIndex = index(pDir, '/');
        if (pIndex != NULL && pIndex != dir){
            char buffer[512] = {0};
            int msg_size = pIndex - dir;
            memcpy(buffer, dir, msg_size);
            int ret = mk_dir(buffer);
            if (ret < 0){
                printf("%s created failed!\n", dir);
            }
        }
        else if (pIndex == NULL && pDir == dir){
            printf("dir is not directory!\n");
            return -1;
        }
        else if (pIndex == NULL && pDir != dir) {
            int ret = mk_dir(dir);
            if (ret < 0){
                printf("%s created failed!\n", dir);
            }

            break;
        }
        pDir = pIndex+1;
    }
    return 0;
}

int Fmkdir(int argc, char **argv )
{

    char *pIndex = index(argv[1], '\n');
    if (pIndex != NULL){
        *pIndex = '/';
    }
    int ret = mk_all_dir(argv[1]);
    if (ret < 0) {
        printf("%s mkdir failed!\n", argv[1]);
        return -1;
    }

    return 0;
}
