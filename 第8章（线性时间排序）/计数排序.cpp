//ʱ�临�ӶȦ� (n+k)��k�������������ķ�Χ 
# include <stdio.h>
void coutingsort(int a[],int b[],int max,int length)//aΪԭ���飬bΪ�����������飬max��ʾԭ��������������length��ʾԭ����ĳ��� 
{
	int c[max+1];//���ԭ������0��maxÿ�������ֵĴ��� 
	int i,j;
	for(i=0;i<=max;i++)
	{
		c[i]=0;
	}
	for(j=0;j<length;j++)//��Ŵ��� 
	{
		c[a[j]]++;
	}
	for(i=1;i<=max;i++)//��ʱc����ÿ��Ԫ�ر�ʾС�ڵ��ڵ�ǰ���ĸ��� 
	{
		c[i]=c[i]+c[i-1];
	}
	
	for(j=length-1;j>=0;j--)
	{
		b[c[a[j]]-1]=a[j];//����С���Լ��ĸ�������b������ʵ�λ���� 
		c[a[j]]--;//��Ϊ�������ظ�����������ÿ�η���һ����֮��ͽ������ĸ�����һ 
	}
}
int main(void)
{
	int a[8]={2,5,3,0,2,3,0,3};
	int b[8];
	coutingsort(a,b,5,8);
	for(int i=0;i<8;i++)
	printf("%d ",b[i]);
	return 0;
}
