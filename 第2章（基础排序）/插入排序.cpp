//时间复杂度o(n^2)
# include<stdio.h>
void sort(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)//从第二张牌开始与前面的牌进行比较 （前面的牌已排好序） 
	{
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key)//当前比较牌的前一个开始向前一个个比较，只要比比较牌大就往后移 
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;//找到最合适的位置 
	}
}
int main(void)
{
	int a[4]={4,3,2,1};
	sort(a,4);
	for(int i=0;i<4;i++)
	printf("%d ",a[i]);
	return 0;
}
