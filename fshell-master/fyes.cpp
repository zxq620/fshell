#include"shell.h"
int kbhit(void)  
{  
struct termios oldt, newt;  
int ch;  
int oldf;  
tcgetattr(STDIN_FILENO, &oldt);  
newt = oldt;  
newt.c_lflag &= ~(ICANON | ECHO);  
tcsetattr(STDIN_FILENO, TCSANOW, &newt);  
oldf = fcntl(STDIN_FILENO, F_GETFL, 0);  
fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); 
ch = getchar();  
tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  
fcntl(STDIN_FILENO, F_SETFL, oldf);  
if(ch == 'q'){
printf("\n");
return 1;  
}
}  

int Fyes(int argc, char **argv){
    while(1)

{
printf("yes\n");
sleep(1);

       if(kbhit())

      {
		return 0;

       }

}
    return 0;
}

