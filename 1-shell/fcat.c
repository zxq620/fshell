#include"shell.h"
int Fcat(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");   // ��ֻ����ʽ���ļ���argv[1]�������Ҫ��ʾ���ļ�·����
    int read_ret;
    if(argc < 2){
        printf("please input source file!\n");
    }
    if(fp == NULL){
        printf("open source %s failed!\n", argv[1]);
    }
    while(1){
        read_ret = fgetc(fp); /*C �⺯�� int fgetc(FILE *stream) ��ָ������ stream ��ȡ��һ���ַ���һ���޷����ַ���������λ�ñ�ʶ����ǰ�ƶ����ú������޷��� char ǿ��ת��Ϊ int ����ʽ���ض�ȡ���ַ�����������ļ�ĩβ�����������򷵻� EOF��*/
        if(feof(fp)) { /*C �⺯�� int feof(FILE *stream) ���Ը����� stream ���ļ�������ʶ�����������������������ļ�������ʶ��ʱ���ú�������һ������ֵ�����򷵻��㡣*/
            break;
        }
        fputc(read_ret,stdout); /*C �⺯�� int fputc(int char, FILE *stream) �Ѳ��� char ָ�����ַ���һ���޷����ַ���д�뵽ָ������ stream �У�����λ�ñ�ʶ����ǰ�ƶ���*/
    }
return 0;
}
