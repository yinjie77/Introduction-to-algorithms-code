//不排序的情况下时间复杂度为O（n）
# include <stdio.h>
int q[100];
int count=0;
void greedselcet(int s[],int f[],int n)
{
	q[count]=1;
	count++;
	int m,k=0;
	for(m=1;m<n;m++)
	{
		if(s[m]>=f[k])
		{
			q[count]=m+1;
			count++;
			k=m;
		}
	}	
} 
int main(void)
{
	int s[]={1,3,0,5,3,5,6,8,8,2,12};
	int f[]={4,5,6,7,9,9,10,11,12,14,16};
	greedselcet(s,f,11);
	int i;
	for(i=0;i<count;i++)
	printf("%d ",q[i]);
	return 0;
}
