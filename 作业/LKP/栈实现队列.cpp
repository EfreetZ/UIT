#include<iostream>
#include<iomanip>
using namespace std;
typedef struct node
{
	int figure;
	struct node *next;
}Node,*NOde;
NOde space()//分配栈顶空间 
{
	NOde top;
	top=new Node;
	top->next=NULL; 
	return top;
}
NOde Incoming_stack(NOde top)//入栈 
{
	NOde p;
	Node s;
	cout<<"将执行入栈操作请输入数字，输入0将结束"<<endl;
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
NOde Incoming_stack2(NOde top1,NOde top2)//入栈
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
void deliver_from_godown(NOde top)//出栈 
{
	NOde s;
	cout<<"当前队列中元素为："; 
	while(top!=NULL)
	{
		s=top;
		cout<<top->figure<<setw(6);
		top=top->next;
		delete s;//撤销此空间 
	}
	cout<<endl;
	return;
}

int main()
{
	NOde top1,top2; 
	top1=space();//分配栈顶空间
	top2=space();
	top1=Incoming_stack(top1);//入栈 
	top2=Incoming_stack2(top1,top2);
 	deliver_from_godown(top2);//出栈 
 	system("pause");
	return 0;
}
