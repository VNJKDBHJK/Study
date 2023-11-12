#include<string.h>
#include<stdio.h>
#include<math.h> 
int main(){
	/*定义*/
	int x;//转换数的进制
	char a[101]={0};//x进制数
	int y;//转换后的进制
	
	/*输入*/ 
	scanf("%d",&x);
    scanf("%s",a);
    scanf("%d",&y);
    
    /*将x进制转化为十进制*/
    int len=strlen(a);
    int sum=0;//十进制数 
    for(int i=len-1;i>=0;i--){
		if(a[i]>57) a[i]-=55;
		else a[i]-=48;
		sum+=(a[i])*pow(x,len-1-i);//pow(x,y)x的y次幂 
		a[i]=0;
	}
	
	/*将十进制转化为y进制存储到数组中*/
	int cnt;
	for(int i=0;sum!=0;i++){
		if(sum%y>=10) a[i]=sum%y+55;
		else a[i]=sum%y;
		sum/=y;
		cnt=i;
	} 
	
	/*输出*/
	for(int i=cnt;i>=0;i--)
		if(a[i]>=10) printf("%c",a[i]);
		else printf("%d",a[i]);
}
