#include<iostream>
using namespace std;

 template<class T>
	 class Node{
			public:
				T data;
				Node<T> *link;
	 };
 template<class T>
	class LinkedStack
	{
		public:
			LinkedStack()	
			{
				top=0;
			}
			~LinkedStack();		
			bool IsEmpty()
			{
				return top==0;
			}		
			bool IsFull();		
			T Top();		
			LinkedStack<T>& PushStack( T&x);		
			LinkedStack<T>& PopStack(T&x);		
			Node<T> *top;		
			void Show();
	};
class OutOfBounds
{       
	public: 
		OutOfBounds()
		{
		cout<<"Out Of Bounds!"<<endl;
		}   
};
	//�ڴ治����쳣��    
class NoMem
{        
	public:           
		NoMem()
		{ 
			cout<<"No Memory!"<<endl;
		}   
};    
template<class T>
void LinkedStack<T>::Show()
{
	Node<T> *current = top;
	while(current) {
		cout<<current->data<<endl;
		current=current->link;
	} 
}    
//��ջ����������
template<class T>LinkedStack<T>::~LinkedStack()
{
	Node<T>*next;
	while(top){
		next=top->link;
		delete top;
		top=next;	
	}
}
//�жϵ�ǰ�Ķ�ջ��ľ������
template<class T>bool LinkedStack<T>::IsFull(){
	try
	{
		Node<T>*p = new Node<T>;
		delete p ;		
		return false;
	}
	catch(NoMem)
	{
		return true;
	}
}
//���ص�ǰ��ջ��ͷԪ������
template<class T>
T LinkedStack<T>::Top()
{
	if( IsEmpty() )
		throw OutOfBounds();
	return top->data;
} 
//������ѹ����ջ
template<class T>
LinkedStack<T>& LinkedStack<T>::PushStack( T&x)
{
	Node<T>*p = new Node<T>;
	p->data = x;
	p->link = top;
	top = p;
	return *this;
} 
//ɾ��ջ��Ԫ�ز���������x
template<class T>
LinkedStack<T>&LinkedStack<T>::PopStack(T&x) //ȡ��һ��
{
	if( IsEmpty() )		
		throw OutOfBounds();
	x=top->data;
	Node<T>*p = top;
	top = top->link;
	delete p;
	return *this;
}
int main()
{	
	LinkedStack<int> S;
	int temp;
	for (int i = 0; i < 7; i++)
	{
		cin >> temp;
		S.PushStack(temp);		//����
	}
	int popNode;
	S.PopStack(popNode);		//ȡ��һ��
	cout<<"��ջ��ȡ��һ�� : "<<popNode<<endl;
	printf("\n");
	S.Show();	//ȡ������ջ
	return 0;
}
