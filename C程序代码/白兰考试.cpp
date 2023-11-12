#include  <stdio.h>  
#define STU 30  
#define COURSE 3  
void Input(long num[],int score[][COURSE],int n);  
void GetSumAver(int score[][COURSE],int n,int sum[],float aver[]);  
void Sort(long num[],int score[][COURSE],int n,int sum[],float aver[]);  
void Print(long num[],int score[][COURSE],int n,int sum[],float aver[]);  
int  Search(long num[], int n, long x);
int main(void)  
{  
    int n, score[STU][COURSE],sum[STU],pos;  
    long num[STU],x;  
    float aver[STU];  
    printf("Please enter the total number of the students(n<=30):");  
    scanf("%d", &n);                    //输入参加考试的学生人数  
    printf("Enter No. and score as: MT  EN  PH\n");  
    Input(num, score, n);                //输入学生成绩
    GetSumAver(score, n, sum, aver);    //计算总分和平均分  
    printf("Before sort:\n");  
    Print(num, score, n, sum, aver);  
    Sort(num, score, n, sum, aver);        //排名次  
    printf("After sort:\n");  
    Print(num, score, n, sum, aver);
    printf("Please enter searching number:\n");  
    scanf("%ld", &x);                    //以长整型格式输入待查找学生的学号  
    pos = Search(num,n,x);            //信息查询  
    if (pos != -1)  
    {  
        printf("position:   %8s\t|%6s%6s%6s%7s%8s\n","  NO    ","MT","EN","PH","SUM","AVER");  
        printf("%8d    %ld\t|%6d%6d%6d%7d%8.0f\n",  
                     pos+1,num[pos],    score[pos][0],score[pos][1],  
                     score[pos][2],    sum[pos],aver[pos]);  
    }  
    else  
    {  
        printf("Not found!\n");  
    }
    return 0;  
}  
// 函数功能：输入某班学生期末考试三门课程成绩  
void Input(long num[], int score[][COURSE], int n)  
{  
    int  i, j;  
    for (i=0; i<n; i++)  
    {  
        scanf("%ld", &num[i]);  
        for (j=0; j<COURSE; j++)  
        {  
                scanf("%d", &score[i][j]);  
        }  
    }  
}
// 函数功能：计算每个学生的总分和平均分  
void GetSumAver(int score[][COURSE], int n, int sum[], float aver[])  
{  
    /************Begin************/
    for(int i=0;i<n;i++){
        sum[i]=score[i][0]+score[i][1]+score[i][2];
        aver[i]=((sum[i]*0.1)/3)*10;
    }
    
    /************End************/
}  
// 函数功能：按总分成绩由高到低排出成绩的名次  
void Sort(long num[],int score[][COURSE], int n, int sum[], float aver[])  
{  
    /************Begin************/
    long double t;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(sum[i]<sum[j]){
                t=sum[i];
                sum[i]=sum[j];
                sum[j]=t;

                t=score[i][0];
                score[i][0]=score[j][0];
                score[j][0]=t;

                t=score[i][1];
                score[i][1]=score[j][1];
                score[j][1]=t;

                t=score[i][2];
                score[i][2]=score[j][2];
                score[j][2]=t;

                t=aver[i];
                aver[i]=aver[j];
                aver[j]=t;

                t=num[i];
                num[i]=num[j];
                num[j]=t;
            }
        }
    }
    /************End************/

}   
// 函数功能：输出名次表，表格内包括学生编号、各科分数、总分和平均分  
void Print(long num[], int score[][COURSE], int n,  
            int sum[], float aver[])  
{  
    int  i, j;
    printf("%8s\t|%6s%6s%6s%7s%8s\n","  NO    ","MT","EN","PH","SUM","AVER");  
    printf("---------------------------------------------------\n");
    for (i=0; i<n; i++)  
    {  
        printf("%ld\t|", num[i]);  
        for (j=0; j<COURSE; j++)  
        {  
                printf("%6d", score[i][j]);  
        }  
        printf("%7d%8.0f\n", sum[i], aver[i]);  
    }  
}
// 函数功能：在学号数组中顺序查找学生的学号  
//           找到时，返回学生学号在学号数组中的下标位置，否则返回值-1  
/***********Begin************/
int  Search(long num[], int n, long x){
    int z;
    for(int i=0;i<n;i++){
        if(x==num[i]){
            z=i;
            break;
        }else{
            z=-1;
        }
    }
    return(z);
}
/***********End************/
