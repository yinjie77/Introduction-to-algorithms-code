# include <stdlib.h>
typedef int ElemType;
typedef struct qnode
{
	ElemType data;
	struct qnode *next;
}queuenode;
typedef struct{
	queuenode *front;
	queuenode *rear;
}queue;

void queueInitiate(queue *q)
{
	q->front=NULL;
	q->rear=NULL;
}
int queueNotEmpty(queue q)
{
	if(q.front==NULL)
	return 0;
	else
	return 1;
}
int queueAppend(queue *q,ElemType x)
{
	queuenode *p;
	if((p=(queuenode*)malloc(sizeof(queuenode)))==NULL)
	exit(-1);
	p->data=x;
	p->next=NULL;
	if(q->rear!=NULL)
	q->rear->next=p;
	
	q->rear=p;
	if(q->front==NULL)
	q->front=p;
	
	return 1;
	
}
int queueDelete(queue *q,ElemType *x)
{
	queuenode *p;
	if(q->front==NULL)
	return 0;
	else
	{
		*x=q->front->data;
		p=q->front;
		q->front=q->front->next;
		
		if(q->front==NULL)
		{
			q->rear=NULL;
		}
		free(p);
		return 1;
		
	}
}
int Destroy(queue *q)
{
	queuenode *z,*x;
	z=q->front;
	while(z!=NULL)
	{
		x=z;
		z=z->next;
		free(x);
	}
	q->front=NULL;
	q->rear=NULL;
	return 1;
}
