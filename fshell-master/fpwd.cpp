#include "shell.h"
void printpathto(ino_t this_inode)
{
    ino_t my_inode;
    char its_name[BUFSIZ];
    /*如果本目录的i-节点与上级目录不同，即本目录不是根目录*/
    if (get_inode("..")!=this_inode)                                 
    {
        chdir("..");         //进入上级目录
        inum_to_name(this_inode,its_name,BUFSIZ);
        my_inode = get_inode(".");
        printpathto(my_inode);
        printf("/%s",its_name);
    }
}
void inum_to_name(ino_t inode_to_find,char* namebuf,int buflen)   //找到i-节点对应的文件名，并放在字符数组里
{
    DIR* dir_ptr;
    struct dirent* direntp;
    dir_ptr = opendir(".");
    if (dir_ptr == NULL)
    {
        perror(".");
        exit(1);
    }
 
    while((direntp = readdir(dir_ptr)) != NULL)
    {
        if(direntp->d_ino == inode_to_find)
        {
            strncpy(namebuf,direntp->d_name,buflen);
            namebuf[buflen-1] = '\0';
            closedir( dir_ptr);
            return;
        }
    }
    fprintf( stderr , "error looking for inum % d\n" ,inode_to_find);
    exit (1) ;
}
ino_t get_inode(char* fname)            //根据文件名，返回-i节点
{
    struct stat info;
    if ( stat( fname, &info) == -1){
        fprintf( stderr , "Cannot stat ");
        perror(fname);
        exit (1);
    }
    return info.st_ino;
}

int Fpwd()
{
    printpathto(get_inode("."));  //print path to here
    putchar('\n');
    return 0;
}


