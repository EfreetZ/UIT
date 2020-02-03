#include<iostream>
#include<stack>
using namespace std;
int main(void)
{	
	stack<float>s;//定义一个栈	
	int temp;
	for(int i=0;i<10;i++)
	{
		cin>>temp; 
		s.push(temp);
		cout<<"栈内的元素的个数为："<<s.size()<<endl;
	}
	if(!s.empty())
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;		
	while(!s.empty())	
	{		
		//printf("%.3f\n",s.top());	
		cout<<s.top()<<endl;
		s.pop();	
	}	
	cout<<"栈内的元素的个数为："<<s.size()<<endl;
	if(!s.empty())
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
