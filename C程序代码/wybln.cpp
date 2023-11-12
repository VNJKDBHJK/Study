//#include<stdio.h>
//int main() {
//	int n = 2730;
//	int a[100000];
//	int j;
//	for (j = n;; j++) {
//		int i,k,num=j;
//		for (i = 0; num!= 0; i++) {
//			a[i] = num % 16;
//			num /= 16;
//		}
//		for(k=i-1;;k--){
//			if(a[k]<10||a[k]>15||k==0) break;
//		}
//		if(k==0) break;
//	}
//	printf("%d",j);
//}
//2730
//#include<stdio.h>
//int main(){
//	int n=2022;
//	int i,a[4];
//	for(i=0;n!=0;i++){
//		a[i]=n%26;
//		n/=26;
//	}
//	printf("%d",i);
//}
//TYB
//#include<stdio.h>
//int main() {
//	int year = 1900, month = 1, day = 1,cnt=0,cnyear=0,i=0;
//	int a[4];
//	for (;year<=1902; year++) {
//		for(cnyear=year;i<4;i++){
//			a[i]=cnyear%10;
//			cnyear/=10;
//		}
//		for (; month <= 12; month++) {
//			if (month % 2 == 0 && month != 2) {
//				day = 30;
//			} else if (month == 2) {
//				//判断闰年
//				if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
//					day = 28;
//				} else day = 29;
//			} else day = 31;
//			for(;day!=0;day--){
//				if(a[0]+a[1]+a[2]+a[3]==month+day) cnt++;
//			}
//		}
//	}
//	printf("%d",cnt);
//}
//#include<stdio.h>
//int s[30] = {99, 22, 51, 63, 72, 61, 20, 88, 40, 21, 63, 30, 11, 18, 99, 12, 93, 16, 7, 53, 64, 9, 28, 84, 34, 96, 52, 82, 51, 77};
//void quick_sort(int l, int r) {
//	if (l < r) {
//		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
//		int i = l, j = r, x = s[l];
//		while (i < j) {
//			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
//				j--;
//			if (i < j)
//				s[i++] = s[j];
//
//			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
//				i++;
//			if (i < j)
//				s[j--] = s[i];
//		}
//		s[i] = x;
//		quick_sort(l, i - 1); // 递归调用
//		quick_sort(i + 1, r);
//	}
//}
//int main() {
//	quick_sort(0,29);
//	int cnt=0;
//	for(int i=0;i<29;i++){
//		for(int j=i;j<30;j++){
//			if(s[j]*s[i]>=2022){
//				cnt+=29-j;
//				break;
//			}
//		}
//	}
//	printf("%d",cnt);
//}
//183
//#include<stdio.h>
//int main(){
//	int w;
//	scanf("%d",&w);
//	long int n;
//	scanf("%ld",&n);
//	n=n%7;
//	printf("%d",(w+n)%7);
//}
//#include<stdio.h>
//#include<math.h>
//int main(){
//	int w,h;
//	scanf("%d%d",&w,&h);
//	int a[w+1][h+1]={0};
//	int n,r;
//	scanf("%d%d",&n,&r);
//	for(int i=0;i<n;i++){
//		int x,y;
//		scanf("%d%d",&x,&y);
//		for(int m=w;m>=0;m--){
//			for(int n=h;n>=0;n--){
//				if(sqrt((x-m)*(x-m)+(y-n)*(y-n))<=r){
//					a[m][n]=1;
//				}
//			}
//		}
//	}
//	int cnt=0;
//	for(int i=0;i<=w;i++){
//		for(int j=0;j<=h;j++){
//			if(a[i][j]==1) cnt++;
//		}
//	}
//	printf("%d",cnt);
//}
//#include<stdio.h>
//int main(){
//	int n,m;
//	scanf("%d%d",&n,&m);
//	int a[n][m]={1};
//	int t;
//	scanf("%d",&t);
//	for(int i=0;i<t;i++){
//		int x,y,m,n;
//		scanf("%d%d%d%d",&x,&y,&m,&n);
//		for(int j=0;j<m;j++){
//			for(int k=0;k<n;k++){
//				if((j<m&&j>=x)&&(k<n&&k>=y)) a[j][k]=0;
//			}
//		}
//	}
//	int cnt=0;
//	for(int i=m-1;i>=0;i--){
//		for(int j=n-1;j>=0;j--){
//			if(a[i][j]==0) cnt++;
//		}
//	}
//	printf("%d",cnt);
//}
