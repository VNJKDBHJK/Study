#include<string.h>
#include<stdio.h>
#include<math.h> 
int main(){
	/*����*/
	int x;//ת�����Ľ���
	char a[101]={0};//x������
	int y;//ת����Ľ���
	
	/*����*/ 
	scanf("%d",&x);
    scanf("%s",a);
    scanf("%d",&y);
    
    /*��x����ת��Ϊʮ����*/
    int len=strlen(a);
    int sum=0;//ʮ������ 
    for(int i=len-1;i>=0;i--){
		if(a[i]>57) a[i]-=55;
		else a[i]-=48;
		sum+=(a[i])*pow(x,len-1-i);//pow(x,y)x��y���� 
		a[i]=0;
	}
	
	/*��ʮ����ת��Ϊy���ƴ洢��������*/
	int cnt;
	for(int i=0;sum!=0;i++){
		if(sum%y>=10) a[i]=sum%y+55;
		else a[i]=sum%y;
		sum/=y;
		cnt=i;
	} 
	
	/*���*/
	for(int i=cnt;i>=0;i--)
		if(a[i]>=10) printf("%c",a[i]);
		else printf("%d",a[i]);
}
