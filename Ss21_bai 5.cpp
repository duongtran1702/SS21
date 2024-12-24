#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void write_to_file(int n){
	FILE*f=fopen("bt05.txt","w");
	char content[100];
	for(int i=0;i<n;i++){
		printf("Enter content:");
		fgets(content,100,stdin);
		fprintf(f,"%s",content);
	}
	fclose(f);
}

int main(){
	int n;
	printf("Enter the number of lines:");
	scanf("%d",&n);
	getchar();
	write_to_file(n);
}
