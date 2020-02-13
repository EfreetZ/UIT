#include<iostream>
#include<queue> 
using namespace std;
priority_queue<int>que;
int main()
{
	que.push(1);//加入一个元素 
	que.push(3);
	que.push(5);
	que.push(4);
	que.push(2);
	cout<<"队列中有"<<que.size()<<"个元素"<<endl;//返回元素个数 
	while(!que.empty())//empty判断是否为空 
	{
		cout<<que.top()<<endl;//返回优先队列的对顶元素 
		que.pop();//删除对顶元素 
	}
	return 0;
}
