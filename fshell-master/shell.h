#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <dirent.h>
#include <iostream>
#include <sys/wait.h>
#include <termios.h>
const int MAX_CMD=10000;
//int Fyes(int argc, char **argv);
void Fdate();
int Fcal();
void Fman();
int Fmv(int argc,char **argv);
int Fmkdir(int argc, char **argv );
int Fls(int argc,char**argv);
int Fcat(int argc, char **argv);
int Frm(int argc, char **argv);
int Fcp(int argc, char **argv );
ino_t get_inode(char*);
void printpathto(ino_t);
void inum_to_name(ino_t,char*,int);
int Fpwd();

