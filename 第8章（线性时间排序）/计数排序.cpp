//时间复杂度Ο (n+k)，k是数组中整数的范围 
# include <stdio.h>
void coutingsort(int a[],int b[],int max,int length)//a为原数组，b为存放排序的数组，max表示原数组中最大的数，length表示原数组的长度 
{
	int c[max+1];//存放原数组中0到max每个数出现的次数 
	int i,j;
	for(i=0;i<=max;i++)
	{
		c[i]=0;
	}
	for(j=0;j<length;j++)//存放次数 
	{
		c[a[j]]++;
	}
	for(i=1;i<=max;i++)//此时c数组每个元素表示小于等于当前数的个数 
	{
		c[i]=c[i]+c[i-1];
	}
	
	for(j=length-1;j>=0;j--)
	{
		b[c[a[j]]-1]=a[j];//根据小于自己的个数放入b数组合适的位置中 
		c[a[j]]--;//因为可能有重复的数，所以每次放入一个数之后就将此数的个数减一 
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
