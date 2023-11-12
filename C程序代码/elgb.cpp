#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[100];
int main() {
	scanf("%s", a);
	for (int i = 0; i < strlen(a); i++) {
		a[i] = a[i] - 5;
		if (a[i] <'@') a[i] += 27;
		if (a[i] == '@') a[i] = ' ';
		printf("%c", a[i]);
	}
}
