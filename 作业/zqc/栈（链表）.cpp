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
	//内存不足的异常类    
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
//堆栈的析构方法
template<class T>LinkedStack<T>::~LinkedStack()
{
	Node<T>*next;
	while(top){
		next=top->link;
		delete top;
		top=next;	
	}
}
//判断当前的堆栈有木有满载
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
//返回当前堆栈的头元素数据
template<class T>
T LinkedStack<T>::Top()
{
	if( IsEmpty() )
		throw OutOfBounds();
	return top->data;
} 
//将数据压进堆栈
template<class T>
LinkedStack<T>& LinkedStack<T>::PushStack( T&x)
{
	Node<T>*p = new Node<T>;
	p->data = x;
	p->link = top;
	top = p;
	return *this;
} 
//删除栈顶元素并将其送入x
template<class T>
LinkedStack<T>&LinkedStack<T>::PopStack(T&x) //取出一个
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
		S.PushStack(temp);		//输入
	}
	int popNode;
	S.PopStack(popNode);		//取出一个
	cout<<"从栈中取出一个 : "<<popNode<<endl;
	printf("\n");
	S.Show();	//取出整个栈
	return 0;
}
