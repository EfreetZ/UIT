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
 
class B:virtual public A //虚继承
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
 
class C:virtual public A //虚继承 
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
//在最后主函数里会出现一些问题，没加virtual前；cout<<d.num<<endl;出现error:访问不明确；
//csdn上教了两种解决方法： 
//第一种方案：清楚的表明作用域，以免出现歧义：
//cout<<d.B::num<<endl;
//cout<<d.C::num<<endl;
//第二种方案：加上virtual后，就没有歧义了，B和C都指向同一份A；
