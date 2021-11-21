typedef char ElemType;
# define MaxSize 100
# include <stdio.h>
# include "MGraph.h"
void printft();//���A������������· 
void main(void)
{
    MatrixGraph g1;
    ElemType a[]={'A','B','C','D','E','F'};
    RowColWeight rcw[]={{0,2,5},{0,3,30},{1,0,2},{1,4,8},{2,5,7},{2,1,15},{4,3,4},{5,4,18},{5,3,10}};
    int n=6,e=9;
    int i,j;
    CreatGraph(&g1,a,n,rcw,e);
    printf("���㼯��Ϊ��");
    for(i=0;i<g1.Vertices.size;i++)
        printf("%c  ",g1.Vertices.list[i]);
    printf("\n");
    printf("Ȩֵ����Ϊ:\n");
    for(i=0;i<g1.Vertices.size;i++)
    {
        for(j=0;j<g1.Vertices.size;j++)
            printf("%5d  ",g1.edge[i][j]);
            printf("\n");
    }
//    printf("��ȱ�����\n");
//    DepthFirstSearch(g1);
//    printf("\n��ȱ���: \n");
//    BroadFirstSearch(g1);
    
  int distance[50],path[50];
    Dijkstra(g1,0,distance,path);
    printf("\n\n�Ӷ���A���������������̾���Ϊ��\n");
    for(i=0;i<n;i++)
       {
       	printf("������%c����̾���Ϊ:%d",65+i,distance[i]);
       	printf("\n");
	   }
    printf("path����ֵΪ: \n");
    for(i=0;i<n;i++)
    	printf("%d ",path[i]);
    printf("\nA������������·��\n");
    for(i=1;i<n;i++)
    {
    	printft(g1,0,i,path);
    	printf("\n");
	}
       
}
void printft(MatrixGraph G,int v0,int v1,int path[])
{
	if(v0==v1)//��pathԪ�ص���v0ʱ�������ҵ�ԭ���㣬���ԭ���� 
		{
			printf("%c ",G.Vertices.list[v0]);
			return ;
		}
		printft(G,v0,path[v1],path);//���Ҳ���ʱ�ͼ���Ѱ�����·������һ���� 
		printf("%c ",G.Vertices.list[v1]);//��Ϊ��һ�����ǰ�ң�����ֻ��ÿ�γ���ִ����ʱ�����ǰ�Ķ��㼴�� 
}
