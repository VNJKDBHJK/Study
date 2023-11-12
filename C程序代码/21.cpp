#include <stdio.h>
#include <stdlib.h>
int main() {
	int i = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int sum = 0;
	for (i = 100; i <= 999; i++) {
		a = i / 100;
		b = i / 10 % 10;
		c = i % 10;
		sum = a * a * a + b * b * b + c * c * c;
		if (sum == i) {
			printf(" %d", i);
		}
	}
	system("pause");
	return 0;
}
