#include <iostream>
#include <queue> 
#include <vector> 
using namespace std;
int main()
{
	priority_queue<int,vector<int>,less<int> >que1;//�������Ӵ�С���� 
	priority_queue<int,vector<int>,greater<int> >que2;//��������С�������� 
	que1.push(1);
	que1.push(5);
	que1.push(3);
	que1.push(2);
	que1.push(4);
	que2.push(1);
	que2.push(5);
	que2.push(3);
	que2.push(2);
	que2.push(4);
	cout<<"que1: ";
	while(!que1.empty())
	{
		cout<<que1.top()<<" ";
		que1.pop();
	}
	cout<<endl;
	cout<<"que2: ";
	while(!que2.empty())
	{
		cout<<que2.top()<<" ";
		que2.pop();
	}
	cout<<endl;
	return 0;
}   


/*
���ȶ�����ͷ�ļ�#include <queue>�У�

��������ʽΪ��priority_queue <int> ans;����һ����Ϊans�����ε����ȶ���

���ȶ��еļ��ֲ�����
1.��� q.push();

2.���� q.pop();

3.�������Ԫ�ظ��� q.size();

4.�ж϶����Ƿ�Ϊ�� q.empty();��Ϊ�շ���true�����򷵻�false

5.�����Ԫ�� q.top();

6.����q�ĵ�һ��Ԫ�� ?q.top();

7.����q��ĩβԪ��?q.back();
*/ 
