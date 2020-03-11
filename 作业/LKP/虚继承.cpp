/*如果一个基类派生出很多派生类，这些派生类又共同派生出一个派生类，会导致最后派生类间接继承多次基类
虚基类，使得在继承间接共同基类时只保留一份成员
避免出现二义性
*/
#include<iostream>
using namespace std;
class A
{
public:
	A(int j) { i = j; }//构造函数
	~A(){}
	void f()//输出i
	{
		cout << i << endl;
	}
private :
	int i;
};
class B :virtual public A//虚继承
{
public:
	B(int k) : A (k)//构造函数
	{
	}
};
class C : virtual public A//虚继承
{
public:
	C(int k) :A(k)//构造函数
	{
	}
};
class D :public B, public C
{
public:
	D(int k) :A(k), B(k), C(k){}//构造函数

};
int main()
{
	D sum = { 57 };
	sum.f();
	return 0;
}