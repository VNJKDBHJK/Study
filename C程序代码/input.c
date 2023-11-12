#include<stdio.h>
int main() {
	int i = 0, j = 0, k = 0,l=0;
	char x;
	scanf("%c", &x);
	for (;;) {
		if(x>='0'&&x<='9') i++;
		if((x>='a'&&x<='z')||(x>='A'&&x<='Z')) j++;
		if(x==' ') k++;
		if(x='\n') break;
		else l++;
	
	}
	printf("Number of charaters in the whole variable is %d\n", i);
	printf("Number of numbers in the whole variable is %d\n", j);
	printf("Number of no in the whole variable is %d\n", k);
	printf("Number of others in the whole variable is %d\n",l);
	return 0;
}
