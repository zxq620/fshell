#include "shell.h"

int parseline(char *buf,int &argc,char**argv){
    while(*buf==' '){
        buf++;
    }
    int delim = 0;

    argc = 0;
    while(*buf!='\n'){

        while(buf[delim]!='\n'&&buf[delim]!=' '){
            delim++;
        }

        if(buf[delim] == '\n'){
            buf[delim] = '\0';
            argv[argc++] = buf;
            break;
        }
        buf[delim] = '\0';
        argv[argc++] = buf;

        buf+=delim+1;
        /*Ö¸Ê¾Æ÷indicator=0*/
        delim = 0;
        while(*buf==' '){
            buf++;
        }
    }
    /*the last element is NULL*/
    argv[argc] = NULL;
    return 0;
}
int tof(int argc,char **argv){
    if(strcmp(argv[0],"exit")==0&&argc==1){
        exit(0);
    }
    if(strcmp(argv[0],"cd")==0&&argc==1){
        if(chdir(argv[1])){
            printf("myselous:cd:%s:no such directory\n",argv[1]);
        }
        return 1;
    }
    if(strcmp(argv[0],"yes")==0&&argc==1){
        //Fyes(argc,argv);
        return 1;
    }
    if(strcmp(argv[0],"man")==0&&argc==1){
        Fman();
        return 1;
    }
    if(strcmp(argv[0],"date")==0&&argc==1){
        Fdate();
        return 1;
    }
    if(strcmp(argv[0],"cal")==0&&argc==1){
        Fcal();
        return 1;
    }
    if(strcmp(argv[0],"ls")==0&&argc==1){
        Fls(argc,argv);
        return 1;
    }
    if(strcmp(argv[0],"cat")==0&&argc==2){
        Fcat(argc,argv);
        return 1;
    }
    if(strcmp(argv[0],"rm")==0&&argc==2){
        Frm(argc,argv);
        return 1;
    }
    if(strcmp(argv[0],"mkdir")==0&&argc==2){
        Fmkdir(argc,argv);
        return 1;
    }
    if(strcmp(argv[0],"mv")==0&&argc==3){
        Fmv(argc,argv);
        return 1;
    }
    if(strcmp(argv[0],"cp")==0&&argc==3){
        Fcp(argc,argv);
        return 1;
    }
    if(strcmp(argv[0],"pwd")==0&&argc==1){
        Fpwd();
        return 1;
    }
    return 0;//not a buildin_command
}

void eval(char *cmdstring){
    int argc=0;
    /*parse the cmdstring to argv*/
    char *argv[MAX_CMD];
    /*Holds modified command line*/
    char buf[MAX_CMD];

    strcpy(buf,cmdstring);
    /*parse the cmdstring*/
    parseline(buf,argc,argv);
    if(argv[0]==NULL){
        return;/*ignore empty lines*/
    }
    /*is a buildin command*/
    /*direct return*/
    if(tof(argc,argv)) return;

}
int main(int argc,char *argv[]){

    char cmdstring[MAX_CMD];
    int n;
    while(1){
        printf("*myshell*>");
        fflush(stdout);

        /*read*/
        if((n=read(0,cmdstring,MAX_CMD))<0){
            printf("read error");
        }

        eval(cmdstring);
    }
    return 0;
}
