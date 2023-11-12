#include<stdio.h>
int main() {
	int n, m;
	char arr[99][99] = { 0 };
	scanf("%d%d", &n, &m);

	getchar();//输入字符时注意空格和回车,这里吃回车
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &arr[i][j]);

		}
		if (i != n - 1)
			getchar();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '?') {
				arr[i][j] = '0';
				for (int k = i - 1 ; k <= i + 1; k++) {
					for (int l = j - 1 ; l <= j + 1; l++) {
						//printf("k:%d	l:%d	arr[k][l]:%c\n",k,l,arr[k][l]);
						if (arr[k][l] == '!')
							arr[i][j]++;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", arr[i][j]);
		}
		if(i!=n-1)
		printf("\n");
	}
}
