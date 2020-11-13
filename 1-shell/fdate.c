#include"shell.h"
void Fdate(){
     struct tm *sysTime;
     time_t nowTime;
     time(&nowTime);
     sysTime=localtime(&nowTime);
     printf("%d-%d-%d %d:%d:%d\n",1900+sysTime->tm_year,sysTime->tm_mon+1,sysTime->tm_mday,sysTime->tm_hour,sysTime->tm_min,sysTime->tm_sec);
}
