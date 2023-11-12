#include<stdio.h>
#include<stdlib.h>
typedef struct men {
	int dre;
	char name[10];
} Men;
typedef struct chg {
	int drr;
	int num;
} Chg;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Men man[n];
	for (int i = 0; i < n; i++) {
		scanf("%d%s", &man[i].dre, &man[i].name);
	}
	Chg chh[m];
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &chh[i].drr, &chh[i].num);
	}
	int nm = 0;
	for (int i = 0; i < m; i++) {
		if ((chh[i].drr == 0 && man[nm].dre == 0) || (chh[i].drr == 1 && man[nm].dre == 1)) {
			if (nm <= 0) nm+=n-chh[i].num;
			else nm -= chh[i].num;
		} else {
			if (nm + chh[i].num > n - 1){
				for(;nm + chh[i].num > n - 1;){ nm += chh[i].num - n;}
			}
			else nm += chh[i].num;
		}
		if(nm<0) nm=n+nm;
		printf("%d %s\n",nm,man[nm].name);
	}
	printf("%s", man[nm].name);
}
