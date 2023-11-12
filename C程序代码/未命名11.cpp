#include<stdio.h>
#include<math.h>
int main() {
	int a[500];
	for (int i = 0;; i++) {
		char ch = getchar();
		a[i] = ch;
		if (a[i] == 'E') break;
	}
	if(a[0]=='E') printf("0:0\n\n0:0");
	int cnt = 0, cntt = 0;
	for (int i = 0; a[i] != 'E'; i++) {
		if (a[i] == 'W') cnt++;
		if (a[i] == 'L') cntt++;
		if (abs(cnt-cntt)>=2&&cnt + cntt >= 11) {
			printf("%d:%d\n", cnt, cntt);
			cnt = 0;
			cntt = 0;
		}
	}
	if (cnt != 0 || cntt != 0) printf("%d:%d\n", cnt, cntt);
	printf("\n");
	cnt = 0;
	cntt = 0;
	for (int i = 0; a[i] != 'E'; i++) {
		if (a[i] == 'W') cnt++;
		if (a[i] == 'L') cntt++;
		if (abs(cnt-cntt)>=2&&cnt + cntt == 21) {
			printf("%d:%d\n", cnt, cntt);
			cnt = 0;
			cntt = 0;
		}
	}
	if (cnt != 0 || cntt != 0) printf("%d:%d", cnt, cntt);
}
