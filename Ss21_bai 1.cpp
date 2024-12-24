#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void create_file(char *str){
	FILE *f=fopen("bt01.txt","w");
	fprintf(f,"%s",str);
	fclose(f);
}

int main(){
	printf("Enter string:");
	char str[30];
	fgets(str,30,stdin);
	str[strcspn(str,"\n")]='\0';
	create_file(str);
	return 0;
}
