//ʱ�临�Ӷ�o(nlgn) 
# include <stdio.h>
int max=999999;
/*
�ϲ�����Ҫ˼�룺���������ߵ���ֵ�ֱ𸳸��������飬�ٽ��б��������������������г�ȡ��С�ķ���ԭ���������С������ӱ������ 
*/ 
void hebing(int s[],int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int a[n1+1],b[n2+1];
	int i,j;
	for(i=0;i<n1;i++)
	a[i]=s[p+i];
	a[i]=max;// ����������������һ��ֵ���൱���ڱ� 
	for(i=0;i<n2;i++)
	b[i]=s[q+i+1];
	b[i]=max;//����������������һ��ֵ���൱���ڱ� 
	i=0,j=0;
	for(int k=p;k<=r;k++)
	{
		if(a[i]<b[j])
		{
			s[k]=a[i];
			i++;
		}
		else
		{
			s[k]=b[j];
			j++;
		}
	}
}
void guibing(int s[],int p,int q)
{
	if(p<q)
	{
		int mid=(p+q)/2;
		guibing(s,p,mid);
		guibing(s,mid+1,q);
		hebing(s,p,mid,q);
	}
}
int main(void)
{
	
	int s[4]={7,5,4,2};
	guibing(s,0,3);
		for(int i=0;i<4;i++)
	printf("%d ",s[i]);
	return 0;
}
