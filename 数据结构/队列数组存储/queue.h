typedef int ElemType;
#define maxsize 100
typedef struct{
	ElemType queue[maxsize];
	int front;
	int rear;
	int count;
}queue;
void queueInitiate(queue*q)
{
	q->front=0;
	q->rear=0;
	q->count=0;
}
int queueNotEmpty(queue q)
{
	if(q.count==0)
	return 0;
	else
	return 1;
}
int queueAppend(queue *q,ElemType x)
{
	if(q->count>0&&q->front==q->rear)
	{
		return 0;
	}
	else
	{
		q->queue[q->rear]=x;
		q->rear=(q->rear+1)%maxsize;
		q->count++;
		return 1;
	}
}
int queueDelete(queue *q,ElemType*x)
{
	if(q->count<=0)
	return 0;
	else
	{
		*x=q->queue[q->front];
		q->front=(q->front+1)%maxsize;
		q->count--;
		return 1;
	}
}
int queueGet(queue q,ElemType *x)
{
	if(q.count<=0)
	return 0;
	else
	{
		*x=q.queue[q.front];
		return 1;
	}
}
