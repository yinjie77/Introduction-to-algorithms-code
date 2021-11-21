//时间复杂度O（mn） 
# include <stdio.h>
# include <stdlib.h>
int m,n;//mn记录两个主序列的个数 
int b[100][100],c[100][100];//b保存标记值，用于寻找最大子序列，c保存各子问题的最长子序列的个数 
void LSC(char x[],char y[])
{
	int i,j;
	for(i=1;i<=m;i++)
	c[i][0]=0;
	for(j=1;j<=n;j++)
	c[0][j]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			{
				if(x[i]==y[j])//如果内容相等，则当前问题的最长子序列的个数是前面序列的个数加1 
				{
					c[i][j]=c[i-1][j-1]+1;
					b[i][j]=1;
				}
				//如果内容不相等，分为两种情况，一是当前问题的最长子序列个数是去掉x最后一个内容的个数，一个是去掉y的最后一个内容的个数 
				else if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					b[i][j]=0;
				}
				else
				{
					c[i][j]=c[i][j-1];
					b[i][j]=-1;
				}
			}
}
int  aprint(char x[],int i,int j)
{
	if(i==0||j==0)
	return 0;
	if(b[i][j]==1)
	{
		aprint(x,i-1,j-1);
		printf("%c",x[i]);
	}
	else if(b[i][j]==0)
	aprint(x,i-1,j);
	else
	aprint(x,i,j-1);
}
int main(void)
{
	char x[]={'0','a','b','c','b','d','a','b'},y[]={'0','b','d','c','a','b','a'};
	m=7,n=6;
	LSC(x,y);
/*	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		printf("%d ",b[i][j]);

		printf("\n");
	}
*/	
	aprint(x,m,n);
	return 0;
}
