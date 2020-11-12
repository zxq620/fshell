#include"shell.h"

void Fman() {
    printf("1.mkdir 目录名/\n在当前目录或指定目录新建目录成功显示“created sucessfully!”，不成功显示“created failed!”，已有同名目录则显示“exist!”\n");
    printf("2.cp 源文件名 目的文件或目录\n将源文件复制到指定目录或文件，没有指定文件或目录则显示“file no exsit!”\n");
    printf("3.mv 源文件名 目的文件或目录\n若目标路径是目录，将源文件移动到指定目录，没有指定文件则显示“file no exsit!”，若目标路径是文件名，则重命名源文件\n");
    printf("4.rm 文件名\n删除指定文件，删除失败显示“error”\n");
    printf("5.man\n显示项目所有命令及其功能\n");
    printf("6.ls\n列出目前工作目录所含之文件及子目录\n");
    printf("7.cat 文件名\n输出指定文件内容，没有指定文件则显示“please input source file!”\n");
    printf("8.date\n输出当前年-月-日 时：分：秒\n");
    printf("9.cal\n输出系统当月的完整日历\n");
    printf("10.yes\n输出yes直到按q\n");
    printf("11.pwd\n输出当前所在目录\n");
    printf("12.exit\n退出fshell系统\n");
}
