/*输入5 4 0 0 3 2 0 0 1 0 0
        5
		/\
	   4  3
	     / \
		2   1 
		输出45231*/
#include<iostream>
#include<string>
#define len 100
using namespace std;
typedef struct node
{
	char ch;
	struct node* lnext;//左
	struct node* rnext;//右
}Node,*NOde;
void found(NOde& t)
{
	char i;
	cin >> i;
	if (i == '0')
	{
		t = NULL;
	}
	else
	{
		t = new Node;
		t->ch = i;
		found(t->lnext);
		found(t->rnext);
	}
}
void out(NOde& t)//中序遍历
{
	if (t)
	{
		out(t->lnext );
		cout << t->ch;
		out(t->rnext);
	}
}
int main()
{
	NOde p;
	cout << "输入字符，输入0为一个子树结束语" << endl;
	found(p);
	out(p);
}
