#include<iostream>
using namespace std;
template<class T>
class arrayStack
{
public:
	arrayStack(int capacity = 5);
	~arrayStack();

public:
	void push(T t);
	void pop();
	int getSize();
	bool isEmpty();
	T getTopElement();
	void show();
private:
	T* m_array;		//����
	int m_nSize;	//Ԫ������
	int m_Capacity; //��������
};
template<class T>			
arrayStack<T>::arrayStack(int capacity) //����
	:m_Capacity(capacity),
	m_nSize(0),
	m_array(NULL)
	{
		m_array = new T[m_Capacity];
	}
template<class T>
arrayStack<T>::~arrayStack()   //����
{
	if (m_array)
	{
		delete[] m_array;
		m_array = NULL;
	}
}
template<class T>
void arrayStack<T>::push(T t) //push
{
	if (getSize() >= m_Capacity)
	{
		cout << "ջ���ˣ���ջʧ�ܡ�" << endl;
		return;
	}
	m_array[m_nSize++] = t;
	cout << "��ջ�ɹ���" << "\n";
}template<class T>
void arrayStack<T>::pop()		//pop
{
	if (!isEmpty())
	{
		m_array[m_nSize--];
		cout << "\t" << "����Ϊ:" << "\t" << getSize()+1 << "." << endl;
	}
	else
	{
		cout << "\n" << "���Ȳ�����ɾ��ʧ�ܡ�" << endl;
	}
}
template <class T>
int arrayStack<T>::getSize()		// getSize
{
	return m_nSize;
}
template <class T>
bool arrayStack<T>::isEmpty()	 //isEmpty
{
	return m_nSize == 0;
}
template<class T>
T arrayStack<T>::getTopElement()	//getTopElement
{
	if (m_nSize > 0)
	{
		return m_array[m_nSize - 1];
	}
	else
	{
		cout << "GetTopElement ʧ��" << endl;
		return T(NULL);
	}
}
template<class T>
void arrayStack<T>::show()		//show
{
	int nSize = getSize();
	for (int i = 0; i < nSize; i++)
	{
		cout << m_array[i] << "  ";
	}
}
int main()
{
	int capacity = 6;				// Ĭ������
	arrayStack<int> s1(6);
	arrayStack<int> s2(6);
	int temp;
	for (int i = 0; i < capacity; i++)
	{
		cin >> temp;
		s1.push(temp);
	}
	printf("*****************\n"); 
	for (int i = 0; i < capacity; i++)
	{
		temp=s1.getTopElement();
		s1.pop();
		s2.push(temp);
	}
	
	for (int i = 0; i < 6; i++)
	{
		cout<<"ջ������˵�Ƕ�ͷΪ��"<<s2.getTopElement()<<endl;
		s2.show();
		s2.pop();
	}
	return 0;
}
