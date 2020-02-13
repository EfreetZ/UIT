#include<iostream>
#include<iomanip>
using namespace std;
typedef struct node
{
	int *a;
	int front;
	int rear;
}Node,*NOde;
int QueueLength(NOde q)//求队列的长度 
{
	return (q->rear-q->front+6)%6;
}
NOde EnQueue(NOde q)//入队 
{
	int e;
		while(1)
	{
		if((q->rear+1)%6==q->front)//判断队列是否满 
		{
		cout<<"队列已满"<<endl;
		return q;
		}
		cin>>e;
		if(e==0)
		break;
		q->a[q->rear]=e;
		q->rear=(q->rear+1)%6;
		
	}
	
	return q;
}
void DeQueue(NOde q)//出队 
{
	int e;
	while(q->front!=q->rear)//判断队列是否为空 
	{
		e=q->a[q->front];
		q->front=(q->front+1)%6;
		cout<<e<<setw(6);
	}
	return;
}
NOde DeQueue2(NOde q)//对头元素 
{
	int e;
	if(q->front!=q->rear)//判断队列是否为空 
	{
		e=q->a[q->front];
		q->front=(q->front+1)%6;
		cout<<e<<setw(6);
	}
	return q;
}
int main()
{
	NOde q;
	char i;
	q=new Node;
	q->a=new int[6];
	q->front=q->rear=0;
	cout<<"本循环队列空间为6，占用5个空间判定为满"<<endl;
	cout<<"输入队列的数字为0时结束输入"<<endl<<"请输入要入队的数字:";
	while(1)
	{
		fflush(stdin); 
		q=EnQueue(q);//入队
		cout<<"队列的长度为："<<QueueLength(q)<<endl;//求队列的长度
		cout<<"队列的对头为：";
		q=DeQueue2(q);
		cout<<"此时对头已删除"<<endl; 
		while(1)
		{
			cout<<"Y是，N不是"<<"是否又重新输入：";
			cin>>i;
			if(i=='N'||i=='Y')
			break;
		}
		if(i=='N')
		break;
	 } 
	cout<<"队列的全部元素：";
	DeQueue(q);//出队
	return 0;
}
