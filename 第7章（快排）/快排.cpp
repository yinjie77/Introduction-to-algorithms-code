//���������Ǳ��λ����߻��ұ���һ������û���κ�������ʱʱ�临�ӶȾ�O��n^2)������������һ���������������������� ����������ֻ��O��n���������������� O��n^2)
//��������������ߺ��ұߵĸ���ƽ�⣬ʱ�临�Ӷ�Ϊo(nlgn)
//������һ��ֻ��һ������һ��������ʣ��ģ�Ҳ��o(nlgn)���ںõĻ����뻵�Ļ��ֻ���У�һ���� o(nlgn)
# include <stdio.h>
int  m(int a[],int left,int right)//Ѱ��һ�����λ���������ȫ������С���Ҳ�ȫ�������󣨵������Ҳ����������һ��������ģ� 
{
	int flag=a[right];//�����һ��������Ϊ���λ �����ȡ�ģ� 
	int i=left-1;
	int j,t;
	for(j=left;j<right;j++)
	{
		if(a[j]<flag)//��Ϊ�ȱ�־λС�Ķ�����ߣ�������ұߣ���������С�ľ͸��ұߵĵ�һ�������жԻ� 
		{
			i++;
			t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
	}
	t=a[i+1];//��󽫱�־λ�������� 
	a[i+1]=a[right];
	a[right]=t;
	return i+1;
}
void quicksort(int a[],int left,int right)
{
	if(left<right)
	{
		int mid; 
		mid=m(a,left,right);
		quicksort(a,left,mid-1);
		quicksort(a,mid+1,right);
	}
}
int main(void)
{
	int a[]={4,1,3,2,16,9,10,14,8,7};
	quicksort(a,0,9);
	for(int i=0;i<10;i++)
	printf("%d ",a[i]);
	
	return 0;
}
