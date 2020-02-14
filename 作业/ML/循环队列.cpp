#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define MAXQSIZE 10//����г���
#define OVERFLOW 1

typedef struct
{
    int *base;//��ʼ���Ķ�̬����ռ�
    int front;//��ͷԪ��
    int rear;//��βԪ�ص���һ��λ��

}SQueue;

//��ʼ���ն���
int InitQueue(SQueue *Q)
{
    Q->base = (int *)malloc(MAXQSIZE *sizeof(int));
    if(!Q->base)//�洢����ʧ��
        exit(OVERFLOW);
    Q->rear = 0 ;
    Q->front = Q->rear;
    return OK;
}

//����еĳ���
int QueueLength(SQueue *Q)
{
    int n;
    n = (Q->rear-Q->front + MAXQSIZE)%MAXQSIZE;
    return n;
}

//����
int  InsertQueue(SQueue *Q, int n)
{
    if ((Q->rear+1)%MAXQSIZE == Q->front)//������
        printf("The queue is full\n");
    Q->base[Q->rear] = n;
    Q->rear = (Q->rear+1)%MAXQSIZE;
    return 0;
}

//ɾ��
int DeleteQueue(SQueue *Q)
{
    int n;
    if (Q->front == Q->rear)
        printf("The queue is empty\n");
    n = Q->base[Q->front];
    Q->front = (Q->front+1)%MAXQSIZE;
    return n;
}


int main()
{
    SQueue *Q;
    int k,n;
    Q=(SQueue *)malloc(sizeof(SQueue));
    InitQueue(Q);
    int quit=1;
    while(quit==1)
    {
        printf("1.Insert 2.Delete 3.Length \n");
        scanf("%d",&k);
        getchar();
        switch(k)
        {
            case 1:
                printf("Insert number \n");
                scanf("%d",&n);
                InsertQueue(Q,n);
                break;

            case 2:
                printf("Delete number is %d\n",DeleteQueue(Q));
                break;
            case 3:
                printf("%d\n",QueueLength(Q));
                break;
        }
    }
    return 0;
}
 
/*���е��ص�����ѭ�Ƚ��ȳ���ԭ��
��һ�˽��в�������һ�˽���ɾ����
��������һ���Ƕ�β������ɾ����һ���Ƕ�ͷ��
ѭ�������Ƕ��е�˳��ʵ�ַ�ʽ��
����Ҫ������ʼ������ӡ����ӡ������Ԫ�ظ����Ĳ�����


1��ѭ�����е�˳��洢�ṹ�����ݽṹ����
2����ʼ��ѭ������
3����ѭ�������в���Ԫ��--���
4��ɾ��ѭ�������е�Ԫ��--����
5����ѭ�����е�ʵ�ʳ���
*/

