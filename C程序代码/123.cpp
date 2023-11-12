//P5734
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	int num;
	scanf("%d", &num);
	char start[30] = {0};
	scanf("%s", start);
	int len = strlen(start);
	for (int i = 0; i < num; i++) {
		int ope;
		scanf("%d", &ope);
		if (ope == 1) {
			char back[20] = {0};
			scanf("%s", &back);
			int len1 = strlen(back);
			for (int i = len, j = 0; i < len + len1; i++, j++) {
				start[i] = back[j];
			}
			printf("%s", start);
		}

		if (ope == 2) {
			int one, two;
			scanf("%d", &one);
			scanf("%d", &two);
			char anoo[20];
			for (int i = one,j=0; i < one + two; i++,j++) {
//				printf("%c", start[i]);
				anoo[j]=start[i];
			}
			for(int i=0;i<len;i++){
				start[i]=anoo[i];
			}
			printf("%s\n",anoo);
			printf("%s",start);
		}
		if (ope == 3) {
			int three;
			scanf("%d", &three);
			char ano[20];
			for (int i = three, j = 0; i < len; i++, j++) {
				ano[j] = start[i];
			}
			char behind[20];
			scanf("%s", &behind);
			int len2 = strlen(behind);
			for (int i = three, j = 0; i < three + len2; i++, j++) {
				start[i] = behind[j];
			}
			for (int i = three + len2, j = 0; i < len + len2; i++, j++) {
				start[i] = ano[j];
			}
			printf("%s", start);
		}
		if (ope == 4) {
			char last[20];
			scanf("%s", &last);
			int len3 = strlen(last);
			int dedede;
			int z = 0;
			for (int i = 0; i < len; i++) {
				if (start[i] == last[0]) {
					dedede = i;
					for (int j=0; i < dedede + len3; i++,j++) {
						if (start[i] != last[j]) {
							break;
						}
					}
					if(i==dedede+len3) z=1;
				}
			}
			if (z == 1) {
				printf("%d", dedede);
			} else {
				printf("-1");
			}
		}
	}
}
