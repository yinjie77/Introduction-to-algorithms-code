//�����ʱ����o(n^2)��������һ������Ϊ����ʱ���ѡ���㷨����Ϊ��־λ�����ȡ�� 
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
int qselect(int a[],int left,int right,int i)//����a�����е�i������� 
{
	if(left==right)//�ݹ�������� 
	return a[i-1];
	int flag=m(a,left,right);//�����һ��ѡһ����־λ��Ϊ�������� 
	int k=flag-left+1;//K�������ǵڼ�������� 
	//ͨ��i��k�ıȽϽ��в�ͬ����Ĳ��� 
	if(i==k)
		return a[flag]; 
	else if(i<k)
		return qselect(a,left,flag-1,i);
	else
		return qselect(a,flag+1,right,i-k);//������Ϊ������������ң����Բ����ǵ�i�������������������������i-k����� 
		
}
int main(void)
{
	int a[]={4,1,3,2,16,9,10,14,8,7};
	printf("%d",qselect(a,0,9,5));
	return 0;
}
