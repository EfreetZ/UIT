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
void deliver_from_godown(NOde top)//��ջ 
{
	NOde s;
	cout<<"��ǰջ��Ԫ��Ϊ��"; 
	while(top!=NULL)
	{
		s=top;
		cout<<top->figure<<setw(6);
		top=top->next;
		delete s;//�����˿ռ� 
	}
	return;
}
NOde stack_top(NOde top)//ջ��Ԫ�� 
{
	NOde s=top;
	if(top!=NULL)
	{
		cout<<"��ǰջ��Ԫ��Ϊ��"<<top->figure<<endl; 
		top=top->next;
		delete s;//�����˿ռ� 
	}
	else
	cout<<"ջ��û��Ԫ��"<<endl;
	return top;
}
void Get_the_number(NOde top)//��ȡջ��Ԫ�ظ��� 
{
	int number=0;
	while(top!=NULL)//�ж�ջ�Ƿ�Ϊ�� 
	{
		number++;
		top=top->next;
	 } 
	 cout<<"ջ��Ԫ�ظ���Ϊ��"<<number<<endl;
	 return;
}
int main()
{
	NOde top; 
	top=space();//����ջ���ռ�
	top=Incoming_stack(top);//��ջ 
	Get_the_number(top);//��ȡջ��Ԫ�ظ���
	top=stack_top(top);//ջ��Ԫ��
 	deliver_from_godown(top);//��ջ 
 	system("pause");
	return 0;
}
