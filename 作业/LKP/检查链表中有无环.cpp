#include<iostream>
using namespace std;
typedef struct node
{
	int i;
	struct node *next;
}Node,*NOde;
NOde space(NOde head)//����ռ� 
{
	head=new Node;
	return head;
}
NOde one(NOde head)//������ 
{
	NOde q,p=head;
	int i=1;
	while(1)
	{	
		q=new Node;
		q->i =i;
		p->next =q;
		p=q;
		i++;
		if(i==6)
		break;
	}
	p->next =NULL;
	return head;
}
NOde two(NOde head)//ѭ������ 
{
	NOde q,p=head;
	int i=1;
	while(1)
	{	
		q=new Node;
		q->i =i;
		p->next =q;
		p=q;
		i++;
		if(i=6)
		break;
	}
	p->next =head;
	return head;
}
int check(NOde head)//����Ƿ��л� 
{
	if(!head)
	return 0;
	NOde one=head,two=head;
	while(1)
	{
		one=one->next ;
		two=two->next ;
		if(!two||!two->next )
		return 0;
		two=two->next ;
		if(one==two)
		return 1;
	}
}
 
int main()
{
	NOde head1,head2;
	head1=space(head1);
	head2=space(head2);
	head1=one(head1);
	head2=two(head2);
	if(check(head1))
	cout<<"head1�������л�"<<endl;
	else
	cout<<"head1�������޻�"<<endl;
	 if(check(head2))
	cout<<"head2�������л�"<<endl;
	else
	cout<<"head2�������޻�"<<endl;
	system("pause");
	return 0;
}
