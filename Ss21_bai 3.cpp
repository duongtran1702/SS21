#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Add_to_file(char *str){
	FILE *f=fopen("bt01.txt","a");
	fprintf(f,"%s",str);
	fclose(f);
}

int main(){
	printf("Enter string:");
	char str[30];
	fgets(str,30,stdin);
	//str[strcspn(str,"\n")]='\0';
	Add_to_file(str);
	return 0;
}