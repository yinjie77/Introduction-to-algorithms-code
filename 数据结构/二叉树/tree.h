# include <stdlib.h>
# include <stdio.h>
typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node *left;
	struct node *right;
}treenode;
void visit(treenode*t)//打印出结点数据
{
    printf("%c  ",t->data);
}
treenode* leftchild(treenode*t)
{
	if(t!=NULL)
	return t->left;
	else
	return NULL;
}
treenode* rightchild(treenode*t)
{
	if(t!=NULL)
	return t->right;
	else
	return NULL;
}
treenode *create(void)
{
	treenode *p;
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
	p=NULL;
	else
	{
		p=(treenode*)malloc(sizeof(treenode));
		if(p==NULL)
		return p;
		p->data=ch;
		p->left=create();
		p->right=create();
	}
	return p;
}
void preorder(treenode*root)
{
	if(root==NULL)
	return ;
	visit(root);
	preorder(root->left);
	preorder(root->right);
}
void midorder(treenode*root)
{
		if(root==NULL)
		return ;
		preorder(root->left);
		visit(root);
		preorder(root->right);
}
void lastorder(treenode*root)
{
		if(root==NULL)
		return ;
		
		preorder(root->left);
		preorder(root->right);
		visit(root);
}
