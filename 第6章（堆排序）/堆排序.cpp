//ʱ�临�Ӷ�o(nlgn)  
# include <stdio.h>
void max(int a[],int i,int length)//ά�����ѵ����� 
{
	int l=2*i+1;//��ڵ� 
	int r=2*i+2;//�ҽڵ� 
	int largest=i;
	int t;
	//Ѱ���������ڵ�������ֵ��ʹ֮��Ϊ���ڵ㣬���������λ�÷����˽�������Ҫ����ά��������λ�õ��Ǹ��ڵ㣨���Һ�������һ��λ�ã� 
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
	for(i=(length)/2-1;i>=0;i--)//�����һ����Ҷ�ڵ㿪ʼ�������ѣ���ΪҶ�ӽڵ�û�к��ӣ�����Ҫά���������� 
		max(a,i,length);
}
void heapsort(int a[],int length)
{
	buildmaxheap(a,length);
	int i,t;
	for(i=length-1;i>=1;i--)//��Ϊ���ڵ�һ�������ģ�����ÿ�ζ������һ���ڵ㽻��λ�ã���ά���ѵ����ʣ������ֳ����ľ���һ���������� 
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
