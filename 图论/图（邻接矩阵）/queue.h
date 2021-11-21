#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
# define MaxQueueSize 50//最大队列元素个数
typedef struct
{
    ElemType queue[MaxQueueSize];
    int front;
    int count;
} SequenceQueue;
void QueueInitiate(SequenceQueue*Q)//初始化
{
    Q->front=0;
    Q->count=0;
}
int QueueNotEmpty(SequenceQueue Q)//判断是否为空
{
    if(Q.count==0)
        return 0;
    else
        return 1;
}
int QueueAppend(SequenceQueue*Q,ElemType x)//元素入队列
{
    if(Q->count>0&&Q->front==(Q->front+Q->count)%MaxQueueSize)//利用头指针与计数器相加对元素最大数求余即可得到尾指针的位置
    {
        printf("队列已满无法插入！\n");
        return 0;
    }
    else

    {
        Q->queue[(Q->front+Q->count)%MaxQueueSize]=x;//队尾入队
        Q->count++;
        return 1;
    }
}
int QueueDelete(SequenceQueue*Q,ElemType *d)//元素出队
{
    if(Q->count==0)
    {
        printf("循环队列已空无数据元素出队列！\n");
        return 0;
    }
    else
    {
        *d=Q->queue[Q->front];
        Q->front=(Q->front+1)%MaxQueueSize;//头指针指向下一个元素
        Q->count--;
        return 1;
    }
}

#endif // QUEUE_H_INCLUDED
