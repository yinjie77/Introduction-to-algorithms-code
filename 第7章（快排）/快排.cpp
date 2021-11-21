//最坏情况，就是标记位的左边或右边有一个区间没有任何数，这时时间复杂度就O（n^2)，跟插入排序一样，并且如果本身就是有序 ，插入排序还只是O（n），而快排依旧是 O（n^2)
//最好情况，就是左边和右边的个数平衡，时间复杂度为o(nlgn)
//即便是一边只有一个数，一边有其他剩余的，也是o(nlgn)，在好的划分与坏的划分混合中，一定是 o(nlgn)
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
void quicksort(int a[],int left,int right)
{
	if(left<right)
	{
		int mid; 
		mid=m(a,left,right);
		quicksort(a,left,mid-1);
		quicksort(a,mid+1,right);
	}
}
int main(void)
{
	int a[]={4,1,3,2,16,9,10,14,8,7};
	quicksort(a,0,9);
	for(int i=0;i<10;i++)
	printf("%d ",a[i]);
	
	return 0;
}
