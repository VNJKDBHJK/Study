#include<stdio.h>
int main(){
	char s[20],s1[20];
	int j=0;
	scanf("%s",s);
	for(int i=0;s[i]!='\0';i++){
		if(i%2==1||s[i]%2==0){
			s1[j]=s[i];
			j++;
		}
	}
	for(int i=0;i<j;i++){
		printf("%c",s1[i]);
	}
}
