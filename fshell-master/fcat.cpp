#include"shell.h"
int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "r");   // ��ֻ����ʽ���ļ���argv[1]�������Ҫ��ʾ���ļ�·����
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
