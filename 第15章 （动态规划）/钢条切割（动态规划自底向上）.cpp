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
int BOTTOMUPCUTROD(int p[],int n)
{
	int r[n+1];
	r[0]=0;
	int j;
	for(j=1;j<=n;j++) //�ӳ���Ϊ1������ʼ���㵽����Ϊn������ֵ��n������ֵ��ǰ���������ֵƴ������ 
	{
		int q=min;
		int i;
		for(i=1;i<=j;i++)
		q=max(q,p[i]+r[j-i]);
		
		r[j]=q; 
	}
	return r[n];
}


int main(void)
{
	int p[]={0,1,5,8,9,10,17,17,20,24,30};
	printf("%d",BOTTOMUPCUTROD(p,9));
	return 0;
}
