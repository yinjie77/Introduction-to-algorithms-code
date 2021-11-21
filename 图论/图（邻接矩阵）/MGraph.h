# include "SequenceList.h"
# include "queue.h"
# include <stdlib.h>
# define MaxVertices 100
# define MaxWeight 10000
typedef struct
{
    SequenceList Vertices;//存放顶点
    int edge[MaxVertices][MaxVertices];//存放边
    int numOfEdges;//边的条数
} MatrixGraph;
typedef struct
{
    int row;//行
    int col;//列
    int weight;//权值
} RowColWeight;
void Initiate(MatrixGraph * G,int n)//图初始化
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(i==j)
                G->edge[i][j]=0;
            else
                G->edge[i][j]=MaxWeight;
        }
    G->numOfEdges=0;
    ListInitialize(&G->Vertices);
}
void InsertVertex(MatrixGraph * G,ElemType vertex)//插入顶点
{
    ListInsert(&G->Vertices,G->Vertices.size,vertex);//在顺序表中插入
}
void InsertEdge(MatrixGraph * G,int v1,int v2,int weight)//插入边
{
    if(v1<0||v1>=G->Vertices.size||v2<0||v2>=G->Vertices.size)
    {
        printf("参数v1或v2越界出错! \n");
        exit(1);
    }
    G->edge[v1][v2]=weight;
    G->numOfEdges++;
}
void DeleteEdge(MatrixGraph * G,int v1,int v2)//删除边
{
    if(v1<0||v1>=G->Vertices.size||v2<0||v2>=G->Vertices.size||v1==v2)
    {
        printf("参数v1或v2越界出错! \n");
        exit(1);
    }
    G->edge[v1][v2]=MaxWeight;
    G->numOfEdges--;
}
void DeleteVertex(MatrixGraph * G,int v)//删除顶点
{
    int n = ListLength(G->Vertices),i,j;
    ElemType x;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if((i==v||j==v)&&G->edge[i][j]>0&&G->edge[i][j]<MaxWeight)
                G->numOfEdges--;
    for(i=v; i<n; i++)//删除第v行
        for(j=0; j<n; j++)
            G->edge[i][j]=G->edge[i+1][j];
    for(i=0; i<n; i++)//删除第v列
        for(j=v; j<n; j++)
            G->edge[i][j]=G->edge[i][j+1];
    ListDelete(&G->Vertices,v,&x);//顺序表中删除顶点

}
int GetFirstVex(MatrixGraph  G,int v)//取第v行的第一个非0非无穷大的数
{
    int col;
    if(v<0||v>=G.Vertices.size)
    {
        printf("参数v越界出错! \n");
        exit(1);
    }
    for(col=0; col<G.Vertices.size; col++)
        if(G.edge[v][col]>0&&G.edge[v][col]<MaxWeight)
            return col;
    return -1;

}
int GetNextVex(MatrixGraph  G,int v1,int v2)//取v1行的v2的下一个顶点
{
    int col;
    if(v1<0||v1>=G.Vertices.size||v2<0||v2>=G.Vertices.size)
    {
        printf("参数v1或v2越界出错! \n");
        exit(1);
    }
    for(col=v2+1; col<=G.Vertices.size; col++)
        if(G.edge[v1][col]>0&&G.edge[v1][col]<MaxWeight)
            return col;
    return -1;
}
void CreatGraph(MatrixGraph * G,ElemType V[],int n,RowColWeight E[],int e)
{
    int i,k;
    Initiate(G,n);
    for(i=0; i<n; ++i) //插入顶点
        InsertVertex(G,V[i]);
    for(k=0; k<e; k++) //插入边
        InsertEdge(G,E[k].row,E[k].col,E[k].weight);
}
void DepthFSearch(MatrixGraph G,int v,int visited[])//连通图深度遍历
{
    int w;
    printf("%c  ",G.Vertices.list[v]);//输出当前顶点
    visited[v]=1;//将此顶点标记
    w=GetFirstVex(G,v);//取第一个邻接顶点
    while(w!=-1)//有邻接顶点就进入循环
    {
        if(!visited[w])//只要没标记过就对w行的继续执行深度遍历
            DepthFSearch(G,w,visited);
        w=GetNextVex(G,v,w);
    }
}
void DepthFirstSearch(MatrixGraph G)//非连通图深度遍历
{
    int i;
    int * visited=(int *)malloc(sizeof(int)*G.Vertices.size);
    for(i=0; i<G.Vertices.size; i++)
        visited[i]=0;//初始化数组
    for(i=0; i<G.Vertices.size; i++) //保证每个顶点都能遍历到，只要没标记过就执行连通图的深度遍历
        if(!visited[i])
            DepthFSearch(G,i,visited);
    free(visited);
}
void BroadFSearch(MatrixGraph G,int v,int visited[])//连通图广度遍历
{
    ElemType u,w;
    SequenceQueue queue;
    printf("%c  ",G.Vertices.list[v]);//输出开始遍历的顶点
    visited[v]=1;//标记该顶点
    QueueInitiate(&queue);
    QueueAppend(&queue,v);
    while(QueueNotEmpty(queue))//只要队列不为空就继续遍历
    {
        QueueDelete(&queue,&u);
        w=GetFirstVex(G,u);//取当前顶点的第一个邻接结点的位置
        while(w!=-1) //只要还有未标记邻接顶点就不断进行输出与入队
        {
            if(!visited[w])
            {
                printf("%c  ",G.Vertices.list[w]);
                visited[w]=1;
                QueueAppend(&queue,w);
            }
            w=GetNextVex(G,u,w);

        }
    }
}//利用队列结构可以保证顶点的准确输出顺序
void BroadFirstSearch(MatrixGraph G)//非连通图的广度遍历
{
    int i;
    int *visited=(int*)malloc(sizeof(int)*G.Vertices.size);
    for(i=0; i<G.Vertices.size; i++)
        visited[i]=0;//初始化
    for(i=0; i<G.Vertices.size; i++) //只要没有标记过就执行连通图的广度遍历，保证每个顶点都被遍历到
        if(!visited[i])
            BroadFSearch(G,i,visited);
    free(visited);
}
void Dijkstra(MatrixGraph G,int v0,int distance[],int path[])//v0表示从哪个顶点开始寻找，distance表示最短路径权值之和的数组，path表示从哪个顶点来到当前顶点 
{
    int n=G.Vertices.size;
    int *s=(int *)malloc(sizeof(int)*n); //用于记录是否已找到最佳路径 
    int minDis,i,j,u;
    for(i=0; i<n; i++)
    {
        distance[i]=G.edge[v0][i];//把出发顶点与各顶点的权值赋给distance，表示从此顶点出发寻找路径 
        s[i]=0;
        if(i!=v0&&distance[i]<MaxWeight)//只有与当前顶点有权值的才能赋值当前结点下标 
            path[i]=v0;
        else
            path[i]=-1;
    }
    s[v0]=1;
    for(i=1; i<n; i++)
    {
        minDis=MaxWeight;
        for(j=0; j<=n; j++)//在还没找到最短路径的顶点中选取最短的顶点 
            if(s[j]==0&&distance[j]<minDis)
            {
                u=j;
                minDis=distance[j];
            }
        if(minDis==MaxWeight) 
            return;
        s[u]=1;//所找的顶点标记表明已找到 （因为每次都是在distance中找最短，所以一旦找到，则表明此顶点一定是最短的，就可以标记已找到） 
        for(j=0; j<n; j++)
            if(s[j]==0&&G.edge[u][j]<MaxWeight&&distance[u]+G.edge[u][j]<distance[j])//找未被标记且与u与j之间有权值的路径 ，并且u与j的权值加上当前distance[u]比 distance[i]小时，对路径进行更新 
            {
                distance[j]=distance[u]+G.edge[u][j];//找到后 ，将源点到u再到其他顶点的最短路径赋值给distance 
                path[j]=u;//将u的下标赋值给j的path，表示来自于u 
            }
    }
   

}
