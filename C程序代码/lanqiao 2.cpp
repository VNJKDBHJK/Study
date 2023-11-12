#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
int main(){
	int k;
	scanf("%d",&k);
	char s[100001];
	scanf("%s",s);
	char temp;
	scanf("%c",&temp);
	char c1,c2;
	scanf("%c",&c1);
	scanf("%c",&temp);
	scanf("%c",&c2);
	int cnt=0,cnty=0;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]==c1){
			for(int j=i;j<len;j++){
				cnt++;
				if(cnt>=4&&s[j]==c2){
					cnty++;
				} 
			}
		}
		cnt=0;
	}
	printf("%d",cnty);
}
