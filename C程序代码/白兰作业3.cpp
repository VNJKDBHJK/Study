#include<stdio.h>
#include<string.h> 
void swap(char *a,char *b)
{
    char temp[8];
    int i;
    for (i=0;i<8;i++)
    temp[i]='\0';
    /*int length=strlen(a),lengths=strlen(b);*/
    for (i=0;i<9;i++)
    {
        temp[i]=a[i];
        if (a[i]=='\0')
        break;
    }
    for (i=0;i<9;i++)
    {
        a[i]=b[i];
        if (b[i]=='\0')
        break;
    }
    for (i=0;i<9;i++)
    {
        b[i]=temp[i];
        if (temp[i]=='\0')
        break;
    }
 }
int main()
{
    char cArray[9][8];
    int i;
    printf("ÅÅÐòÇ°µÄ×Ö·û´®£º\n");
    for (i=0;i<9;i++)
    {
        scanf("%s",&cArray[i]);
        printf("%s\n",cArray[i]);
    }
    for (i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (strcmp(cArray[j],cArray[j+1])>0)
            {
                swap((cArray[j]),(cArray[j+1]));
            }
        }
    }
    printf("ÅÅÐòºóµÄ×Ö·û´®£º\n");
    for (i=0;i<9;i++)
    printf("%s\n",cArray[i]);
    return 0;
}
