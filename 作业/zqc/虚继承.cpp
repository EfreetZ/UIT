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
}/* ��̳п��Խ�����ּ̳��е��������⣺��һ���˷Ѵ洢�ռ䣬����Ǵ��ڶ��������� */ 
