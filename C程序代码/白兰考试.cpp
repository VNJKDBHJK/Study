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
    scanf("%d", &n);                    //����μӿ��Ե�ѧ������  
    printf("Enter No. and score as: MT  EN  PH\n");  
    Input(num, score, n);                //����ѧ���ɼ�
    GetSumAver(score, n, sum, aver);    //�����ֺܷ�ƽ����  
    printf("Before sort:\n");  
    Print(num, score, n, sum, aver);  
    Sort(num, score, n, sum, aver);        //������  
    printf("After sort:\n");  
    Print(num, score, n, sum, aver);
    printf("Please enter searching number:\n");  
    scanf("%ld", &x);                    //�Գ����͸�ʽ���������ѧ����ѧ��  
    pos = Search(num,n,x);            //��Ϣ��ѯ  
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
// �������ܣ�����ĳ��ѧ����ĩ�������ſγ̳ɼ�  
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
// �������ܣ�����ÿ��ѧ�����ֺܷ�ƽ����  
void GetSumAver(int score[][COURSE], int n, int sum[], float aver[])  
{  
    /************Begin************/
    for(int i=0;i<n;i++){
        sum[i]=score[i][0]+score[i][1]+score[i][2];
        aver[i]=((sum[i]*0.1)/3)*10;
    }
    
    /************End************/
}  
// �������ܣ����ֳܷɼ��ɸߵ����ų��ɼ�������  
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
// �������ܣ�������α�����ڰ���ѧ����š����Ʒ������ֺܷ�ƽ����  
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
// �������ܣ���ѧ��������˳�����ѧ����ѧ��  
//           �ҵ�ʱ������ѧ��ѧ����ѧ�������е��±�λ�ã����򷵻�ֵ-1  
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
