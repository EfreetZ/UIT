#include<iostream>
#include<stack>
#include <string>
using namespace std;
int main(void)
{	
	int temp;
	int yesMate[10];
	int noMate[10];
	int j;
	int y_temp=0,n_temp=0;
	stack<char>s;//定义一个栈	
	stack<char>s1;
	std::string str;
	cin >> str;
	for(int i = 0; i < str.size(); i++) 
	{
		s.push(str[i]);
	}
	
	for(int i = str.size(); i >= 0; i--)	
	{		
		if(str[i]=='(')
		{
			s1.push(str[i]);
			for(j=i;j<str.size();j++)
			{
				if(str[j]==')')
				{
					s1.push(str[j]);
					str[j]='*';
					break;
				}
			}
			if(s1.top()==')')
			{
				yesMate[y_temp]=i+1;
				y_temp++;
				yesMate[y_temp]=j+1;
				y_temp++;
			}
			else
			{
				noMate[n_temp]=i+1;
				n_temp++;
			}
		}	
	}
	for(int i = str.size(); i >= 0; i--)
	{
		if(str[i]==')')
		{
			noMate[n_temp]=i+1;
			n_temp++;
			str[j]='*';
		}
	}
	for(int m=0;m<y_temp;m++)
	{
		printf("%d   ",yesMate[m]);
	}
	printf("\n");
	for(int m=0;m<n_temp;m++)
	{
		printf("%d   ",noMate[m]);
		temp=1;
	}
	if(temp==1)
	{
		printf(" 未匹配  ");
	}
	return 0;
}
