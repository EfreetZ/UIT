#include <iostream>
using namespace std;
class A
{
public:
	int num;
	A()
	{
		num=100;
		cout<<"A"<<endl;
	}
	~A()
	{
		cout<<"~A"<<endl;
	}
 
 
};
 
class B:virtual public A //��̳�
{
public: 
	B()
	{
		cout<<"B"<<endl;
	}
	~B()
	{
		cout<<"~B"<<endl;
	}
};
 
class C:virtual public A //��̳� 
{
public: 
	C()
	{
		cout<<"C"<<endl;
	}
	~C()
	{
		cout<<"~C"<<endl;
	}
};
class D:public B,public C
{
public: 
	D()
	{
		cout<<"D"<<endl;
	}
	~D()
	{
		cout<<"~D"<<endl;
	}
};
int main()
{
	D d;
	cout<<d.num<<endl;
	system("pause");
	return 0;
}
//�����������������һЩ���⣬û��virtualǰ��cout<<d.num<<endl;����error:���ʲ���ȷ��
//csdn�Ͻ������ֽ�������� 
//��һ�ַ���������ı�������������������壺
//cout<<d.B::num<<endl;
//cout<<d.C::num<<endl;
//�ڶ��ַ���������virtual�󣬾�û�������ˣ�B��C��ָ��ͬһ��A��
