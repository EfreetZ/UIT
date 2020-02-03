#include<iostream>
using namespace std;
template<class T>
class ArrayStack
{
public:
	ArrayStack(int Capacity = 5);
	~ArrayStack();

public:
	void Push(T t);
	void Pop();
	int GetSize();
	bool IsEmpty();
	T GetTopElement();
	void Show();
private:
	T* m_array;		//数组
	int m_nSize;	//元素数量
	int m_Capacity; //容器容量
};
template<class T>			
ArrayStack<T>::ArrayStack(int Capacity) //构造
	:m_Capacity(Capacity),
	m_nSize(0),
	m_array(NULL)
	{
		m_array = new T[m_Capacity];
	}
template<class T>
ArrayStack<T>::~ArrayStack()   //析构
{
	if (m_array)
	{
		delete[] m_array;
		m_array = NULL;
	}
}
template<class T>
void ArrayStack<T>::Push(T t) //Push
{
	if (GetSize() >= m_Capacity)
	{
		cout << "栈满了，入栈失败。" << endl;
		return;
	}
	m_array[m_nSize++] = t;
	cout << "入栈成功。" << "\n";
}template<class T>
void ArrayStack<T>::Pop()		//Pop
{
	if (!IsEmpty())
	{
		m_array[m_nSize--];
		cout << "\t" << "长度为:" << "\t" << GetSize()+1 << "." << endl;
	}
	else
	{
		cout << "\n" << "长度不够，删除失败。" << endl;
	}
}
template <class T>
int ArrayStack<T>::GetSize()		// GetSize
{
	return m_nSize;
}
template <class T>
bool ArrayStack<T>::IsEmpty()	 //IsEmpty
{
	return m_nSize == 0;
}
template<class T>
T ArrayStack<T>::GetTopElement()	//GetTopElement
{
	if (m_nSize > 0)
	{
		cout << "GetTopElement 成功" << endl;
		return m_array[m_array - 1];
	}
	else
	{
		cout << "GetTopElement 失败" << endl;
		return T(NULL);
	}
}
template<class T>
void ArrayStack<T>::Show()		//Show
{
	int nSize = GetSize();
	for (int i = 0; i < nSize; i++)
	{
		cout << m_array[i] << "  ";
	}
}
int main()
{
	int Capacity = 7;				// 默认七个
	ArrayStack<int> arrStack(Capacity);
	int temp;
	for (int i = 0; i < Capacity; i++)
	{
		cin >> temp;
		arrStack.Push(temp);
	}
	arrStack.Show();
	if (arrStack.IsEmpty())
	{
		cout << "\n" << "栈为空。" << endl;
	}
	else
	{
		cout << "\n" << "栈非空。" << endl;
	}
	cout << "\n" << "栈的长度为： " << " " << arrStack.GetSize() << "\n" << endl;
	arrStack.Show();
	for (int i = 0; i < 7; i++)
	{
		arrStack.Pop();
		arrStack.Show();
	}
	return 0;
}
