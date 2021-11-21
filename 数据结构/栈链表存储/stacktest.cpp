# include <stdio.h>
# include "stack.h"
int main(void)
{
	stackLinkList *head;
	StackInitiate(&head);
	int i;
	for(i=0;i<5;i++)
	{
		StackPush(head,i+1);
	}
	Destroy(&head);
		for(i=0;i<5;i++)
		{
			int x;
			StackPop(head,&x);
			printf("%d",x);
		}
//	printf("%d",StackNotEmpty(head));
	return 0;
}
