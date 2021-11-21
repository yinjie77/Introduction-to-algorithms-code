//时间复杂度o(nlgn)  
# include <stdio.h>
void max(int a[],int i,int length)//维护最大堆的性质 
{
	int l=2*i+1;//左节点 
	int r=2*i+2;//右节点 
	int largest=i;
	int t;
	//寻找这三个节点中最大的值，使之成为根节点，如果发生了位置发生了交换，则要继续维护交换了位置的那个节点（左右孩子其中一个位置） 
	if(l<length&&a[l]>a[i])
		largest=l;
	if(r<length&&a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		t=a[largest];
		a[largest]=a[i];
		a[i]=t;
		max(a,largest,length);
	}
}
void buildmaxheap(int a[],int length)
{
	int i;
	for(i=(length)/2-1;i>=0;i--)//从最后一个非叶节点开始构造最大堆，因为叶子节点没有孩子，不需要维护最大堆性质 
		max(a,i,length);
}
void heapsort(int a[],int length)
{
	buildmaxheap(a,length);
	int i,t;
	for(i=length-1;i>=1;i--)//因为根节点一定是最大的，所以每次都与最后一个节点交换位置，再维护堆的性质，最后呈现出来的就是一个升序排序 
	{
		t=a[0];
		a[0]=a[i];
		a[i]=t;
		length=length-1;
		max(a,0,length);		
	}
}
int main(void)
{
	int a[]={4,1,3,2,16,9,10,14,8,7};
	heapsort(a,10);
	for(int i=0;i<10;i++)
	printf("%d ",a[i]);
	
}
