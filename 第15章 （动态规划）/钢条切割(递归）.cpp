//时间复杂度2的n次方 
# include <stdio.h>
int min=-1000;
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int cutrod(int p[],int n)
{
	if(n==0)
	return 0;
	int q=min;
	int i;
	for(i=1;i<=n;i++)
		{
			q=max(q,(p[i]+cutrod(p,n-i)));
		}
	return q;
}
int main(void)
{
	int p[]={0,1,5,8,9,10,17,17,20,24,30};
	printf("%d",cutrod(p,40));
	return 0;
}
