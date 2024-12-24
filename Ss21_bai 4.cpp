#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void read_file(char *str){
	FILE *f=fopen("bt01.txt","r");
	if (fgets(str,100,f)==NULL){
		printf("The file is empty or corrupted !\n");
	}
	fclose(f);
}

int main(){
	char s[100];
	read_file(s);
	printf("%s",s);
}
