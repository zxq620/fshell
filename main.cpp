#include "shell.h"
#include "fyes.h"
using namespace std;
void splits(string s,string &s1,string &s2,string &s3)
{
	return 0;
}

int main()
{
	string s,s1,s2;
	while(1){
		printf("*fshell*");
		fflush(stdout);
		cin>>s;
		int l=s.length();
		if(l==0)
			continue;
		else{
			s1=s;
			/*for(int i=0;i<l;i++){
				if(s[i]==' '){
					s1=s.substr(0,i);
					s2=s.substr(i+1,l-i);
					for(int j=i+;j<l;j++){
						if(s[j]==' '){
							s2=s.substr(i+1,j-i-1);
							s3=s.sunstr(j+1,l-j);
							return 3;
						}
					}
					return 2;
				}
			}
			return 1;*/
			if(s1=="yes"/*&&s_l==1*/)
			{
				Fyes();
			}
		}
	}
}
