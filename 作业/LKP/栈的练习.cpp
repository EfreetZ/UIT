#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
typedef struct node
{
	int figure;
	struct node *next;
}Node,*NOde;
NOde Incoming_stack(NOde top,int e)//��ջ 
{

	NOde p;
	p=new Node;
	top->figure=e;
	p->next=top;
	top=p;
	return top;	
}
NOde deliver_from_godown(NOde top)//��ջ 
{
		NOde s; 
		s=top;
		cout<<top->next->figure<<setw(6);
		top=top->next;
		delete s;//�����˿ռ� 
		return top;
}
int main()
{
	string string1;
	cin>>string1;//�����ַ���
	NOde top;
	top=new Node;
	top->next=NULL;
	int length,a[10],j=0;
	length=string1.length();//�ַ������� 
	for(int i=0;i<length;i++)
	{
		if(string1[i]=='(')
		{
		top=Incoming_stack(top,i+1);	
		}
		else if(string1[i]==')')
		{
			if(top->next!=NULL)
			{
				top=deliver_from_godown(top); 
				cout<<i+1<<endl;
			}
			else
			{
				a[j]=i+1;
				j++;
			}
		}
	}
	if(j!=0||top->next!=NULL)//�ж��Ƿ���δ����� 
	{
		for(int k=0;k<j;k++)
		cout<<a[k]<<setw(6);
		while(top->next!=NULL)
		top=deliver_from_godown(top);
		cout<<"δ����"<<endl;
	}
	
 	system("pause");
	return 0;
}
