# include <Stdio.h>
# include "queue.h"
int main(void)
{
	queue q;
	queueInitiate(&q);
	int i;
	for(i=0;i<5;i++)
	{
		queueAppend(&q,i+1);
	}
	Destroy(&
	q);
//	for(i=0;i<5;i++)
//	{
//		int x;
//		queueDelete(&q,&x);
//		printf("%d",x);		
//	}
	printf("%d",queueNotEmpty(q));
	return 0;
}
