# include <stdlib.h>
typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node *next;
}stackLinkList;
void StackInitiate(stackLinkList**head)
{
	if(((*head)=(stackLinkList*)malloc(sizeof(stackLinkList)))==NULL)
	exit(-1);
	(*head)->next=NULL;
}
int StackNotEmpty(stackLinkList *head)
{
	if(head->next!=NULL)
	return 1;
	else
	return 0;
}
int StackPush(stackLinkList *head,ElemType x)
{
	stackLinkList *q;
	if((q=(stackLinkList*)malloc(sizeof(stackLinkList)))!=NULL)
	{
		q->data=x;
		q->next=head->next;
		head->next=q;
		return 1;
	}
	else
	return 0;
}
int StackPop(stackLinkList*head,ElemType *x)
{
	stackLinkList*q=head->next;
	if(q==NULL)
	return 0;
	
	head->next=q->next;
	*x=q->data;
	free(q);
	return 1;
}
int StackTop(stackLinkList *head,ElemType *x)
{
	stackLinkList*q=head->next;
		if(q==NULL)
		return 0;
	*x=q->data;
	return 1;	
	
}
void Destroy(stackLinkList**head)
{
	stackLinkList*p,*q;
	p=*head;
	while(p!=NULL){
		q=p;
		p=p->next;
		free(q);
	}
	*head=NULL;
}
