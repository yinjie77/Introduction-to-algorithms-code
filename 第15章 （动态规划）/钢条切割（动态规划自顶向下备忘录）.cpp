//ʱ�临�Ӷ�Ϊn�� 
# include <stdio.h>
int min=-1000;
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int cutrod(int p[],int n,int r[])
{
	if(r[n]>=0)
	return r[n];
	if(n==0)
	return 0;
	int q=min;
	int i;
	for(i=1;i<=n;i++)
		{
			q=max(q,(p[i]+cutrod(p,n-i,r)));
		}
	r[n]=q;//��¼��ǰ���������Сֵ���Ժ�Ͳ���Ҫ���� 
	return q;
}
int memcutrod(int p[],int n)//��ʼ������¼ 
{
	int r[n+1];
	int i;
	for(i=0;i<=n;i++)
	r[i]=min;
	
	return cutrod(p,n,r);
}

int main(void)
{
	int p[]={0,1,5,8,9,10,17,17,20,24,30};
	printf("%d",memcutrod(p,40));
	return 0;
}
