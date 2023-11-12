#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct node
{
    DataType info;
    struct node *next;
}queuedata;
 
typedef struct queuerecord{
    queuedata *front, *rear ;
}linkqueue;
typedef struct node *pqueuedata;
typedef struct queuerecord *plinkqueue;
 
plinkqueue createqueue( )
{
    plinkqueue p=(plinkqueue)malloc(sizeof(linkqueue));
    p->front=NULL;
    p->rear=NULL;
 
}
 
int emptyequeue(plinkqueue q)
{
    plinkqueue p;
    p=q;
    if(p->front==NULL)
        return 1;
    else
        return 0;
 
 
}
 
void pushqueue(DataType x, plinkqueue q)
{
    pqueuedata p=(pqueuedata)malloc(sizeof(struct node));
    if(q->front==NULL&&q->rear==NULL)
    {
        q->front=p;
        q->rear=p;
    }
    p->info=x;
    p->next=NULL;
    q->rear->next=p;
    q->rear=q->rear->next;
 
 
}
 
 
DataType popqueue(plinkqueue q)
{
    pqueuedata p=q->front;
    DataType temp=q->front->info;
    q->front=q->front->next;
    free(p);
    return temp;
 
}
 
struct node1{
    DataType element;
    struct node1 *next;
};
 
typedef struct node1 *PtrToNode;
typedef struct node1 * stack;
 
 
int emptystack(stack s)
{
 
    if(s->element==0&&s->next==NULL)
        return 1;
    else
        return 0;
 
 
}
stack createStack(void)
{
 
    stack top=(stack)malloc(sizeof(struct node1));
    top->element=0;
    top->next=NULL;
    return top;
 
 
}
 
 
void pushstack(DataType  x,stack s)
{
 
    stack temp=(struct node1 *)malloc(sizeof(struct node1));
    temp->element=x;
    temp->next=s->next;
    s->next=temp;
 
 
}
DataType popstack(stack s)
{
 
    if(emptystack(s))
        return -1;
    else
    {
        stack node=s->next;
        int tmp;
        tmp=node->element;
        s->next=node->next;
        free(node);
 
        return tmp;
 
    }
 
}
 
int palindrome(char src[])
{
    plinkqueue p1=createqueue();
    stack p2=createStack();
    int i=0;
    int j=0;
    while(src[i]!='\0')
    {
        pushqueue(src[i], p1);
        i++;
    }
    while(src[j]!='\0')
    {
        pushstack(src[j],p2);
        j++;
    }
    while(emptyequeue(p1)!=1)
    {
        DataType x1=popqueue(p1);
        DataType x2=popstack(p2);
        if(x1!=x2)
            return 0;
    }
    return 1;
}
 
int main(void)
{
 
    char a[100]={'0'};
    scanf("%s",a);
 
    int res=palindrome(a);
    if(res==1)
        printf("yes");
    else
        printf("no");
 
 
 
 
    return 0;
}
