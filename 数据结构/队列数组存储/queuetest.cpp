# include <stdio.h>
# include "queue.h"
int main(void)
{
	queue q;
	queueInitiate(&q);
	int i;
	int x;
	for(i=0;i<5;i++)
	{
		queueAppend(&q,i+1);
	}
	queueGet(q,&x);
	printf("%d",x);
	for(i=0;i<5;i++)
	{
		
		queueDelete(&q,&x);
		
	}
	return 0;
}
