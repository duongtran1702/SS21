#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE *f=fopen("bt01.txt","r");
	if(f==NULL){
		printf("Cannot open file!\n");
		return 0;
	}
	char s=fgetc(f);
	printf("The first character :%c",s);
	fclose(f);
	return 0;
}
