#include<stdio.h>
int main(){
	int sum=0,s=1;
//	for(int n=1;n<=3;n+=1){
//		for(int i=0;n>i;i++){
//			s=n*i;sum=sum+s;
//		}
//		//printf("1");
//		}
for(int i=1;i<=20;i++){
	//TODO
	s=s*i;
	sum=sum+s;
}
		printf("%d\n",sum);
		return 0;
}
