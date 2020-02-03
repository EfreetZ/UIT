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
void deliver_from_godown(NOde top)//出栈 
{
	NOde s;
	cout<<"当前栈中元素为："; 
	while(top!=NULL)
	{
		s=top;
		cout<<top->figure<<setw(6);
		top=top->next;
		delete s;//撤销此空间 
	}
	return;
}
NOde stack_top(NOde top)//栈顶元素 
{
	NOde s=top;
	if(top!=NULL)
	{
		cout<<"当前栈顶元素为："<<top->figure<<endl; 
		top=top->next;
		delete s;//撤销此空间 
	}
	else
	cout<<"栈顶没有元素"<<endl;
	return top;
}
void Get_the_number(NOde top)//获取栈中元素个数 
{
	int number=0;
	while(top!=NULL)//判断栈是否为空 
	{
		number++;
		top=top->next;
	 } 
	 cout<<"栈中元素个数为："<<number<<endl;
	 return;
}
int main()
{
	NOde top; 
	top=space();//分配栈顶空间
	top=Incoming_stack(top);//入栈 
	Get_the_number(top);//获取栈中元素个数
	top=stack_top(top);//栈顶元素
 	deliver_from_godown(top);//出栈 
 	system("pause");
	return 0;
}
