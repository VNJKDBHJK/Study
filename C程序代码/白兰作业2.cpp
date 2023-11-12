#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int N,a[100];
	char s[100][100];
	scanf("%d",&N);
	char temp;
	scanf("%c",&temp);
	for(int i=0;i<N;i++){
		gets(s[i]);
		a[i]=strlen(s[i]);
	}
	int max=a[0],num=0;
	for(int i=1;i<N;i++){
		if(max<a[i]){
			max=a[i];
			num=i;
		}
	}
	puts(s[num]);
}
