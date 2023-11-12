#include<stdio.h>
#include<string.h>
int main(){
	char a[100];
	gets(a);
	printf("The original string: \n");
	printf("%s",a);
	printf("\n");
	printf("The string after deleted: \n");
	for(int i=0;i<strlen(a);i++){
		if(a[i]!='c'){
			printf("%c",a[i]);
		}
	}printf("\n");
}
