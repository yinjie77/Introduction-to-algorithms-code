# include <stdlib.h>
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
}linklist;
void Listinitialize(linklist **head)
{
	if((*head=(linklist*)malloc(sizeof(linklist)))==NULL)
		exit(-1);
	(*head)->next=NULL;
}
int Listlenght(linklist*head)
{
	linklist*p=head;
	int size=0;
	while(p->next!=NULL){
		p=p->next;
		size++;
	}
	return size;
}
int Listget(linklist*head,int i,ElemType *x)
{
	linklist*p=head;
	int j=-1;
	while(p->next!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j!=i)
	return 0;
	
	*x=p->data;
	return 1;
}
int Listinsert(linklist*head,int i,ElemType x)
{
	linklist*q=head,*p;
	int j=-1;
	while(q->next!=NULL&&j<i-1)
	{
		q=q->next;
		j++;
	}
	if(j!=i-1)
	return 0;
	
	if((p=(linklist*)malloc(sizeof(linklist)))==NULL)
	exit(-1);
	p->data=x;
	p->next=q->next;
	q->next=p;
	return 1;	
}
int Listdelete(linklist*head,int i,ElemType *x)
{
	linklist*q=head,*p;
	int j=-1;
	while(q->next!=NULL&&j<i-1)
	{
		q=q->next;
		j++;
	}
	if(j!=i-1)
	return 0;
	
	p=q->next;
	*x=p->data;
	q->next=p->next;
	free(p);
	return 1;
	
		
}
void Listdestroy(linklist**head)
{
	linklist *p,*q;
	p=*head;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	*head=NULL;
}
