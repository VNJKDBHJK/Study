#include <stdio.h>
#include <string.h>
struct  person
{
    char name[8];
    int count;
};
int main()
{
    int i,j;
    char person_name[10];
    char name[8];
    struct  person leader[5]={"zhang",0,"sun",0,"li",0,"yang",0,"zhao",0 };
    for(i=1;i<=10;i++)
	{
		scanf("%s",&person_name);					 					 
		for(j=0;j<5;j++)
			if(person_name==leader[j].name)
	           leader[j].count+=1;
	}
    //
    printf("投票结果：\n");
    printf("姓名      票数\n");
    for(j=0;j<5;j++)
        printf("%s %d\n",leader[j].name,leader[j].count);
    return 0;
}				   	
