#include "shell.h"

int parseline(int l,char *buf,char**argv){
    while(*buf==' '){
        buf++;
    }
    int delim = 0;

    int argc = 0;
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
    return argc;
}
int tof(int argc,char **argv){
    if(strcmp(argv[0],"exit")==0&&argc==1){
        exit(0);
    }
    else if(strcmp(argv[0],"cd")==0&&argc==1){
        if(chdir(argv[1])){
            printf("myselous:cd:%s:no such directory\n",argv[1]);
        }
        return 1;
    }
    else if(strcmp(argv[0],"yes")==0&&argc==1){
        Fyes(argc,argv);
        return 1;
    }
    else if(strcmp(argv[0],"man")==0&&argc==1){
        Fman();
        return 1;
    }
    else if(strcmp(argv[0],"date")==0&&argc==1){
        Fdate();
        return 1;
    }
    else if(strcmp(argv[0],"cal")==0&&argc==1){
        Fcal();
        return 1;
    }
    else if(strcmp(argv[0],"ls")==0&&argc==1){
        Fls();
        return 1;
    }
    else if(strcmp(argv[0],"cat")==0&&argc==2){
        Fcat(argc,argv);
        return 1;
    }
    else if(strcmp(argv[0],"cd")==0&&argc==2){
        Fcd(argc,argv);
        return 1;
    }
    else if(strcmp(argv[0],"rm")==0&&argc==2){
        Frm(argc,argv);
        return 1;
    }
    else if(strcmp(argv[0],"mkdir")==0&&argc==2){
        Fmkdir(argc,argv);
        return 1;
    }
    else if(strcmp(argv[0],"mv")==0&&argc==3){
        Fmv(argc,argv);
        return 1;
    }
    else if(strcmp(argv[0],"cp")==0&&argc==3){
        Fcp(argc,argv);
        return 1;
    }
    else if(strcmp(argv[0],"pwd")==0&&argc==1){
        char *path=Fpwd();
        printf("%s\n",path);
        return 1;
    }
    else{
        printf("command not found!\n");
    }
    
    return 0;//not a buildin_command
}

void eval(char *cmdstring){
    //printf("%s",cmdstring);
    int argc=0;
    /*parse the cmdstring to argv*/
    char *argv[10000];
    /*Holds modified command line*/
    char buf[10000];

    strcpy(buf,cmdstring);
    /*parse the cmdstring*/
    int l=strlen(cmdstring);
    argc=parseline(l,buf,argv);
    if(argv[0]==NULL){
        return;/*ignore empty lines*/
    }
    /*is a buildin command*/
    /*direct return*/
    if(tof(argc,argv)) return;

}
int main(void){
    char *cmdstring;
    char path[10000];
    while(1){     
        //printf("\033[32m\033[1m*fshell*:\033[0m\033[34m\033[1m%s\033[0m$",Fpwd());
	sprintf(path,"\033[32m\033[1m*fshell*:%s\033[0m$",Fpwd());
        cmdstring=readline(path);
	add_history(cmdstring);
	cmdstring[strlen(cmdstring)]='\n';
        eval(cmdstring);
    }
    return 0;
}
