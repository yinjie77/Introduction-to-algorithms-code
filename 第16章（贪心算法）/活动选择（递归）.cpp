//������������ʱ�临�Ӷ�ΪO��n�� 
# include <stdio.h>
int q[100];
int count=0;
int recselect(int s[],int f[],int k,int n)
{
	int m=k+1;
	while(m<=n&&s[m]<f[k])
	m++;
	if(m<=n)
		{
			q[count]=m;
			count++;
			recselect(s,f,m,n);	
		}
	else
		return 0;
}
int main(void)
{
	//����һ����ʼ�ͽ���Ϊ0�Ļ��ʹ���㷨�п���һ��ʼ�ͼ����һ��� 
	int s[]={0,1,3,0,5,3,5,6,8,8,2,12};
	int f[]={0,4,5,6,7,9,9,10,11,12,14,16};
	recselect(s,f,0,12);
	int i;
	for(i=0;i<count;i++)
	printf("%d ",q[i]);
	
	return 0;
}
