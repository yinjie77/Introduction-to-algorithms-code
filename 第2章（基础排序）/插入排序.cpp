//ʱ�临�Ӷ�o(n^2)
# include<stdio.h>
void sort(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)//�ӵڶ����ƿ�ʼ��ǰ����ƽ��бȽ� ��ǰ��������ź��� 
	{
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key)//��ǰ�Ƚ��Ƶ�ǰһ����ʼ��ǰһ�����Ƚϣ�ֻҪ�ȱȽ��ƴ�������� 
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;//�ҵ�����ʵ�λ�� 
	}
}
int main(void)
{
	int a[4]={4,3,2,1};
	sort(a,4);
	for(int i=0;i<4;i++)
	printf("%d ",a[i]);
	return 0;
}
