#include<iostream>
#include<queue> 
using namespace std;
priority_queue<int>que;
int main()
{
	que.push(1);//����һ��Ԫ�� 
	que.push(3);
	que.push(5);
	que.push(4);
	que.push(2);
	cout<<"��������"<<que.size()<<"��Ԫ��"<<endl;//����Ԫ�ظ��� 
	while(!que.empty())//empty�ж��Ƿ�Ϊ�� 
	{
		cout<<que.top()<<endl;//�������ȶ��еĶԶ�Ԫ�� 
		que.pop();//ɾ���Զ�Ԫ�� 
	}
	return 0;
}
