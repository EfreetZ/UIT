#include<iostream>
#include<iomanip>
using namespace std;
typedef struct node
{
	int figure;
	struct node *next;
}Node,*NOde;
NOde space()//����ջ���ռ� 
{
	NOde top;
	top=new Node;
	top->next=NULL; 
	return top;
}
NOde Incoming_stack(NOde top)//��ջ 
{
	NOde p;
	Node s;
	cout<<"��ִ����ջ�������������֣�����0������"<<endl;
	while(1)
	{
	p=new Node;
	cin>>s.figure;
	if(s.figure!=0)
	{
		top->figure=s.figure;
		p->next=top;
		top=p;
	}
	else
		break;
	}
	return top->next;	
}
NOde Incoming_stack2(NOde top1,NOde top2)//��ջ
{
	NOde p;
	while(top1)
	{
		p=new Node;
		top2->figure=top1->figure;
		p->next=top2;
		top2=p;
		top1=top1->next ;
	}
	return top2->next;
}
void deliver_from_godown(NOde top)//��ջ 
{
	NOde s;
	cout<<"��ǰ������Ԫ��Ϊ��"; 
	while(top!=NULL)
	{
		s=top;
		cout<<top->figure<<setw(6);
		top=top->next;
		delete s;//�����˿ռ� 
	}
	cout<<endl;
	return;
}

int main()
{
	NOde top1,top2; 
	top1=space();//����ջ���ռ�
	top2=space();
	top1=Incoming_stack(top1);//��ջ 
	top2=Incoming_stack2(top1,top2);
 	deliver_from_godown(top2);//��ջ 
 	system("pause");
	return 0;
}
