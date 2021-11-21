typedef char ElemType;
# define MaxSize 100
# include <stdio.h>
# include "MGraph.h"
void printft();//输出A到其他点的最短路 
void main(void)
{
    MatrixGraph g1;
    ElemType a[]={'A','B','C','D','E','F'};
    RowColWeight rcw[]={{0,2,5},{0,3,30},{1,0,2},{1,4,8},{2,5,7},{2,1,15},{4,3,4},{5,4,18},{5,3,10}};
    int n=6,e=9;
    int i,j;
    CreatGraph(&g1,a,n,rcw,e);
    printf("顶点集合为：");
    for(i=0;i<g1.Vertices.size;i++)
        printf("%c  ",g1.Vertices.list[i]);
    printf("\n");
    printf("权值集合为:\n");
    for(i=0;i<g1.Vertices.size;i++)
    {
        for(j=0;j<g1.Vertices.size;j++)
            printf("%5d  ",g1.edge[i][j]);
            printf("\n");
    }
//    printf("深度遍历：\n");
//    DepthFirstSearch(g1);
//    printf("\n广度遍历: \n");
//    BroadFirstSearch(g1);
    
  int distance[50],path[50];
    Dijkstra(g1,0,distance,path);
    printf("\n\n从顶点A到其他各顶点的最短距离为：\n");
    for(i=0;i<n;i++)
       {
       	printf("到顶点%c的最短距离为:%d",65+i,distance[i]);
       	printf("\n");
	   }
    printf("path数组值为: \n");
    for(i=0;i<n;i++)
    	printf("%d ",path[i]);
    printf("\nA到其他点的最短路：\n");
    for(i=1;i<n;i++)
    {
    	printft(g1,0,i,path);
    	printf("\n");
	}
       
}
void printft(MatrixGraph G,int v0,int v1,int path[])
{
	if(v0==v1)//当path元素等于v0时代表已找到原顶点，输出原顶点 
		{
			printf("%c ",G.Vertices.list[v0]);
			return ;
		}
		printft(G,v0,path[v1],path);//当找不到时就继续寻找最短路径的上一个点 
		printf("%c ",G.Vertices.list[v1]);//因为是一层层往前找，所以只需每次程序执行完时输出当前的顶点即可 
}
