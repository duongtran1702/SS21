#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void copy_file(const char *file_1,const char *file_2){
	FILE*src=fopen(file_1,"r");
	if(src==NULL){
		printf("File is empty or corrupted.\n");
		return;
	}
	FILE*dest=fopen(file_2,"w");
	if(dest==NULL){
		printf("File is empty or corrupted.\n");
		fclose(src);
		return;
	}
	char content[100];
	while(fgets(content,100,src)){
		fputs(content,dest);
	}
	printf("Copy file successfully.");
	fclose(dest);
	fclose(src);
}
int main (){
	copy_file("bt05.txt","bt06.txt");
	return 0;
}

