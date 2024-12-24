#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int id;
	char name[30];
	int age;
}student;

void read_file(student **sv,int *n){
	FILE *f=fopen("students.txt","rb");
	if(f==NULL){
		printf("Can not open file!\n");
		return;
	}
	fseek(f,0,SEEK_END);
	int size=ftell(f);
	*n=size/sizeof(student);
	rewind(f);
	*sv=(student*)malloc(*n*sizeof(student));
	fread(*sv,sizeof(student),*n,f);
	fclose(f);
	printf("Read file successfully!\n");
}
void display_file(student*sv,int n){
	for(int i=0;i<n;i++){
		printf("Student %d:\n",sv[i].id);
		printf("Name: %s\n",sv[i].name);
		printf("Age:%d\n",sv[i].age);
		printf("------------------------------------\n");
	}
}
int main(){
	int n;
	student *hs;
	read_file(&hs,&n);
	display_file(hs,n);
}











