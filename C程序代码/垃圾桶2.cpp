#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
	int a,b,sum;
	srand((unsigned)time(NULL));
	a=rand()%10;
	b=rand()%10;
	printf("%d+%d=",a,b);
	scanf("%d",&sum);
	if(sum==a+b) printf("Right!");
	else printf("Not corrent!");
} 
