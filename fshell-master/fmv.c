#include"shell.h"
/*int Fmv(int argc, char **argv ){
	FILE * source = fopen(argv[1],"r");
	if(source==NULL){
		printf("file no exsit!\n");
		return 0;
	}else{
 		char *path=Fpwd();
		strcat(path,"/");
		strcat(path,argv[1]);
		struct stat * statbuf=(struct stat *)malloc(sizeof(statbuf));
		stat(argv[2], statbuf); //�ж�Ŀ��·����һ����ͨ�ļ�����һ��Ŀ¼
		if(S_ISDIR (statbuf->st_mode)){//Ŀ���Ǹ�Ŀ¼
			int i,j,k=0;//��ΪĿ��·����һ��Ŀ¼������Ĭ�Ͽ���һ����Դ�ļ�����һ��������
			//Ҫ�ҵ�Դ�ļ������֣���Ҫ��Դ·�����һ��'/'������ַ�������Դ�ļ�������
			for(i=strlen(argv[1])-1;i>=0;i--){
				if(argv[1][i]=='/'){
					break; //�ҵ����˳� ������'/'�±�Ϊi
				}
			}
			char source_file_name[10000]={};//�����洢Դ�ļ�������
			for(j=i+1;j<strlen(argv[1]);j++){//��Դ·�����һ��'/'������ַ�����source_file_name,������Դ�ļ�����
				source_file_name[k++]=argv[1][j];
			}
			//���Ŀ��·�������û�С�/��������Ҫ��һ��'/'
			if(argv[2][strlen(argv[2])-1]!='/'){
				strcat (argv[2],"/");
			}
			remove(argv[1]);
			//remove(path);  //ɾ��Դ�ļ�
			//��Ŀ��·����Դ�ļ���ƴ����������Ϊһ��Ŀ���ļ���������������
			FILE * target = fopen(strcat (argv[2],source_file_name),"w+");
			while(!feof(source)){//��Դ�ļ�����ȫ������Ŀ���ļ�
				char c;
				fread(&c,1,1,source);
				fwrite(&c,1,1,target);
			}
			printf("mv successfully!\n");
   			//if(target!=NULL)
				//fclose(target);
			return 0;
		}
		else{//Ŀ��·���Ǹ��ļ�
			FILE * target = fopen(argv[2],"w+");
				while(!feof(source)){
					char c;
					fread(&c,1,1,source);
					fwrite(&c,1,1,target);
					//fputc(fgetc(source),target);
				}
				//if(target!=NULL)
					//fclose(target);
				remove(argv[1]);  //ɾ��Դ�ļ�
				printf("mv successfully!\n");
				return 0;
		}

	}
	fclose(source);
}*/
int Fmv(int argc, char **argv ){
	FILE * source = fopen(argv[1],"r");
	if(source==NULL){
		printf("file no exsit!\n");
		return 0;
	}
	else{
		struct stat * statbuf=(struct stat *)malloc(sizeof(statbuf));
		stat(argv[2], statbuf); //�ж�Ŀ��·����һ����ͨ�ļ�����һ��Ŀ¼
		if(S_ISDIR (statbuf->st_mode)){//Ŀ���Ǹ�Ŀ¼
			int i,j,k=0;//��ΪĿ��·����һ���ļ��У�����Ĭ�Ͽ���һ����Դ�ļ�����һ��������
			//Ҫ�ҵ�Դ�ļ������֣���Ҫ��Դ·�����һ��'/'������ַ�������Դ�ļ�������
			for(i=strlen(argv[1])-1;i>=0;i--){
				if(argv[1][i]=='/'){
						break; //�ҵ����˳� ������'/'�±�Ϊi
				}
			}
			char source_file_name[100000]={};//�����洢Դ�ļ�������
			for(j=i+1;j<strlen(argv[1]);j++){
			//��Դ·�����һ��'/'������ַ�����source_file_name,������Դ�ļ�����
				source_file_name[k++]=argv[1][j];
			}
			//���Ŀ��·�������û�С�/��������Ҫ��һ��'/'
			if(argv[2][strlen(argv[2])-1]!='/'){
					strcat (argv[2],"/");
			}
			
			//��Ŀ��·����Դ�ļ���ƴ����������Ϊһ��Ŀ���ļ���������������
			FILE * target = fopen(strcat (argv[2],source_file_name),"w+");
			while(!feof(source)){	//��Դ�ļ�����ȫ������Ŀ���ļ�
				char c;
				fread(&c,1,1,source);
				fwrite(&c,1,1,target);
			}
			remove(argv[1]);  //ɾ��Դ�ļ�
			printf("mv successfully!\n");
			fclose (target);
			return 0;
		}else{//Ŀ��·���Ǹ��ļ�
			FILE * target = fopen(argv[2],"w+");
				while(!feof(source)){
					char c;
					fread(&c,1,1,source);
					fwrite(&c,1,1,target);
					//fputc(fgetc(source),target);
				}
				
				remove(argv[1]);  //ɾ��Դ�ļ�
				printf("mv successfully!\n");
				fclose (target);
				return 0;
		}
	}
	fclose (source);

}