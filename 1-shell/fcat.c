#include"shell.h"
int Fcat(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");   // 以只读方式打开文件，argv[1]是输入的要显示的文件路径名
    int read_ret;
    if(argc < 2){
        printf("please input source file!\n");
    }
    if(fp == NULL){
        printf("open source %s failed!\n", argv[1]);
    }
    while(1){
        read_ret = fgetc(fp); /*C 库函数 int fgetc(FILE *stream) 从指定的流 stream 获取下一个字符（一个无符号字符），并把位置标识符往前移动。该函数以无符号 char 强制转换为 int 的形式返回读取的字符，如果到达文件末尾或发生读错误，则返回 EOF。*/
        if(feof(fp)) { /*C 库函数 int feof(FILE *stream) 测试给定流 stream 的文件结束标识符。当设置了与流关联的文件结束标识符时，该函数返回一个非零值，否则返回零。*/
            break;
        }
        fputc(read_ret,stdout); /*C 库函数 int fputc(int char, FILE *stream) 把参数 char 指定的字符（一个无符号字符）写入到指定的流 stream 中，并把位置标识符往前移动。*/
    }
return 0;
}
