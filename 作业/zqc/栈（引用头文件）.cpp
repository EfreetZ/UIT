#include<iostream>
#include<stack>
using namespace std;
int main(void)
{	
	stack<float>s;//����һ��ջ	
	int temp;
	for(int i=0;i<10;i++)
	{
		cin>>temp; 
		s.push(temp);
		cout<<"ջ�ڵ�Ԫ�صĸ���Ϊ��"<<s.size()<<endl;
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
	cout<<"ջ�ڵ�Ԫ�صĸ���Ϊ��"<<s.size()<<endl;
	if(!s.empty())
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
