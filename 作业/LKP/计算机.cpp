#include<iostream>
#include<string> 
using namespace std;
#define  SIZE 1000
class compute
{
public:
	compute() { ctop = -1, itop = -1, k = 1, j = -1; };
	~compute(){}
	void print();//输入
	void resolve();//分解
	void pull2();//输出数值
private:
	string str;
	char str1[SIZE];
	int ctop;
	double count[SIZE];
	int itop;
	double k ;
	double j;
	void push(double i);
	void push(char i);
	double pull();//出栈
	char pull1();
	void ride();//乘
	void get_rid_of();//除
	void add();//加
	void subtract();//减
	void F();//对符号栈中还有的数据处理
};

void compute::print()//输入
{
	cin >> str;
}
void compute::resolve()//分解
{
	int i;
	for (i = 0; i < str.length(); i++)
	{
		
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
		{

			if (j == -1)
			{
				j = 0;
			}
			if (str[i] == '.')
			{
				i++;
				k = 1;
				while (str[i] >= '0' && str[i] <= '9')
				{
					k = k*0.1;
					j = j + (str[i]-'0') * k;
					i++;
				}
				i--;
			}
			else
			{
				j = j * 10 + str[i] - '0';
			}
			
			
		}
		else if (str[i] == '(')
		{
			if (j != -1)
			{
				push(j);
			}
			push(str[i]);
		}
		else if ( str[i] == '*' || str[i] == '/'  )
		{
			if (j != -1)
			{
				push(j);
			}
			while ((str1[ctop] == '*' || str1[ctop] == '/') && str1[ctop] != '('&& ctop!=-1)
			{
				char t = str1[ctop--];
				if (t == '*')
				{
					ride();
				}
				else if (t == '/')
				{
					get_rid_of();
				}
			}
			push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			if (j != -1)
			{
				push(j);
			}
			while ((ctop != -1)&&(str1[ctop] != '('))
			{
				char t = str1[ctop--];
				if (t == '*')
				{
					ride();
				}
				else if (t == '/')
				{
					get_rid_of();
				}
				else if (t == '+')
				{
					add();
				}
				else if (t == '-')
				{
					subtract();
				}
			}
				push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (j != -1)
			{
				push(j);
			}
			while (str1[ctop] != '(')
			{
				char t = str1[ctop--];
				if (t == '*')
				{
					ride();
				}
				else if (t == '/')
				{
					get_rid_of();
				}
				else if (t == '+')
				{
					add();
				}
				else if (t == '-')
				{
					subtract();
				}
			}
			ctop--;
		}
		
	}
	if (j != -1)
	{
		push(j);
	}
	F();
}
void compute::push(double i)//入栈
{
	k = 1,j=-1;
	count[++itop] = i;
	return;
}
void compute::push(char i)
{
	str1[++ctop] = i;
	return;
}
double compute::pull()
{
	return count[itop--];
}
char compute::pull1()
{
	return str1[ctop--];
}
void compute::ride()//乘
{
	double j;
	j = pull() * pull();
	push(j);
	return;
}
void compute::get_rid_of()//除
{
	double j, i = pull();
	j = pull() / i;
	push(j);
	return;
}
void compute::add()//加
{
	double count;
	count = pull() + pull();
	push(count);
	return;
}
void compute::subtract()//减
{
	double count,j;
	j = pull();
	count = pull() - j;
	push(count);
	return;
}
void compute::pull2()
{
	
	cout << count[itop--] << endl;

}
void compute::F()//对符号栈中还有的数据处理
{
	while (ctop != -1)
	{
		char t = str1[ctop--];
		if (t == '*')
		{
			ride();
		}
		else if (t == '/')
		{
			get_rid_of();
		}
		else if (t == '+')
		{
			add();
		}
		else if (t == '-')
		{
			subtract();
		}
	}
}
int main()
{
	compute i;
	while (1)
	{
		i.print();
		i.resolve();
		i.pull2();

	}
	
	return 0;
}



