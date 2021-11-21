# include <stdio.h>

# include "Sequencelist.h"
void converse(Sequencelist *L)//ÄæÖÃ 
{
	int i;
	for(i=0;i<L->size/2;i++)
	{
		ElemType x;
		x=L->list[i];
		L->list[i]=L->list[L->size-1-i];
		L->list[L->size-1-i]=x;
		
	}
}
int main(void)
{
	Sequencelist L;
	listInitialize(&L);
	int i;
	for(i=0;i<5;i++)
	listinsert(&L,i,i+1);
	
	
//	int x;
//	x=listlength(L);
//	printf("%d",x);
	converse(&L);
	
	
	for(i=0;i<L.size;i++)
	printf("%d",L.list[i]);
	return 0;
}
