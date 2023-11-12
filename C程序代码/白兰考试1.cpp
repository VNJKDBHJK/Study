#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
void swap(double* a,double* b){
    double z=*a;
    *a=*b;
    *b=z;
}
void inputData(double* p,int N){
    for(int i=0;i<N;i++){
        scanf("lf",&(*(p+i)));
    }
}
void sortData(double* p,int N,int mode){
    if(mode==0){
        for(int i=0;i<N-1;i++){
            for(int j=0;j<N-1-i;j++){
                if(*(p+j)>*(p+j+1))
                swap(p+j,p+j+1);
            }
        }
    }
    else{
        for(int i=0;i<N-1;i++){
            for(int j=0;j<N-1-i;j++){
                if(*(p+j)<*(p+j+1))
                swap(p+j,p+j+1);
            }
        }
    }
}
void outputData(double* p,int N){
    for(int i=0;i<N;i++){
        printf("%.2lf",*(p+i));
    }
}
int main()
{
//mode:排序方式，为0表示升序，非0表示降序
    int N,mode;
    int k;
    double data[MAXNUM];
    //输入
    scanf("%d%d",&N,&mode);
    inputData(data,N);
    //排序
    sortData(data,N,mode);
    //显示排序结果
    outputData(data,N);
    return 0;
}
