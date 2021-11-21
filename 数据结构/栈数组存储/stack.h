#define maxsize 100
typedef int ElemType;
typedef struct{
	ElemType stack[maxsize];
	int top;
}SequenceStack;
void stackInitiate(SequenceStack * s)
{
	s->top=0;
}
int StackNotEmpty(SequenceStack s)
{
	if(s.top<=0)
	return 0;
	else 
	return 1;
}
int StackPush(SequenceStack *s,ElemType x)
{
	if(s->top>=maxsize)
	return 0;
	
	s->stack[s->top]=x;
	s->top++;
	return 1;
}
int StackPop(SequenceStack *s,ElemType *x)
{
	if(s->top<=0)
	return 0;
	
	*x=s->stack[s->top-1];
	s->top--;
	return 1;
}
int StackTop(SequenceStack s,ElemType *x)
{
	if(s.top<=0)
	return 0;
	*x=s.stack[s.top-1];
	return 1;
}
