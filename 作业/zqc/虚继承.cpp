#include <iostream>
#include <stdio.h>
class A{
	public:
	void a() {
	printf("UIT.");
	}
};
class B : virtual public A{ 
};
class C : virtual public A{
};
class D : public B, public C{
};
int main()
{
	D d;
	d.a();
	return 0;
}/* 虚继承可以解决多种继承中的两个问题：其一是浪费存储空间，其二是存在二义性问题 */ 
