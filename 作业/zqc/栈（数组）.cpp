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
	T* m_array;		//����
	int m_nSize;	//Ԫ������
	int m_Capacity; //��������
};
template<class T>			
ArrayStack<T>::ArrayStack(int Capacity) //����
	:m_Capacity(Capacity),
	m_nSize(0),
	m_array(NULL)
	{
		m_array = new T[m_Capacity];
	}
template<class T>
ArrayStack<T>::~ArrayStack()   //����
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
		cout << "ջ���ˣ���ջʧ�ܡ�" << endl;
		return;
	}
	m_array[m_nSize++] = t;
	cout << "��ջ�ɹ���" << "\n";
}template<class T>
void ArrayStack<T>::Pop()		//Pop
{
	if (!IsEmpty())
	{
		m_array[m_nSize--];
		cout << "\t" << "����Ϊ:" << "\t" << GetSize()+1 << "." << endl;
	}
	else
	{
		cout << "\n" << "���Ȳ�����ɾ��ʧ�ܡ�" << endl;
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
		cout << "GetTopElement �ɹ�" << endl;
		return m_array[m_array - 1];
	}
	else
	{
		cout << "GetTopElement ʧ��" << endl;
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
	int Capacity = 7;				// Ĭ���߸�
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
		cout << "\n" << "ջΪ�ա�" << endl;
	}
	else
	{
		cout << "\n" << "ջ�ǿա�" << endl;
	}
	cout << "\n" << "ջ�ĳ���Ϊ�� " << " " << arrStack.GetSize() << "\n" << endl;
	arrStack.Show();
	for (int i = 0; i < 7; i++)
	{
		arrStack.Pop();
		arrStack.Show();
	}
	return 0;
}
