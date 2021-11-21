# include "SequenceList.h"
# include "queue.h"
# include <stdlib.h>
# define MaxVertices 100
# define MaxWeight 10000
typedef struct
{
    SequenceList Vertices;//��Ŷ���
    int edge[MaxVertices][MaxVertices];//��ű�
    int numOfEdges;//�ߵ�����
} MatrixGraph;
typedef struct
{
    int row;//��
    int col;//��
    int weight;//Ȩֵ
} RowColWeight;
void Initiate(MatrixGraph * G,int n)//ͼ��ʼ��
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
void InsertVertex(MatrixGraph * G,ElemType vertex)//���붥��
{
    ListInsert(&G->Vertices,G->Vertices.size,vertex);//��˳����в���
}
void InsertEdge(MatrixGraph * G,int v1,int v2,int weight)//�����
{
    if(v1<0||v1>=G->Vertices.size||v2<0||v2>=G->Vertices.size)
    {
        printf("����v1��v2Խ�����! \n");
        exit(1);
    }
    G->edge[v1][v2]=weight;
    G->numOfEdges++;
}
void DeleteEdge(MatrixGraph * G,int v1,int v2)//ɾ����
{
    if(v1<0||v1>=G->Vertices.size||v2<0||v2>=G->Vertices.size||v1==v2)
    {
        printf("����v1��v2Խ�����! \n");
        exit(1);
    }
    G->edge[v1][v2]=MaxWeight;
    G->numOfEdges--;
}
void DeleteVertex(MatrixGraph * G,int v)//ɾ������
{
    int n = ListLength(G->Vertices),i,j;
    ElemType x;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if((i==v||j==v)&&G->edge[i][j]>0&&G->edge[i][j]<MaxWeight)
                G->numOfEdges--;
    for(i=v; i<n; i++)//ɾ����v��
        for(j=0; j<n; j++)
            G->edge[i][j]=G->edge[i+1][j];
    for(i=0; i<n; i++)//ɾ����v��
        for(j=v; j<n; j++)
            G->edge[i][j]=G->edge[i][j+1];
    ListDelete(&G->Vertices,v,&x);//˳�����ɾ������

}
int GetFirstVex(MatrixGraph  G,int v)//ȡ��v�еĵ�һ����0����������
{
    int col;
    if(v<0||v>=G.Vertices.size)
    {
        printf("����vԽ�����! \n");
        exit(1);
    }
    for(col=0; col<G.Vertices.size; col++)
        if(G.edge[v][col]>0&&G.edge[v][col]<MaxWeight)
            return col;
    return -1;

}
int GetNextVex(MatrixGraph  G,int v1,int v2)//ȡv1�е�v2����һ������
{
    int col;
    if(v1<0||v1>=G.Vertices.size||v2<0||v2>=G.Vertices.size)
    {
        printf("����v1��v2Խ�����! \n");
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
    for(i=0; i<n; ++i) //���붥��
        InsertVertex(G,V[i]);
    for(k=0; k<e; k++) //�����
        InsertEdge(G,E[k].row,E[k].col,E[k].weight);
}
void DepthFSearch(MatrixGraph G,int v,int visited[])//��ͨͼ��ȱ���
{
    int w;
    printf("%c  ",G.Vertices.list[v]);//�����ǰ����
    visited[v]=1;//���˶�����
    w=GetFirstVex(G,v);//ȡ��һ���ڽӶ���
    while(w!=-1)//���ڽӶ���ͽ���ѭ��
    {
        if(!visited[w])//ֻҪû��ǹ��Ͷ�w�еļ���ִ����ȱ���
            DepthFSearch(G,w,visited);
        w=GetNextVex(G,v,w);
    }
}
void DepthFirstSearch(MatrixGraph G)//����ͨͼ��ȱ���
{
    int i;
    int * visited=(int *)malloc(sizeof(int)*G.Vertices.size);
    for(i=0; i<G.Vertices.size; i++)
        visited[i]=0;//��ʼ������
    for(i=0; i<G.Vertices.size; i++) //��֤ÿ�����㶼�ܱ�������ֻҪû��ǹ���ִ����ͨͼ����ȱ���
        if(!visited[i])
            DepthFSearch(G,i,visited);
    free(visited);
}
void BroadFSearch(MatrixGraph G,int v,int visited[])//��ͨͼ��ȱ���
{
    ElemType u,w;
    SequenceQueue queue;
    printf("%c  ",G.Vertices.list[v]);//�����ʼ�����Ķ���
    visited[v]=1;//��Ǹö���
    QueueInitiate(&queue);
    QueueAppend(&queue,v);
    while(QueueNotEmpty(queue))//ֻҪ���в�Ϊ�վͼ�������
    {
        QueueDelete(&queue,&u);
        w=GetFirstVex(G,u);//ȡ��ǰ����ĵ�һ���ڽӽ���λ��
        while(w!=-1) //ֻҪ����δ����ڽӶ���Ͳ��Ͻ�����������
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
}//���ö��нṹ���Ա�֤�����׼ȷ���˳��
void BroadFirstSearch(MatrixGraph G)//����ͨͼ�Ĺ�ȱ���
{
    int i;
    int *visited=(int*)malloc(sizeof(int)*G.Vertices.size);
    for(i=0; i<G.Vertices.size; i++)
        visited[i]=0;//��ʼ��
    for(i=0; i<G.Vertices.size; i++) //ֻҪû�б�ǹ���ִ����ͨͼ�Ĺ�ȱ�������֤ÿ�����㶼��������
        if(!visited[i])
            BroadFSearch(G,i,visited);
    free(visited);
}
void Dijkstra(MatrixGraph G,int v0,int distance[],int path[])//v0��ʾ���ĸ����㿪ʼѰ�ң�distance��ʾ���·��Ȩֵ֮�͵����飬path��ʾ���ĸ�����������ǰ���� 
{
    int n=G.Vertices.size;
    int *s=(int *)malloc(sizeof(int)*n); //���ڼ�¼�Ƿ����ҵ����·�� 
    int minDis,i,j,u;
    for(i=0; i<n; i++)
    {
        distance[i]=G.edge[v0][i];//�ѳ���������������Ȩֵ����distance����ʾ�Ӵ˶������Ѱ��·�� 
        s[i]=0;
        if(i!=v0&&distance[i]<MaxWeight)//ֻ���뵱ǰ������Ȩֵ�Ĳ��ܸ�ֵ��ǰ����±� 
            path[i]=v0;
        else
            path[i]=-1;
    }
    s[v0]=1;
    for(i=1; i<n; i++)
    {
        minDis=MaxWeight;
        for(j=0; j<=n; j++)//�ڻ�û�ҵ����·���Ķ�����ѡȡ��̵Ķ��� 
            if(s[j]==0&&distance[j]<minDis)
            {
                u=j;
                minDis=distance[j];
            }
        if(minDis==MaxWeight) 
            return;
        s[u]=1;//���ҵĶ����Ǳ������ҵ� ����Ϊÿ�ζ�����distance������̣�����һ���ҵ���������˶���һ������̵ģ��Ϳ��Ա�����ҵ��� 
        for(j=0; j<n; j++)
            if(s[j]==0&&G.edge[u][j]<MaxWeight&&distance[u]+G.edge[u][j]<distance[j])//��δ���������u��j֮����Ȩֵ��·�� ������u��j��Ȩֵ���ϵ�ǰdistance[u]�� distance[i]Сʱ����·�����и��� 
            {
                distance[j]=distance[u]+G.edge[u][j];//�ҵ��� ����Դ�㵽u�ٵ�������������·����ֵ��distance 
                path[j]=u;//��u���±긳ֵ��j��path����ʾ������u 
            }
    }
   

}
