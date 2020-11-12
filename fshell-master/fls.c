#include "shell.h"
char filename[256][256];
int len = 0;
int trave_dir(const char* path)
{
    DIR *d; //声明一个句柄
    struct dirent *file; //readdir函数的返回值就存放在这个结构体中
    struct stat sb;   
   
    if(!(d = opendir(path)))
    {
        printf("error opendir %s!!!\n",path);
        return -1;
    }
    while((file = readdir(d)) != NULL)
    {
        //把当前目录.，上一级目录..及隐藏文件都去掉，避免死循环遍历目录
        if(strncmp(file->d_name, ".", 1) == 0)
            continue;
        strcpy(filename[len++], file->d_name); //保存遍历到的文件名
   
    }
    closedir(d);
    return 0;
}
int Fls()
{
    trave_dir(".");
    for(int i = 0; i < len; i++)
    {
        printf("%s\n", filename[i]);
    }
    len=0;
    return 0;
}
