#include <iostream>
using namespace std;

typedef char DataType;

//���������ݽṹ 
struct node
{
	DataType info ; //��Ž������ 
	struct node *lchild , *rchild ; //ָ�����Һ��ӵ�ָ�� 
};

typedef struct node *BiTree ;

/*����������
  ��������createBiTree
  ��������
  ����ֵ�������������ָ��
  */
BiTree createBiTree(void)
{
	char ch ;
	BiTree  root ;
	cin>>ch ;
	if(ch == '#') root = NULL;
	else{
        root = new struct node ;
        root->info = ch ;
        root->lchild = createBiTree() ;
        root->rchild = createBiTree();
	}
	return root ;
}

void changeLR(BiTree root)
{
	//���ڴ˴���д���룬 ��ɶ����������������� 
    /********** Begin **********/
    if(!root) return;
    else{
		BiTree change=root->lchild;
		root->lchild=root->rchild;
		root->rchild=chaange
	}
    
    
    /********** End **********/
}

void visit(BiTree T) //������T������
{
	cout<<T->info ;
}

void inOrder(BiTree root)
{
	if(root == NULL) return ;
	inOrder(root->lchild);
	visit(root);
	inOrder(root->rchild);
}

int main(void)
{
	BiTree root = createBiTree();
    changeLR(root);
	inOrder(root);
}
