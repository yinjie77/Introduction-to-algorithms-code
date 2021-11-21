# include <stdio.h>
# include "stack.h"
int main(void)
{
	SequenceStack s;
	stackInitiate(&s);
	int i=0;
	for(i=0;i<5;i++)
	{
		StackPush(&s,i+1);
	}
	for(i=0;i<5;i++)
	{
		int x;
		StackPop(&s,&x);
		printf("%d",x);
		
	}
	printf("%d",StackNotEmpty(s));
	return 0;
}
