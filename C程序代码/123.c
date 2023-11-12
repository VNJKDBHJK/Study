//#include<stdio.h>
//int main() {
//	return 0;
//}
//#include<stdio.h >
//int main(){
//	int i,n;
//	for(n=1;n<=4;n++){
//		for(i=4-n;i>0;i--){printf(" ");}
//		if(n%2==1){printf("********");}
//		if(n%2==0){printf("*******");}
//		printf("\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//int main (){
//	int a[100][100],n,i,j,linesum,columnsum,diasum,oppdiasum;
//	srand ((unsigned int) time (0));
//	scanf("%d",&n);
//	for(i=0;i<=n;i++){
//		for(j=0;j<=n;j++){
//			a[i][j]=rand()%(n*n);
//	    }
//	}
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++){
//			if(a[i][j]==a[i-1][j-1]){break;}
//		}
//	}
//	for(;;){
//		for(i=0,j=0;j<=n;j++){linesum+=a[i][j];}
//		for(i=0,j=0;i<=n;i++){columnsum+=a[i][j];}
//		for(i=0,j=0;i<=n;i++){
//			if(i==j){diasum+=a[i][j];}
//		}
//		for(i=0,j=0;i<=n;i++){
//			if(i+j==n){oppdiasum+=a[i][j];}
//		}
//		if(linesum==columnsum&&linesum==diasum&&diasum==oppdiasum)break;
//	    for(i=0;i<=n;i++){
//			for(j=0;j<=n;j++){
//				 printf("%d\t",a[i][j]);
//		    }
//	    }
//	    for(i=0;i<=n;i++){
//			for(j=0;j<=n;j++){
//				if(j==n){printf("\n");}
//			}
//		}
//    }
//}
//#include<stdio.h>
//int main(){
//	int x,y;
//	for(x=1;x<=3;x++){
//        for(y=(x-1)*2;y<=4&&y>=1;y--){
//            printf(" ");
//        }
//        printf("*****\n");
//    }
//    return 0;
//
//
//}
//#include<stdio.h>
//int main(){
//	int x,y;
//	for(x=0;x<3;x++){
//		printf(" ");
//        printf("*****\n");
//	}return 0;
//
//
//}
//#include <stdio.h>
//int main(){
//	int i,j;
//	for(i=1;i<=5;i++){printf(" ");}
//	for(i=5;i<=27;i++){
//		if(j<=30){
//			if(j<=32-3*i){
//				printf(" ");
//			}
//			else printf("*");
//			if(j<=45-3*i&&j>=41-3*i){
//				printf(" ");
//			}
//			else printf("*");
//		}
//		if(j<=34){
//			if(i<=14){printf(" ");}
//		}
//		else printf("*");
//		if(j<=59){
//			if(j<=53-3*i){
//				printf(" ");
//			}
//			else printf(" ");
//			if(j<=74-3*i&&j>=62-3*i){
//				printf(" ");
//			}
//			else printf("*");
//
//		}
//	}
//}
//#include<stdio.h>
//#include<string.h>
//int main(){
//  char str[100];
//  gets(str);
//  int a=strlen(str);
//  for(int i=0;i<a;i++){
//  if(str[i]>='a'&&str[i]<='z'){
//    str[i]=str[i]-32;}
//  }
//  puts(str);
//}
//#include<stdio.h>
//int main(){
//  int n,i;
//  scanf("%d",&n);
//  if(n>=0&&n<=1024){
//    for(i=2;i<=n;i++){
//      if(n%i==0) break;}
//    if(i==n) printf("True");
//    else printf("False");}
//  else printf("输入不合题意");}
//#include<stdio.h>
//#include<string.h>
//int main(){
//  char a[10000];
//  gets(a);
//  int b=strlen(a);
//  for(int i=b-1;i>=0;i--){
//    printf("%c",a[i]);}
//}

//#include<stdio.h>
//int main (){
//  long int n,N;
//  long long mul=1;
//  scanf("%ld",&N);
//  for(n=1;n<=N;n++){
//    mul*=n;}
//  printf("%lld",mul);
//  return 0;}

//#include<stdio.h>
//int main(){
//  int a[10],n,i,j,sum;
//  scanf("%d%d",&n,&sum);
//  for(i=0;i<n;i++){
//    scanf("%d",&a[i]);}
//  for(i=0;i<n;i++){
//    for(j=i+1;j<n;j++){
//      if(sum==a[i]+a[j]) printf("%d %d",i,j);}}
//  return 0;}
//
//#include<stdio.h>
//int main(){
//	int n,m,l,N,M,L,t;
//	int a[10][10],b[10][10],c[10][10];
//	scanf("%d%d%d",&n,&m,&l);
//	for(N=0;N<n;N++){
//		for(M=0;M<m;M++){
//			scanf("%d",&a[N][M]);
//		}
//	}
//	for(M=0;M<m;M++){
//		for(L=0;L<l;L++){
//			scanf("%d",&b[M][L]);
//		}
//	}
//	for(N=0;N<n;N++){
//		for(L=0;L<l;L++){
//			c[N][L]=0;
//			for(t=0;t<m;t++){
//				c[N][L]+=a[N][t]*b[t][L];
//			}
//		}
//	}
//	for(N=0;N<n;N++){
//		for(L=0;L<l;L++){
//			printf("%d ",c[N][L]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int main(){
//	int a=0,x,y,l,m;
//	scanf("%d",&m);
//	for(x=0;x<=(m/20);x++){
//		for(y=0;y<=(m/5);y++){
//			for(l=0;l<=m;l++){
//				if(m==x*20+y*5+l) a++;
//			}
//		}
//	}printf("%d",a);
//	return 0;
//	}
//#include<stdio.h>
//int main (){
//  float x,ReLu;
//  float max(float a,float b);
//  scanf("%f",&x);
//  ReLu=max(0,x);
//  printf("%g",ReLu);
//    return 0;}
//  float max(float a,float b){
//  	float max;
//  	max=a>b?a:b;
//	  return (max);}
//#include<stdio.h>
//int main (){
//	float max(float x,float y);
//	float a,ReLu;
//	scanf("%f",&a);
//	ReLu=max(0,a);
//	printf("%g",ReLu);
//	return 0;
//}
//float max(float x,float y){
//	float max;
//	max=x>y?x:y;
//	return (max);
//}
// #include<stdio.h>
// #include<math.h>
// int main(){
// 	int x,sum=0;
// 	int a=0;
// 	scanf("%d",&x);
// 	a=abs(x);
// 	for(;a>0;a/=10){
//	 	sum=sum*10+a%10;
//	 }
//	 if(x>0) printf("%d",sum);
//	 else printf("%d",-sum);
//	 return 0;
// }
//#include<stdio.h>
//int main (){
//	int n,N,i,t,min=0,max=0,x=0;
//	int a[20];
//	scanf("%d",&n);
//	for(N=0;N<n;N++){
//		scanf("%d",&a[N]);}//输入
//    for(i=0;i<n;i++){
//		if(a[i]>a[max]) max=i;
//		if(a[i]<a[min]) min=i;
//	}
//	t=a[max];
//	a[max]=a[min];
//	a[min]=t; //调换
//    printf("0 ");
//    for(i=1;i<n;i++){
//    	x=0;
//		for(t=0;t<i;){
//			if(a[i]>a[t]) x+=1;
//			t++;
//		}
//		printf("%d ",x);
//	}//判断+输出
//	return 0;
//}
//排序
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main(){
//	int i,j,t,z=1;
//	char c[20];
//	gets(c);
//	int m= strlen (c);
//	for(i=0;i<m;i++){
//		for(j=i+1;j<m;j++){
//			if(c[i]>c[j]){
//			t=c[i];
//			c[i]=c[j];
//			c[j]=t;}//排序
//		}
//	}
//	for(i=0;i<m;i++){
//		z=1;
//		if(c[i]==c[i+1]){
//			for(;;i++){
//				if(c[i]!=c[i+1]) break;
//				z++;
//			}
//		}
//		printf("%c:%d\n",c[i],z);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main (){
//	int i,n,sum=0;
//	scanf("%d",&n);
//	for(i=1;i<=n;i++){
//		sum+=i;
//		if(i>=7){
//		if(i%7==0) sum-=5;}
//	}
//	printf("%d",sum);
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main(){
//	char c[5][5],i,j,sum[5],s[5],a,t;
//	gets(c);
//	for(i=0;i<5;i++){
//		for(j=0;j<5;j++){
//			scanf("%c",&c[i][j]);
//		}
//	}
//	for(t=0;t<5;t++){
//		sum[t]=c[2][t]-c[1][t];
//	}
//	char s1[5]={"d" "h" " "};
//	char s2[5]={"y" "z" "x" " "};
//	char s3[5]={"l" "c" "x" " "};
//	char s4[5]={"h" "l" "h" " "};
//	char s5[5]={"g" "y" "y" " "};
//	strcat (s1,sum[0]);
//	strcat (s2,sum[1]);
//	strcat (s3,sum[2]);
//	strcat (s4,sum[3]);
//	strcat (s5,sum[4]);
//	for(t=1;t<=5;t++){
//		if(sum[t-1]<sum[t]){
//			a=st;
//
//		}
//	}

//}

//#include <stdio.h>
//int main(){
//	float N,M,sum=0;
//	int n,t;
//	scanf("%d",&n);
//	for(N=1.00,M=2.00,t=1;t<=n;t++){
//		sum+=M/N;
//		M=M+N;
//		N=M-N;
//	}
//	printf("%.2f",sum);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main() {
//	int t;
//	char c[20];
//	gets(c);
//	int a = strlen(c);
//	if (a % 2 == 0) {
//		for (t = 0; t <= (a / 2) - 1; t++) {
//			if (c[(a / 2) - 1 - t] == c[(a / 2) + t]) ;
//			else {
//				printf("0");
//				break;
//			}
//		}
//		if(t==(a/2)) printf("1");
//	}
////	printf("1");
//
//if (a % 2 == 1) {
//	for (t = 0; t <= (a - 1) / 2; t++) {
//		if (c[((a - 1) / 2) - t] == c[((a - 1) / 2) + t]);
//		else {
//			printf("0");
//			break;
//		}
//	}if(t==((a-1)/2)+1) printf("1");
//}
//}

//#include<stdio.h>
//int main(){
//	int a,b=0,sum=0,i,N;
//	scanf("%d",&a);
//	scanf("%d",&N);
//	for(i=1;i<=N;i++){
//		b=10*b+a;
//		sum+=b;
//	}
//	printf("%d",sum);
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main(){
//	char c[100];
//	char i;
//	int z=0,t;
//	gets(c);
//	int a=strlen(c);
//	for(i='a';i<='z';i++){
//		for(t=0;t<a;t++){
//			if(c[t]==i){
//				z++;
//				break;
//			}
//		}
//	}
//	if(z%2==0) printf("CHAT WITH HER!");
//	if(z%2==1) printf("IGNORE HIM!");
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int n,i,su;
//	float sum;
//	scanf("%d",&n);
//	sum=n*10*0.85;
//	su=n*10;
//	for(i=1;i<=n;i++){
//		if(i%6==0){
//			su-=10;
//		}
//	}
//	if(sum<su) printf("1");
//	if(su<sum) printf("2");
//	if(su==sum) printf("12");
//	return 0;
//
//
//}

//#include<stdio.h>
//int main(){
//	int n=10000,a,z=90000;
//	for(;n<=99999&&n>=10000;n++){
//		a=n;
//		a=(a/10)%10;
//		if(a==4) z--;
//	}
//	printf("%d",z);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main(){
//	char c[300];
//	int i,z=0;
//	while((scanf("%c",&c[i]))!=EOF){
//		if(c[i]==' '){
//			z++;
//		}
//		if(c[i]=='\n'){
//				z++;
//		}
//	}
//	int b=strlen(c);
//	for(i=0;i<b;i++){
//		if(c[i]==' '){
//			z++;
//		}
//		if(c[i]=='\n'){
//			z-=3;
//		}
//	}
//	if(z<120) printf("TOO FEW WORDS");
//	if(z>=120&&z<=180) printf("JUST ALRIGHT");
//	if(z>180) printf("TOO MANY WORDS");
//	return 0;
//
//}

//#include<stdio.h>
//int main() {
//	int year, month, day, sum, i;
//	scanf("%d%d%d", &year, &month, &day);
//	if (month == 1) {
//		sum = day;
//		printf("%d", sum);
//	} else {
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//			if (month == 2) {
//				sum = 31 + day;
//				printf("%d", sum);
//			} else sum = 60;
//		else {
//			if (month == 2) {
//				sum = 31 + day;
//				printf("%d", sum);
//			} else sum = 59;
//		}
//		if (month <= 7 && month > 2) { //改动
//			for (i = 3; i < month; i++) {
//				if (i % 2 == 1) {
//					sum += 31;
//				}
//				if (i % 2 == 0) {
//					sum += 30;
//
//				}
//			}
//			sum += day;
//			printf("%d", sum);
//		} else {
//			if (month > 7) {
//				sum += 153;
//				for (i = 1; i < month - 7; i++) {
//					if (i % 2 == 1) {
//						sum += 31;
//					}
//					if (i % 2 == 0) {
//						sum += 30;
//					}
//				}
//				sum += day;
//				printf("%d", sum);
//			}
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int main(){
//	int a,b,n;
//	scanf("%d",&n);
//	a=n%7;
//	b=7-a;
//	if(b==1||b==7) printf("ohhhhh");
//	else{
//		a=6-a;
//		printf("还有%d天才到周末pwp",a);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int n,i,sum;
//	for(n=1;n<10000;n++){
//		sum=0;
//		for(i=1;i<n;i++){
//			if(n%i==0) sum+=i;
////			if(sum==n) printf("%d ",n);
//		}if(sum==n) printf("%d ",n);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main(){
//	char a[100];
//	char b[200];
//	gets(a);
//	int len;
//	len=strlen(a);
//	for(int i=len-1;i>0;i--){
//		if(a[i]!=){
//			//TODO
//		}
//		if(a[i]=='A'||a[i]=='a'||a[i]=='O'||a[i]=='o'||a[i]=='E'||a[i]=='e'||a[i]=='I'||a[i]=='i'||a[i]=='U'||a[i]=='u'){
//
//		}
//	}
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main() {
//	char c[5][8] = {{"dh "}, {"yzx "}, {"lcx "}, {"hlh "}, {"gyy "}};
//	int a[5][2];
//	int i, j;
//	int sum[5], s1[10], s2[10], su[10];
//	for (i = 0; i < 5; i++) {
//		for (j = 0; j < 2; j++) {
//			scanf("%d", &a[i][j]);
//		}
//	}
//	for (i = 0; i < 5; i++) {
//		sum[i] = a[i][1] - a[i][0];
//	}
//	for (i = 0; i < 5; i++) {
//		for (j = i + 1; j < 5; j++) {
//			if (sum[i] < sum[j]) {
//				su[10] = sum[i];
//				sum[i] = sum[j];
//				sum[j] = su[10]; //换数字
//				strcpy(s1, c[i]);
//				strcpy(s2, c[j]);
//				strcpy(c[i],s2);
//				strcpy(c[j],s1);
//			}
//		}
//	}
//
//	for (i = 0; i < 5; i++) {
//		for(j=0;j<5;j++){
//			if(c[i][j] < 32 ) {
//
//				continue ;
//			}
//			printf("%c",c[i][j]);
//		}
//		printf("%d\n",sum[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main() {
//	int num[5], nu[50];
//	char s1[30];
//	int n,j=0;
//	scanf("%d", &n);
//	char a[5][20];
//	for ( int i = 0; i < n; i++) {
//		int z = 0;
//		j=0;
//		for (;; j++) {
//			//printf("%s", a[i]);
//			a[i][j] = getchar();
//			if (a[i][j] == ' ') {
//				z++;
//			}
//			if (z == 2) break;
//			//printf("%d",j);
//		}
//		scanf("%d", &num[i]);
//	}
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (num[i] < num[j]) {
////				strcpy(nu, num[i]);
////				strcpy(num[i], num[j]);
////				strcpy(num[j], nu);
//				nu[50]=num[i];
//				num[i]=num[j];
//				num[j]=nu[50];
//				strcpy(s1, a[i]);
//				strcpy(a[i], a[j]);
//				strcpy(a[j], s1);
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				printf("%c", a[i][j]);
//			}printf("\n");
//		}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("%c", a[i][j]);
//		}
//		printf(" %d", num[i]);
//		printf("\n");
//	}
//	return 0;
//}
//少了j的范围，getchar不仅可以容纳空格还可以容纳换行，注意输出格式及循环对应的范围
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// int main()
// {
// 	int len;
// 	int num[50], nu[500];
// 	char s1[300];
// 	int n,j=0;
// 	scanf("%d", &n);
// //	getchar();
// 	char a[50][200];
// 	for ( int i = 0; i < n; i++)
// 	{
// 		int z = 0;
// 		j=0;
// 		for (;; j++)
// 		{   a[i][j] = getchar();
// 			if (a[i][j] == ' ')
// 			{
// 				z++;
// 			}
// 			if (z == 2) break;
// 		}
// 		scanf("%d", &num[i]);
// //		getchar();
// 	}
//
//// 		for(j=0;j<i;j++)
//// 	{
//// 		scanf("%s", &name[j]);
//// 		scanf("%d", &number[j]);
//// 		scanf("%d", &time[j]);
//// 	}
//
// 	for (int i = 0; i < n - 1; i++)
// 	{
// 		for (int j = i + 1; j < n; j++)
// 		{
// 			if (num[i] < num[j])
// 			{
// 				nu[50]=num[i];
// 				num[i]=num[j];
// 				num[j]=nu[50];
// 				strcpy(s1, a[i]);
// 				strcpy(a[i], a[j]);
// 				strcpy(a[j], s1);
// 			}
// 		}
// 	}
//
// 	for (int i = 0; i < n; i++)
// 	{
// 		len = strlen(a[i]);
// 		for (int j = 0; j < len; j++)
// 		{
//     	if(a[i][j] != '\n')
// 			printf("%c", a[i][j]);
// 		}
// 		printf("%d\n", num[i]);
//// 		if(i != n-1)
//// 		{
//// 		printf("\n");
//// 		}
////
//}
// 	return 0;
// }
//

//#include <stdio.h>
//#include <string.h>
//int main(){
// char a[10000];
// char b[10000];
// int count=0;
// gets(a);
// int oldlen=strlen(a);
// for(int i=oldlen-1;i>0;i--){
//  if(a[i]==' '){
//   count++;
//  }
// }
// int newlen=oldlen+count*2;
// int i,j;
// for(i=oldlen-1,j=newlen-1;j>=0;){
//  if(a[i]!=' '){
//   b[j]=a[i];
//   i--;
//   j--;
//  }
//  else{
//   b[j--]='0';
//   b[j--]='2';
//   b[j--]='%';
//   i--;
//  }
// }
// for(int i=0;i<newlen;i++){
//  printf("%c",b[i]);
// }
//}

//#include<stdio.h>
//int m;
//int main(){
//	int judge(int x);
//	int n;
//	int judg( int n);
//	scanf("%d",&n);
//	m=judg(n);
//	if(m==1) printf("%d is prime number",n);
//	if(m==0) printf("%d is not the prime number",n);
//	return 0;
//}
//int judge(int x){
//	int i;
//	for(i=2;i<x;i++){
//		if(x%i!=0) printf(" ");
//	}
//	if(i==x) m=1;
//	else m=0;
//
//	return (m);
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//void replace(char str1[]){
//	int i,j=0;
//	char str2[100];
//	for(i=0;str1[i]!='\0';i++)	{
//		if(str1[i]!=' ' ) str2[j++]=str1[i];
//	    else {
//		str2[j++]='%';
//		str2[j++]='2';
//		str2[j++]='0';}}
//		str2[j]='\0';
//		strcpy(str1,str2);}
//int main(){
//	char str[100];
//	fgets(str,100,stdin);
//	replace(str);
//	printf("%s",str);
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	char c;
//	for(c=0;;){
//	c=getchar();
//	if(c==' ') printf("%%20");
//	else printf("%c",c);
//	if(c=='\n') break;}
//	return 0;
//
//}
//#include<stdio.h>
//int main() {
//	int max(int a, int b);
//	int x, y, m;
//	scanf("%d%d", &x, &y);
//	m = max(x, y);
//	printf("%d", m);
//}
//int max(int a, int b) {
//	int m;
//	if (a > b) m = a;
//	else m = b;
//	return (m);
//}

//#include <stdio.h>
//#include <string.h>
//int main() {
// char a[3][3];
// int sumx = 0;
// int sumo = 0;
// for (int i = 0; i < 3; i++) {
//  int j = 0;
//  while ((a[i][j] = getchar()) != '\n') {
//   if (a[i][j] == 'X') {
//    sumx++;
//   }
//   if (a[i][j] == 'O') {
//    sumo++;
//   }
//   j++;
//  }
// }
// if (sumx == sumo) { //为x
//  for (int i = 0; i < 3; i++) {
//   for (int j = 0; j < 3; j++) {
//    if (a[i][j] == 'X') {
//     a[i][j] = 1;
//    }
//    if (a[i][j] == 'O') {
//     a[i][j] = -1;
//    }
//    if (a[i][j] == ' ') {
//     a[i][j] = 0;
//    }
//   }
//  }
// } else {
//  for (int i = 0; i < 3; i++) {
//   for (int j = 0; j < 3; j++) {
//    if (a[i][j] == 'O') {
//     a[i][j] = 1;
//    }
//    if (a[i][j] == 'X') {
//     a[i][j] = -1;
//    }
//    if (a[i][j] == ' ') {
//     a[i][j] = 0;
//    }
//   }
//  }
// }
// int row[3] = {0};
// int column[3] = {0};
// for (int i = 0; i < 3; i++) {
//  for (int j = 0; j < 3; j++) {
//   row[i] += a[i][j];
//  }
// }
// for (int j = 0; j < 3; j++) {
//  for (int i = 0; i < 3; i++) {
//   column[j] += a[i][j];
//  }
// }
// for (int i = 0; i < 3; i++) {
//  if (row[i] == 2 || column[i] == 2) {
//   printf("True");
//   break;
//  }
//  if (a[0][0] + a[1][1] + a[2][2] == 2 || a[0][2] + a[1][1] + a[2][0] == 2) {
//   printf("True");
//   break;
//  }
//  if(i==2){
//   printf("False");
//  }
// }
//}
//

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main() {
//	char c[100], d[100], a[200], b[200] ;
//	int i;
//	scanf("%s", c);
//	scanf("%s", d);
//	int j, t = 0;
//	int c1 = strlen(c);
//	int d1 = strlen(d);
//	for (i = 0, j = c1 - 1; i < c1; i++, j--) {
//		a[j] = c[i];
//	}
//	for (i = 0, j = d1 - 1; i < d1; i++, j--) {
//		b[j] = d[i];
//	}
//	int sum = 0, s = 0, max, min;
//	if (c1 > d1) {
//		max = c1;
//		min = d1;
//	} else {
//		max = d1;
//		min = c1;
//	}
//	t = 0;
//	for (i = 0; i < min; i++) {
//		sum = 0;
//		sum = a[i] - '0' + b[i] - '0';
//		sum += t;
//		s = sum % 10;
//		t = (sum - s) / 10;
//		a[i] = s;
//	}
//	int a1=c1;
//	int b1=d1;
//	if (sum >= 10) {
//		if (c1 == d1) a[min] = sum / 10;
//		if (c1 > d1) a[min] = a[min] - '0' + 1;
//		else a[min]=a[min]-'0';
//		if (c1 < d1) a[min] = b[min] - '0' + 1;
//		else a[min]=a[min]-'0';
//	}
//	else a[min]=a[min]-'0';
//	if (a1 == b1) {//判断大数与小数交接是否进位
//		if (sum >= 10) {
//			a[min] = sum / 10;
//		}
//	}
//	if (a1 > b1) {
//		if (sum >= 10) {
//			a[min] = a[min] - '0' + 1;
//		} else a[min] = a[min] - '0';
//	}
//	if (a1 < b1) {
//		if (sum >= 10) {
//			a[min] = b[min] - '0' + 1;
//		} else a[min] = b[min] - '0';
//	}
//	for (i = min + 1; i < max; i++) {
//		if (c1 > d1) a[i] = a[i] - '0';
//		if (c1 < d1) a[i] = b[i] - '0';
//	}
//	if(a1==b1&&sum>=10) {a[max]=1;
//	for (i = max; i >= 0; i--) {
//		printf("%d", a[i]);
//	}}
//	else {
//		for(i=max-1;i>=0;i--){
//			printf("%d",a[i]);
//		}
//	}
//
//	return 0;
//}
//#include<stdio.h>
//int main(){
//	char a;
//	for(;;){
//		a=getchar();
//		if(a=='\n') break;
//		if(a=='A'||a=='E'||a=='I'||a=='O'||a=='U'||a=='a'||a=='e'||a=='i'||a=='o'||a=='u') continue;
//		else {
//			if(a>'A'&&a<='Z') {
//				a+=32;
//				printf(".%c",a);
//			}
//			if(a>'a'&&a<='z') printf(".%c",a);
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main(){
//	char a;
//	for(;;){
//		a=getchar();
//		if(a=='\n'||a==EOF) {break;}
//		if(a=='A'||a=='E'||a=='I'||a=='O'||a=='U'||a=='a'||a=='e'||a=='i'||a=='o'||a=='u') {continue;}
//		else {
//			if(a>'A'&&a<='Z') {
//				a+=32;
//				printf(".%c",a);
//			}
//			else printf(".%c",a);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int i,j,max;
//	int a[5][2],sum[5];
//	for(i=0;i<5;i++){
//		for(j=0;j<2;j++){
//			scanf("%d",&a[i][j]);
//		}
//	}
//	for(i=0;i<5;i++){
//		sum[i]=a[i][1]-a[i][0];printf("%d\n",sum[i]);
//	}
//	for(i=0;i<5;i++){
//		for(j=i+1;;){
//			if(sum[i]>sum[j]) j++;
//			else
//			j++;
//		}
//		if(j==5){
//			if(max==0) printf("dh %d",sum[0]);
//			if(max==1) printf("yzx %d",sum[1]);
//			if(max==2) printf("lcx %d",sum[2]);
//			if(max==3) printf("hlh %d",sum[3]);
//			if(max==4) printf("gyy %d",sum[4]);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//#include<string.h>
//int main() {
//	signed int n;
//	int y, z, i, x;
//	scanf("%d", &n);
//	scanf("%d", &y);
//	scanf("%d", &z);
//	x = abs(n);
//	int a[32], o[32];
//	for(i=0;i<32;i++){
//		o[i]=0;
//	}
//	int c = x;
//	long long int sum = 0;
//	long long int b;
//	for (i = 32; i > 0;) {
//		i--;
//		b = pow(2, i);
//		if (c - b >= 0) a[i] = 1;
//		else a[i] = 0;
//		if (x < b) c = x;
//		else {
//			if (c > b) c = c - b;
//		}
//	}
//	for (i = 32; i >= 0; i--) {
//		if (a[i] == 1) break;
//	}
//	int h;
//	h = i + 1;
//	if (n != 0) {
//		if (n < 0) {
//			if (a[0] == 1) {
//				o[0] = 1;
//				for (i = 1; i < h; i++) {
//					if (a[i] == 1) o[i] = 0;
//					if (a[i] == 0) o[i] = 1;
//				}
//			} else {
//				for (i = 0; i < h; i++) {
//					if (a[i] == 1) o[i] = 0;
//					if (a[i] == 0) o[i] = 1;
//				}
//				for (i = 0; i < h; i++) {
//					if (o[i] != 0) o[i] = 1;
//					else {
//						o[i] = 1;
//						break;
//					}
//				}
//			}
//			o[y]=z;for(i=0;i<32;i++){printf("%d ",o[i]);}
//			for (i = 0; i < 32; i++) {
//				b = pow(2, i);
//				sum += o[i] * b;
//			}
//		}
////	for (int i = 0; i < 10; i++) {
////		printf("%d", a[i]);
////	}
////	for (int i = 0; i < 10; i++) {
////		printf("%d", a[i]);
////	}
//		else {
//			a[y] = z;//for(i=0;i<32;i++){printf("%d ",a[i]);}
//			for (i = 0; i < 32; i++) {
//				b = pow(2, i);
//				sum += a[i] * b;
//			}
//		}
//	}
//	if (n == 0) sum = 0;
//	printf("%lld", sum);
//}
//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//#include<string.h>
//int main() {
//	signed int n;
//	int y, z, i, x;
//	scanf("%d", &n);
//	scanf("%d", &y);
//	scanf("%d", &z);
//	x = abs(n);
//	int a[32], o[32];
//	for(i=0;i<32;i++){
//		o[i]=0;
//	}
//	int c = x;
//	long long int sum = 0;
//	long long int b;
//	for (i = 32; i > 0;) {
//		i--;
//		b = pow(2, i);
//		if (c - b >= 0) a[i] = 1;
//		else a[i] = 0;
//		if (x < b) c = x;
//		else {
//			if (c > b) c = c - b;
//		}
//	}
//	for (i = 32; i >= 0; i--) {
//		if (a[i] == 1) break;
//	}
//	int h;
//	h = i + 1;
//	if (n != 0) {
//		if (n < 0) {
//			if (a[0] == 1) {
//				o[0] = 1;
//				for (i = 1; i < h; i++) {
//					if (a[i] == 1) o[i] = 0;
//					if (a[i] == 0) o[i] = 1;
//				}
//			} else {
//				for (i = 0; i < h; i++) {
//					if (a[i] == 1) o[i] = 0;
//					if (a[i] == 0) o[i] = 1;
//				}
//				for (i = 0; i < h; i++) {
//					if (o[i] != 0) o[i] = 1;
//					else {
//						o[i] = 1;
//						break;
//					}
//				}
//			}
//			o[y]=z;for(i=0;i<32;i++){printf("%d ",o[i]);}
//			for (i = 0; i < 32; i++) {
//				b = pow(2, i);
//				sum += o[i] * b;
//			}
//		}
////	for (int i = 0; i < 10; i++) {
////		printf("%d", a[i]);
////	}
////	for (int i = 0; i < 10; i++) {
////		printf("%d", a[i]);
////	}
//		else {
//			a[y] = z;//for(i=0;i<32;i++){printf("%d ",a[i]);}
//			for (i = 0; i < 32; i++) {
//				b = pow(2, i);
//				sum += a[i] * b;
//			}
//		}
//	}
//	if (n == 0) sum = 0;
//	printf("%lld", sum);
//}
//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//#include<string.h>
//int main() {
//	signed int n;
//	int y, z, i, x;
//	scanf("%d", &n);
//	scanf("%d", &y);
//	scanf("%d", &z);
//	x = abs(n);
//	int a[32], o[32];
//	for(i=0;i<32;i++){
//		o[i]=0;
//	}
//	int c = x;
//	long long int sum = 0;
//	long long int b;
//	for (i = 32; i > 0;) {
//		i--;
//		b = pow(2, i);
//		if (c - b >= 0) a[i] = 1;
//		else a[i] = 0;
//		if (x < b) c = x;
//		else {
//			if (c > b) c = c - b;
//		}
//	}printf("\n");for(i=0;i<32;i++){printf("%d",a[i]);}printf("\n");
//	if(x%2==1) a[0]=1;
//	else a[0]=0;printf("\n");for(i=0;i<32;i++){printf("%d",a[i]);}printf("\n");
//	for (i = 32; i >= 0; i--) {
//		if (a[i] == 1) break;
//	}//for(i=0;i<32;i++) {printf("%d",a[i]);}
//	int h;
//	h = i + 1;printf("%d\n",h);
//	if (n != 0) {
//		if (n < 0) {
//			if (a[0] == 1) {
//				o[0] = 1;//printf("\n");for(i=0;i<32;i++){printf("%d",a[i]);}printf("\n");
//				for (i = 1; i < h; i++) {
//					if (a[i] == 1) o[i] = 0;
//					if (a[i] == 0) o[i] = 1;
//				}for(i=0;i<32;i++) {printf("%d",o[i]);}
//			}
//			else {
//				for (i = 0; i < h; i++) {
//					if (a[i] == 1) o[i] = 0;
//					if (a[i] == 0) o[i] = 1;
//				}printf("\n");for(i=0;i<32;i++){printf("%d",o[i]);}printf("\n");
//				for (i = 0; i < h; i++) {
//					if (o[i] != 0) o[i] = 0;
//					else {
//						o[i] = 1;
//						break;
//					}
//				}for(i=0;i<32;i++) {printf("%d",o[i]);}
//			}//printf("\n");for(i=0;i<32;i++){printf("%d",o[i]);}printf("\n");
//			o[y]=z;//printf("\n");for(i=0;i<32;i++){printf("%d",o[i]);}printf("\n");
//			for (i = 0; i < 32; i++) {
//				b = pow(2, i);
//				sum += o[i] * b;
//			}
//		}
////	for (int i = 0; i < 10; i++) {
////		printf("%d", a[i]);
////	}
////	for (int i = 0; i < 10; i++) {
////		printf("%d", a[i]);
////	}
//		else {
//			a[y] = z;for(i=0;i<32;i++){printf("%d ",a[i]);}
//			for (i = 0; i < 32; i++) {
//				b = pow(2, i);
//				sum += a[i] * b;
//			}
//		}
//	}
//	if (n == 0) sum = 0;
//	printf("%lld", sum);
//	return 0;
//}
//#include  <stdio.h>
//int main()
//{
//	char c1,c2;
//	printf("Input a upper letter: ");
//	scanf("%c",&c1);
//	if((c1>='A'&&c1<='Z')||(c1>='a'&&c1<='z'))
//	{
//		c2 = c1+32;
//		if(c1>='a' && c1<='u')
//			printf("Input error!");
//		else
//            c2+=5;
//
//		printf("The letter %c change to %c",c1,c2);
//	}
//	else
//    {
//        printf("\nInput error!");
//    }
//
//	return 0;
//}
// #include  <stdio.h>
// int main()
// {
// 	char c1,c2;
// 	printf("Input a upper letter: ");
// 	scanf("%c",&c1);
// 	if((c1>='A'&&c1<='Z')||(c1>='a'&&c1<='z'))
// 	{
// 		c2 = c1+32;
//         if(c1>='a' && c1<='u'){
//             printf("\n");
// 			printf("Input error!");}
//         else {
//             if(c2>='v'&&c2<='z') c2-=21;
//             else c2+=5;
//             printf("\n");
// 		    printf("The letter %c change to %c",c1,c2);}
//
//     }
// 	else
//     {
//           printf("\n");
//         printf("Input error!");
//     }
//
// 	return 0;
// }
//

//#include <stdio.h>
//int main(void)
//{
//	float  h, w, t;
//	printf("Please enter h,w:");
//	scanf("%f, %f", &h, &w);
//	/*********begin**********/
//    t=w/(h*h);
//    printf("\n");
//    if(t<25){
//       if(t<18) printf("t=%f\tLower weight!",t);
//       else printf("t=%f\tStandard weight!",t);
//    }
//    else {
//        if(t<27) printf("t=%f\tHigher weight!",t);
//        else printf("t=%f\tToo fat!",t);
//    }
//	/**********end***********/
//	return 0;
//}

//#include <stdlib.h>
//#include <math.h>
//#include <stdio.h>
//#define  EPS  1e-6
//
//int main()
//{
//    float a,b,c,disc,p,q;
//    printf("Please enter a,b,c:");
//    scanf("%f,%f,%f",&a,&b,&c);
//    if(fabs(a)<=EPS)
//    {
//        printf("\nIt is not a quadratic equation!\n");
//        exit(0);
//    }
//    else{
//        disc = b*b-4*a*c;
//        p=-b/(2*a);
//        q=(sqrt(b*b-4*a*c))/(2*a);
//        if(disc>=0){
//            if(disc>0){
//               printf("\nTwo unequal real roots: ");
//               printf("x1=%f,x2=%f",p+q,p-q);
//               }
//            else {
//                printf("x1=x2=%f",p+q);
//                printf("\nTwo equal real roots: ");
//                }
//        }
//        else printf("\nx1=%f+%fi,x2=%f-%fi",p,q,p,q);}
//    /*********************End*******************/
//    return 0;
//}

//#include <stdlib.h>
//#include <math.h>
//#include <stdio.h>
//#define  EPS  1e-6
//
//int main() {
//	float a, b, c, disc, p, q;
//	printf("Please enter a,b,c:");
//	scanf("%f,%f,%f", &a, &b, &c);
//	if (fabs(a) <= EPS) {
//		printf("\nIt is not a quadratic equation!\n");
//		exit(0);
//	} else {
//		disc = b * b - 4 * a * c;
//		int l = sqrt(disc);
//		p = (-b*0.1)/ (2 * a*0.1);
//		q = (l) / (2 * a);
//		if (disc >= 0) {
//			if (disc > 0) {
//				printf("\nTwo unequal real roots: ");
//				printf("x1=%.2f,x2=%.2f", p + q, p - q);
//			} else {
//				printf("\nTwo equal real roots: ");
//				printf("x1=x2=%.2f", p + q);
//			}
//		} else {
//			disc = -disc;
//			l=sqrt(disc);
//			p = (-b*0.1) / (2 * a*0.1);
//			q = (l*0.1) / (2 * a*0.1);
//			printf("\nTwo complex roots: ");
//			printf("x1=%.2f+%.2fi,x2=%.2f-%.2fi", p, q, p, q);
//		}
//	}
//	/*********************End*******************/
//	return 0;
//}
//
//

//#include <stdio.h>
//#include <stdlib.h>
//
//int main( ) {
//	int a, b, c, min;
//	/********************Begin******************/
//	printf("Input a,b,c:");
//	scanf("%d,%d,%d", &a, &b, &c);
//	if (a > b) {
//		if (b > c) min = c;
//		else min = b;
//	} else {
//		if (a > c) min = c;
//		else min = a;
//	}
//	/********************End********************/
//	printf ("\nthe min number is:%d\n", min);
//	return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//    int x;
//    printf("Please input score:");
//    scanf("%d", &x);
//
//    printf("\n");
//
//    /********************Begin***************************/
//    if(x<=100){
//        if(x>=70) {
//        if(x<80) printf("\n%d--Average",x) ;
//        else{
//            if(x<90) printf("\n%d--Good",x);
//            else printf("\n%d--Excellent",x);
//        }
//    }
//    else{
//        if(x>=60) printf("\n%d--Poor",x);
//        else{
//            if(x>=0) printf("\n%d--Failing",x);
//            else printf("\n%d--Input error",x);
//        }
//    }}
//    else printf("\n%d--Input error",x);
//
//
//
//
//
//    /********************End*****************************/
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//    int score, mark;
//    printf("Please input score:");
//    scanf("%d", &score);
//    printf("\n");
//
//    /********************Begin***************************/
//    mark=score/10;
//
//	switch(mark)
//	{
//		case 6:
//			printf("%d--Poor\n",score);break;
//		case 7:
//			printf("%d--Average\n",score);break;
//		case 8:
//			printf("%d--Good\n",score);break;
//		case 9:
//			printf("%d--Excellent\n",score);break;
//		case 10:
//			printf("%d--Excellent\n",score);break;
//		case 0: case 1:
//		case 2: case 3:
//		case 4: case 5:
//			printf("%d--Failing\n",score);break;
//		default:
//			printf("Input error!");break;
//	}
//    /********************End*****************************/
//    return 0;
//}

//#include<stdio.h>
//int main(){
//	char a;
//	a=100;
//	int b=a/10;
//	printf("%d\n",b);
//	printf("%d",a);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main(){
//	int a,b,c,t;
//	scanf("%d%d%d",&a,&b,&c);
//	for(int i='a';i<'c';i++){
//		if(a>b){
//			t=a;
//			a=b;
//			b=t;}
//		}
//	}
//	if((a+b>c)&&(b-a<c)&&(c-b<a)&&(c-a<b)) s=1;
//
//}
//#include<stdio.h>
//int main() {
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	int i, j, t, m;
//	for (i = 'a'; i < 'c'; i++) {
//		for (j = i + 1; j < 'd'; j++) {
//			if (i > j) {
//				t = i;
//				i = j;
//				j = t;
//			}
//		}
//	}
//	int s = 0;
//	if ((a + b > c) && (c - a < b) && (c - b < a) && (b - a < c)) s = 1;
//	if (s==0) printf("Not triangle");
//	else {
//		m = a * a + b * b - c * c;
//		if (m == 0) printf("Right triangle\n");
//		if (m > 0) printf("Acute triangle\n");
//		if (m < 0) printf("Obtuse triangle\n");
//		if (a == b || b == c || a == c) printf("Isosceles triangle\n");
//		if (a == b && b == c) printf("Equailateral triangle\n");
//	}
//}

#include<stdio.h>
int main(){
	int t,i,j,M,N,sum,D;
	int a[100][100],b[100]={0};
	scanf("%d%d",&N,&M);
	for(i=0;i<M;i++){
		for(j=0;j<=1;j++){
			scanf("%d",&a[i][j]);
		}
	}//输入区域范围二维数组 
	for(i=0;i<M;i++){for(j=0;j<2;j++){printf("%d ",a[i][j]);}}
	for(i=0;i<100;i++){
		t=a[i][1];
		for(;t>=a[i][0];t-=1){
			b[t]=t;//printf("%d=%d",b[t],t);
		}
	}//将所有包含在M区间内的整数点的该位数组元素为该位整数点数字 
	printf("111%d111",b[0]);
	for(i=0;i<100;i++){printf("%d",b[i]);}
	for(i=0;i<M;i++){
		sum+=a[i][1]-a[i][0];
	}//将区域范围内所有整数点之和累加(求平均值) 
	for(D=sum/(N-1);D>0;D--){
		if(b[D]==D) printf("%d",D);
	}
	return 0;
}
