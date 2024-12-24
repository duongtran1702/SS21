#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	int id;
	char name[30];
	int age;
}student;

void format_1st(char *name){
	size_t len=strlen(name);
	int i=0;
	int j=0;
	int find_space=0;
	while(isspace(name[i])) i+=1;
	for(;i<len;i++){
		if(!isspace(name[i])){
			name[j++]=name[i];
			find_space=0;
		}
		else if(find_space==0){
			name[j++]=' ';
			find_space=1;
		}
	}
	if(j>0&&name[j-1]==' '){
		j-=1;
	}
	name[j]='\0';
}
void format_2nd(char *name){
	size_t len=strlen(name);
	int new_word=1;
	for(int i=0;i<len;i++){
		if(isspace(*(name+i))){
			new_word=1;
		}
		else if(new_word==1){
			*(name+i)=toupper(*(name+i));
			new_word=0;
		}
		else{
			*(name+i)=tolower(*(name+i));
		}
	}
}
void create_list(student **hs,int *n){
	printf("Enter the number of students:");
	scanf("%d",n);
	getchar();
	if(*n<1){
		printf("Invalid number of student!\n");
		return;
	}
	*hs=(student*)calloc(*n,sizeof(student));
	if(*hs==NULL){
		printf("Memory allocated failed!\n");
		exit(1);
	}
	for(int i=0;i<*n;i++){
		(*hs)[i].id=i+1001;
		printf("Student %d:\n",(*hs)[i].id);
		printf("Enter the name of student:");
		fgets((*hs)[i].name,30,stdin);
		(*hs)[i].name[strcspn((*hs)[i].name,"\n")]='\0';
		format_1st((*hs)[i].name);
		format_2nd((*hs)[i].name);
		printf("Enter age of student:");
		scanf("%d",&(*hs)[i].age);
		getchar();
		printf("\n");
	}	
}



void create_student_file(student *hs,int n){
	FILE *f=fopen("students.txt","wb");
	if(f==NULL){
		printf("Can not open file!\n");
		return;
	}
	fwrite(hs,sizeof(student),n,f);
	fclose(f);
	printf("File is written successfully!\n");
}

int main(){
	int n;
	student *hs;
	create_list(&hs,&n);
	create_student_file(hs,n);
}













