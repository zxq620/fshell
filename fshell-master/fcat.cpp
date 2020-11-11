#include"shell.h"
int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "r");   // 以只读方式打开文件，argv[1]是输入的要显示的文件路径名
    int read_ret;
    if(argc < 2){
        printf("please input source file!\n");
    }
    if(fp == NULL){
        printf("open source %s failed!\n", argv[1]);
        return -1;
    }
    while(1){
        read_ret = fgetc(fp); 
        if(feof(fp)) {
            break;
        }
        fputc(read_ret,stdout); 
    }
    return 0;
}
