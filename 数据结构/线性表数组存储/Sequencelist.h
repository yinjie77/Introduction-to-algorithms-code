#define  maxsize 100
typedef int ElemType;
typedef struct
{
	ElemType list[maxsize];
	int size;
}Sequencelist;
void listInitialize(Sequencelist * L)
{
	L->size=0;
}
int  listlength(Sequencelist L)
{
	return L.size;
}
int listinsert(Sequencelist *L,int i,ElemType x)
{
	if(L->size>=maxsize)
	return 0;
	else if(i<0||i>L->size)
	return 0;
	else
	{
		int j;
		for(j=L->size;j>i;j--)
		{
			L->list[j]=L->list[j-1];
		}
		L->list[i]=x;
		L->size++;
		return 1;
	}
	
}
int listdelete(Sequencelist *L,int i,ElemType *x)
{
	if(L->size<=0)
		return 0;
	else if(i<0||i>L->size-1)
		return 0;
	else
	{
		int j;
		*x=L->list[i];
		for(j=i;j<L->size-1;j++)
		{
			L->list[j]=L->list[j+1];
		}
		L->size--;
		return 1;
		
	}
}
int listget(Sequencelist L,int i,ElemType *x)
{
	if(i<0||i>=L.size)
	return 0;
	else
	{
		*x=L.list[i];
		return 1;
	}
}
