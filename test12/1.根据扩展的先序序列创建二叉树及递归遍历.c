#include <stdio.h>
typedef int Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

char str[]="ABC^D^^E^^FCK^^^H^M^^";

BiTree CreatBiTree(BiTree root);//�������Ľ���
void PreOrder(BiTree root);//ǰ�����
void InOrder(BiTree root);//�������
void PostOrder(BiTree root);//�������
 
BiTree CreatBiTree(BiTree root){
	static int count;
	char ch=str[count];
	count++;
	if(ch=='^')
		return NULL;
		
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = ch;
	root->lChild = CreatBiTree(root->lChild);//�Ե�ǰ�ڵ����ָ��Ϊ��һ���������ĸ� 
	root->rChild = CreatBiTree(root->rChild);//�Ե�ǰ�ڵ����ָ��Ϊ��һ���������ĸ�	
	return root;
}

void PreOrder(BiTree root){
	int static count;
	if(root==NULL)
		return;
		
	printf("%c",root->data);
	PreOrder(root->lChild);
	PreOrder(root->rChild);
}
void InOrder(BiTree root){
	if(root==NULL)
		return;
		
	InOrder(root->lChild);
	printf("%c",root->data);
	InOrder(root->rChild);
}
void PostOrder(BiTree root){
	if(root==NULL)
		return;
		
	PostOrder(root->lChild);
	PostOrder(root->rChild);
	printf("%c",root->data);
}



int main(void){
	BiTree root;
	root=CreatBiTree(root);
	printf("ǰ�������");
	PreOrder(root); 
	
	printf("\n���������");
	InOrder(root);
	
	printf("\n�������: ");
	PostOrder(root); 
}