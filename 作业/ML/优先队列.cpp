#include <iostream>
#include <queue> 
#include <vector> 
using namespace std;
int main()
{
	priority_queue<int,vector<int>,less<int> >que1;//输出结果从大到小排序 
	priority_queue<int,vector<int>,greater<int> >que2;//输出结果从小到大排序 
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
优先队列在头文件#include <queue>中；

其声明格式为：priority_queue <int> ans;声明一个名为ans的整形的优先队列

优先队列的几种操作：
1.入队 q.push();

2.出队 q.pop();

3.求队列中元素个数 q.size();

4.判断度列是否为空 q.empty();若为空返回true，否则返回false

5.获得首元素 q.top();

6.返回q的第一个元素 ?q.top();

7.返回q的末尾元素?q.back();
*/ 
