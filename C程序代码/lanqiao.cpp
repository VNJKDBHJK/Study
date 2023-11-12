//#include<stdio.h>
//int main(){
//	int a[100],b[100]={0};
//	for(int i=0;i<100;i++){
//		scanf("%d",&a[i]);
//	}
//	
//	for(int i=0;i<100;i++){
//		b[a[i]]++;
//	}
//	b[2]-=2;
//	b[0]-=1;
//	b[3]-=1;
//	
//	for(int i=0;i<=9;i++){
//		printf("%d ",b[i]);
//	}
//	int sum=0;
//	for(int i=1;i<=12;i++){
//		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
//			sum+=31;
//		}else if(i!=2){
//			sum+=30;
//		}else{
//			sum+=28;
//		}
//	}
//	printf("%d",sum);
//}

//#include<stdio.h>
//#include<math.h>
//int main(){
//	int a;
//	scanf("%d",&a);
//	double p;
//	double b;
//	scanf("%lf",&b);
//	-b==p*log2(p)+(1-p)*log2(1-p);
//	printf("%lf",p);
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main() {
//	int n;
//	scanf("%d", &n);
//	char b[n][n];
//	int a[n][2] = {0};
//	for (int i = 0; i < n; i++) {
//		scanf("%s", &b[i]);
//	}
//	int num = 1,i;
//	a[0][1] = b[1][0];
//	bool istrue=false;
//	for (int j = 0; j < n; j++) {
//		for (i = 0; i < num; i++) {
//			if ( b[j + 1][0] == a[i][1]) {
//				if (b[j + 1][0] == b[j][strlen(b[j]) - 1]||j+2==n) {
//					a[i][0] += 1;
//					a[i][1] = b[j+1][strlen(b[j]) - 1];
//					istrue=true;
//				}
//			}
//		}
//		i=0;
//		if (istrue==false) {
//			a[num][0] += 1;
//			a[num][1] = b[j][strlen(b[i]) - 1];
//			num++;
//		}
//		istrue=false;
//	}
//	int max = a[0][0];
//	for (int i = 0; i < num; i++) {
//		if (max < a[i][0]) {
//			max = a[i][0];
//		}
//	}
//	printf("%d", max);
//}

//C×é ÓÃÁ´±í
//#include<stdio.h>
//
//int main(){
//	int t;
//	scanf("%d",&t);
//	for(int i=0;i<t;i++){
//		int n;
//		int a[n],b[n],c[n];
//		scanf("%d",&n);
//		for(int j=0;j<n;j++){
//			scanf("%d%d%d",&a[j],&b[j],&c[j]);
//		}
//		int minb=b[0],mina;
//		for(int k=0;k<n;k++) if(minb>b[k]){minb=b[k];mina=k;}
//		int time1=c[mina]+a[mina];
//		for(int k=0;k<n;k++) if(time1<=b[k]) //true
//	}
//}
