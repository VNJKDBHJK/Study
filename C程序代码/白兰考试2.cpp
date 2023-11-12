#include<stdio.h>
int main(){
	char a;
	for(;;){
		a=getchar();
		if(a!=' '){
			printf("%c",a);
		}
		if(a=='.') break;
	}
}
