# include <stdio.h>
# include "linklist.h"
int main(void)
{
	linklist *head;
	Listinitialize(&head);
	
//	int x=listlenght(head);
//		printf("%d",x);
	int i,x;
	for(i=0;i<5;i++)
	{
		Listinsert(head,i,i+1);
	}
	Listdelete(head,2,&x);
	
	Listdestroy(&head);
	for(i=0;i<Listlenght(head);i++)
		{
			Listget(head,i,&x);
			printf("%d ",x);
		}
	printf("%d",Listlenght(head));
//	int x;
//	Listget(head,0,&x);
//	printf("%d",x);
	
	return 0;
}
