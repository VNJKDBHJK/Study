#include <iostream>
using namespace std;
typedef char DataType;

//��������㶨��
struct node {
	DataType data; //��Ž������
	struct node *lchild, *rchild ; //���Һ���ָ��
};
typedef struct  node  BiTree;
typedef struct  node  *ptree;



//������ֱ��ʹ�ã����ܣ�����������
void print(BiTree *T) {
	cout<< T->data ;
}


/*
��������createBiTree
�������ܣ�������������Ҫ��������������ȸ�������(�������뷽ʽ�뿴���˵��)����������Ӧ�������������ض������ĸ����ָ��
��������
����ֵ���������ĸ����ָ��
*/

BiTree *createBiTree() {
//���ڴ˴���д���룬��ɴ��������������ض����������ָ��Ĺ���
	/*-------begin--------*/
	char ch;
	ptree T;
	cin >> ch;
	if (ch == '#') T=NULL;
	else {
		T = new struct node;
		T->data = ch;
		T->lchild = createBiTree();
		T->rchild = createBiTree();
	}
	return T;
	/*-------end--------*/
}

/*
��������preOrder
�������ܣ��ȸ�����������
�����������������ָ��
����ֵ����
*/
void preOrder(BiTree *T) {
//���ڴ˴���д���룬����ȸ���������������
	/*-------begin--------*/
	if (T == NULL) return;
	printf("%c",T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
	/*-------end--------*/
}

/*
�������� inOrder
�������ܣ��и�����������
�����������������ָ��
����ֵ����
*/
void inOrder(BiTree *T) {
	//���ڴ˴���д���룬����и���������������
	/*-------begin--------*/
	if (T == NULL) return;
	inOrder(T->lchild);
	printf("%c",T->data);
	inOrder(T->rchild);
	/*-------end--------*/
}

/*
��������postOrder
�������ܣ��������������
�����������������ָ��
����ֵ����
*/
void postOrder(BiTree *T) {
	//���ڴ˴���д���룬��ɺ����������������
	/*-------begin--------*/
	if (T == NULL) return;
	postOrder(T->lchild);
	postOrder(T->rchild);
	printf("%c",T->data);
	/*-------end--------*/
}



int main(void) {
	BiTree    *T;
	T =  createBiTree(   ); //���ô������������ܣ��õ��������ĸ����ָ��


	preOrder(  T );//�����ȸ����������������ȸ�����˳�������������㹦��
	cout << endl; //����
	inOrder(T);//�����и����������������и�����˳�������������㹦��
	cout << endl;
	postOrder(T);//���ú�����������������������˳�������������㹦��

	return 0;
}
