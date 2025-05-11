#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void merge_sort(int a[],int re[],int p ,int r){
	if(p>=r) return;
	int len=r-p,mid=(len/2)+p,start1=p,start2=mid+1,end1=mid,end2=r;
	
	merge_sort(a,re,start1,end1);
	merge_sort(a,re,start2,end2);
	
	int num=p;
	while(start1<=end1&&start2<=end2){
		re[num++]=a[start1]<a[start2]?a[start1++]:a[start2++];
	}
	
	while(start1<=end1){
		re[num++]=a[start1++];
	}
	
	while(start2<=end2){
		re[num++]=a[start2++];
	} 
	
	for(num=p;num<=r;num++){
		a[num]=re[num];
	}
	
} 
void merge(int a[],int length){
	int re[length];
	merge_sort(a,re,0,length-1);
}
int main(){
	int a[10];
	int i=0;
	while(i<10){
		scanf("%d",&a[i]);
		i++;
	}
	merge(a,i);
	while(i>=0){
		//TODO
		printf("%d",a[i]);
		i--;
	}
} 
