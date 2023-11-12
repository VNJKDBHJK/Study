#include<stdio.h>
 #include<math.h>
 int mian(){
 	int x,b,sum,t;
 	scanf("%d",&x);
 	int a=abs(x);
 	for(t=100;t>0;t/=10){
	 	b=a%10;
	 	a/=10;
	 	sum+=b*t;
	 }
	 if(x>0) printf("%d",sum);
	 else printf("%d",-sum);
	 return 0;
 }
