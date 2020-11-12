#include"shell.h" 
void list_func(char*path,int depth)    
{    
    DIR*pDirHandle= opendir(path);  
    struct dirent * dent ;  
    struct stat  fstat ;  
    if(pDirHandle==NULL)  
    {  
        printf("OpenDir %s  Error!\n",path);  
    }  
   chdir(path);  
    while((dent=readdir(pDirHandle))!=NULL)  
    {    
        //error then return -1   
        lstat(dent->d_name,&fstat);  
        if(S_ISDIR(fstat.st_mode))  
        {    
            //remove director . and ..  
            if(strcmp(".",dent->d_name)==0||  
              strcmp("..",dent->d_name)==0 )  
                continue ;  
            printf("%*s%s/\n",depth,"",dent->d_name) ;  
            list_func(dent->d_name,depth+4) ;  
        }else  
           printf("%*s%s\n",depth,"",dent->d_name);          
     }  
    chdir("..");  
    closedir(pDirHandle);  
}  
int Fls(int argc,char**argv)  {     
    char *pDirPath;
    if(argc==1){  
  	pDirPath = ".";
  
    }
    else{
    pDirPath=argv[1];  
    }
    int depath=0;  
    list_func(pDirPath,depath); 
    return 0 ;  
} 
