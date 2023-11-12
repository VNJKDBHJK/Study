//#include<stdio.h>
//int main (){
//	int n,t;
//	scanf("%d",&n);
//	for(t=2;t<=5;t++){
//		while(n) {  
//		if(n%t==0) n=n/t; 
//		else break; }}
//		if(n==1)printf("ÊÇ\n");
//		else printf("²»ÊÇ\n");	
//		return 0;
//	
//}
#include<stdio.h>
int main (){
	int t,x;
	char c,str[500];
    for(x=0;x<=500;x++){
		scanf(" %c ",str[x]);
	}
	scanf("%c",&c);
	for(t=1;t<=500;){
		if(str[t]==c){
			t++;
		}
	}
	printf("%d",t);
	return 0;
}
