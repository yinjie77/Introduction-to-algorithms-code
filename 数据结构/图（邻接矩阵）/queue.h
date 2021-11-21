#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
# define MaxQueueSize 50//������Ԫ�ظ���
typedef struct
{
    ElemType queue[MaxQueueSize];
    int front;
    int count;
} SequenceQueue;
void QueueInitiate(SequenceQueue*Q)//��ʼ��
{
    Q->front=0;
    Q->count=0;
}
int QueueNotEmpty(SequenceQueue Q)//�ж��Ƿ�Ϊ��
{
    if(Q.count==0)
        return 0;
    else
        return 1;
}
int QueueAppend(SequenceQueue*Q,ElemType x)//Ԫ�������
{
    if(Q->count>0&&Q->front==(Q->front+Q->count)%MaxQueueSize)//����ͷָ�����������Ӷ�Ԫ����������༴�ɵõ�βָ���λ��
    {
        printf("���������޷����룡\n");
        return 0;
    }
    else

    {
        Q->queue[(Q->front+Q->count)%MaxQueueSize]=x;//��β���
        Q->count++;
        return 1;
    }
}
int QueueDelete(SequenceQueue*Q,ElemType *d)//Ԫ�س���
{
    if(Q->count==0)
    {
        printf("ѭ�������ѿ�������Ԫ�س����У�\n");
        return 0;
    }
    else
    {
        *d=Q->queue[Q->front];
        Q->front=(Q->front+1)%MaxQueueSize;//ͷָ��ָ����һ��Ԫ��
        Q->count--;
        return 1;
    }
}

#endif // QUEUE_H_INCLUDED
