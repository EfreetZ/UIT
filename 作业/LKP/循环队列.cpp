#include<iostream>
#include<iomanip>
using namespace std;
typedef struct node
{
	int *a;
	int front;
	int rear;
}Node,*NOde;
int QueueLength(NOde q)//����еĳ��� 
{
	return (q->rear-q->front+6)%6;
}
NOde EnQueue(NOde q)//��� 
{
	int e;
		while(1)
	{
		if((q->rear+1)%6==q->front)//�ж϶����Ƿ��� 
		{
		cout<<"��������"<<endl;
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
void DeQueue(NOde q)//���� 
{
	int e;
	while(q->front!=q->rear)//�ж϶����Ƿ�Ϊ�� 
	{
		e=q->a[q->front];
		q->front=(q->front+1)%6;
		cout<<e<<setw(6);
	}
	return;
}
NOde DeQueue2(NOde q)//��ͷԪ�� 
{
	int e;
	if(q->front!=q->rear)//�ж϶����Ƿ�Ϊ�� 
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
	cout<<"��ѭ�����пռ�Ϊ6��ռ��5���ռ��ж�Ϊ��"<<endl;
	cout<<"������е�����Ϊ0ʱ��������"<<endl<<"������Ҫ��ӵ�����:";
	while(1)
	{
		fflush(stdin); 
		q=EnQueue(q);//���
		cout<<"���еĳ���Ϊ��"<<QueueLength(q)<<endl;//����еĳ���
		cout<<"���еĶ�ͷΪ��";
		q=DeQueue2(q);
		cout<<"��ʱ��ͷ��ɾ��"<<endl; 
		while(1)
		{
			cout<<"Y�ǣ�N����"<<"�Ƿ����������룺";
			cin>>i;
			if(i=='N'||i=='Y')
			break;
		}
		if(i=='N')
		break;
	 } 
	cout<<"���е�ȫ��Ԫ�أ�";
	DeQueue(q);//����
	return 0;
}
