//时间复杂度o(nlgn) 
# include <stdio.h>
# define min -99999
typedef struct{
	int maxleft;
	int maxright;
	int sum;
}z;//用来保存子数组的信息
/*
寻找跨越中点的最大子数组的思想：从中点开始分别向左右遍历，分别保存左边区间的最大值与右边区间的最大值，最后将这两部分加起来就成了跨越中点的最大数组 
*/ 
z searchmid(int a[],int left,int mid,int right)
{
	z q;
	int  leftmax=min;
	int sum=0,i;
	for(i=mid;i>=left;i--)
	{
		sum=sum+a[i];
		if(sum>leftmax)
		{
			leftmax=sum;
			q.maxleft=i;
		}
	}
	int  rightmax=min;
	sum=0;
	for(i=mid+1;i<=right;i++)
	{
		sum=sum+a[i];
		if(sum>rightmax)
		{
			rightmax=sum;
			q.maxright=i;
		}
	}
	q.sum=rightmax+leftmax;
	return q;
}
z zuida(int a[],int left,int right)
{
	z q;
	z leftmax,rightmax,midmax;
	if(left==right) 
		{
			q.maxleft=left;
			q.maxright=right;
			q.sum=a[left];
			return q;
		}
	else
	{
		//将数组分为两个部分，利用递归求解两边最大值，再求跨越中点的最大值 ，最后返回这三个中子数组最大的值 
		int mid=(left+right)/2;
		 leftmax=zuida(a,left,mid);
		 rightmax=zuida(a,mid+1,right);
		 midmax=searchmid(a,left,mid,right);
	}
	if(leftmax.sum>=rightmax.sum&&leftmax.sum>=midmax.sum)
		return leftmax;
	else if(rightmax.sum>=leftmax.sum&&rightmax.sum>=midmax.sum)
		return rightmax;
	else
		return midmax;
}
int main(void)
{
	int a[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	z m=zuida(a,0,15);
	printf("%d %d %d",m.sum,m.maxleft+1,m.maxright+1);
	return 0;
}
