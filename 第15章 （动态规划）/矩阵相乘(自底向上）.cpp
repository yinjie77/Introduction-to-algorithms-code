//时间复杂度n的三次方 
# include <stdio.h>
int m[100][100]={0};
int s[100][100]={0};
int  min(int p[],int n)
{
	n=n-1;//一开始n表示矩阵链里的行列数，减去一才是矩阵数 
	
	int i,l,j,k,q;

	for(l=2;l<=n;l++)//l表示链长，表示几个矩阵相乘 
	{
		for(i=1;i<=n-l+1;i++)//i表示从何处开始这个链长 
			{
				j=i+l-1;
				m[i][j]=100000;
				for(k=i;k<=j-1;k++)//寻找分割点使得这个链长的值最小 （相当于自底向上解决问题，先计算短的链长，再组成所要求的链长） 
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
