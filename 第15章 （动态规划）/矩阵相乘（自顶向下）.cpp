//时间复杂度n的三次方 
# include <stdio.h>
int max=999999;
int m[100][100];

int chain(int p[],int i,int j)
{
	if(m[i][j]<max)
	return m[i][j];
	if(i==j)
	m[i][j]=0;
	
	else
	{
		int k;
		for(k=i;k<=j-1;k++)
		{
			int q=chain(p,i,k)+chain(p,k+1,j)+p[i-1]*p[k]*p[j];
			if(q<m[i][j])
			m[i][j]=q;
		}
	}
	return m[i][j];
}
int mem(int p[],int n)
{
	n=n-1;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		m[i][j]=max;
	return chain(p,1,n);	
}
int main(void)
{
	int p[4]={10,100,5,50};
	printf("%d",mem(p,4));
	return 0;
}
