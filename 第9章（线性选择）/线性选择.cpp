//最坏运行时间是o(n^2)，但这是一个期望为线性时间的选择算法，因为标志位是随机取的 
# include <stdio.h>
int  m(int a[],int left,int right)//寻找一个标记位，它的左侧全都比他小，右侧全部比他大（但在左右侧里面的数不一定是有序的） 
{
	int flag=a[right];//将最后一个数设置为标记位 （随便取的） 
	int i=left-1;
	int j,t;
	for(j=left;j<right;j++)
	{
		if(a[j]<flag)//因为比标志位小的都在左边，大的在右边，所以遇到小的就跟右边的第一个数进行对换 
		{
			i++;
			t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
	}
	t=a[i+1];//最后将标志位插入其中 
	a[i+1]=a[right];
	a[right]=t;
	return i+1;
}
int qselect(int a[],int left,int right,int i)//查找a数组中第i个大的数 
{
	if(left==right)//递归结束条件 
	return a[i-1];
	int flag=m(a,left,right);//像快排一样选一个标志位分为两个区间 
	int k=flag-left+1;//K表明这是第几个大的数 
	//通过i与k的比较进行不同区间的查找 
	if(i==k)
		return a[flag]; 
	else if(i<k)
		return qselect(a,left,flag-1,i);
	else
		return qselect(a,flag+1,right,i-k);//这里因为是在右区间查找，所以不再是第i个大的数，而是相对于右区间第i-k大个数 
		
}
int main(void)
{
	int a[]={4,1,3,2,16,9,10,14,8,7};
	printf("%d",qselect(a,0,9,5));
	return 0;
}
