//ʱ�临�Ӷ�n�����η� 
# include <stdio.h>
int m[100][100]={0};
int s[100][100]={0};
int  min(int p[],int n)
{
	n=n-1;//һ��ʼn��ʾ�������������������ȥһ���Ǿ����� 
	
	int i,l,j,k,q;

	for(l=2;l<=n;l++)//l��ʾ��������ʾ����������� 
	{
		for(i=1;i<=n-l+1;i++)//i��ʾ�Ӻδ���ʼ������� 
			{
				j=i+l-1;
				m[i][j]=100000;
				for(k=i;k<=j-1;k++)//Ѱ�ҷָ��ʹ�����������ֵ��С ���൱���Ե����Ͻ�����⣬�ȼ���̵��������������Ҫ��������� 
				{
					q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
					if(q<m[i][j])
					{
						m[i][j]=q;
						s[i][j]=k;
					}
				}
			}
	}
	
	return m[1][n];
}
 void print(int i,int j)
 {
 	if(i==j)
 	printf("A%d",i);
 	else
 	{
 		printf("(");
 		print(i,s[i][j]);
 		print(s[i][j]+1,j);
 		printf(")");
 	}
 }
int main(void)
{
	int p[4]={10,100,5,50};
	printf("%d\n",min(p,4));
	print(1,3);
	return 0;
}
