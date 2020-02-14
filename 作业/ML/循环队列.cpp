#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define MAXQSIZE 10//最长队列长度
#define OVERFLOW 1

typedef struct
{
    int *base;//初始化的动态分配空间
    int front;//队头元素
    int rear;//队尾元素的下一个位置

}SQueue;

//初始化空队列
int InitQueue(SQueue *Q)
{
    Q->base = (int *)malloc(MAXQSIZE *sizeof(int));
    if(!Q->base)//存储分配失败
        exit(OVERFLOW);
    Q->rear = 0 ;
    Q->front = Q->rear;
    return OK;
}

//求队列的长度
int QueueLength(SQueue *Q)
{
    int n;
    n = (Q->rear-Q->front + MAXQSIZE)%MAXQSIZE;
    return n;
}

//插入
int  InsertQueue(SQueue *Q, int n)
{
    if ((Q->rear+1)%MAXQSIZE == Q->front)//队列满
        printf("The queue is full\n");
    Q->base[Q->rear] = n;
    Q->rear = (Q->rear+1)%MAXQSIZE;
    return 0;
}

//删除
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
 
/*队列的特点是遵循先进先出的原则，
在一端进行插入在另一端进行删除，
允许插入的一端是队尾，允许删除的一端是队头。
循环队列是队列的顺序化实现方式。
将主要包括初始化、入队、出队、求队列元素个数的操作。


1）循环队列的顺序存储结构的数据结构定义
2）初始化循环队列
3）往循环队列中插入元素--入队
4）删除循环队列中的元素--出队
5）求循环队列的实际长度
*/

