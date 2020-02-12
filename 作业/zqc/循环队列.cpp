#include<iostream> 
#include<stdio.h>
#include<algorithm>
typedef struct queue{
    int count;    
    int front;    
    int rear;     
    int data[5];  
}Queue;
void Init(Queue* ptr) //������� 
{ 
    ptr->count = 0;
    ptr->front = 0;
    ptr->rear = -1;
}
int queueFull(Queue* ptr) 
{   //�ж϶����Ƿ��� 
    return ptr->count >= 5;
}
int queueEmpty(Queue* ptr) 
{   //�ж϶����Ƿ�Ϊ��
    return ptr->count <= 0;
}
void push (Queue* ptr, int temp) 
{    //������� 
    if (queueFull(ptr)) 
	{
	    std::cout << "��������!" << std::endl; 
	    return;    
	}
	else
	{    
	    ptr->count ++;    
		ptr->rear = (ptr->rear + 1) % 5;    
		ptr->data[ptr->rear] = temp;
	}
}
void pop(Queue* ptr) 
{  //����  
	if (queueEmpty(ptr)) 
	{    
	    std::cout << "����Ϊ��!" << std::endl;    
	    return;   
	}
	else 
	{        
		ptr->count --;        
		ptr->front = (ptr->front + 1) % 5;    
	}
}
int queueSize (Queue* ptr) 
{    //���ض��г���
    return ptr->count;
}
void show(Queue* ptr) 
{ //��������    
	if(queueEmpty(ptr)) 
	{     
	   	std::cout << "����Ϊ��!" << std::endl;        
	   	return;    
	}
	else 
	{     
	   std::cout << "���б���: ";        
	   int i = ptr->front;        
	   while (i != ptr->rear) 
	   {      
	        std::cout << ptr->data[i] << " ";            
			i++;            
			i = i % 5;        
		}    
		std::cout << ptr->data[ptr->rear] << " "; 
	}  
	std::cout << std::endl;
}
int main() 
{
    Queue* a = (Queue *)malloc(sizeof(Queue)); 
    Init(a);
    push(a,10);
    push(a,18);
    push(a,15);
    show(a);
    std::cout<<queueSize(a)<<std::endl; 
    push(a,19);
    push(a,12);
    show(a);
    if(queueFull(a))
    {
    	std::cout<<"����������"<<std::endl; 
	}
    pop(a);
    show(a);
    push(a,58);
    show(a);
    push(a,59);
    show(a);
    std::cout << "\n��ʼ����!" << std::endl; 
    for(int i=0;i<5;i++)
    {
    	std::cout<<"���г���Ϊ��"<<queueSize(a)<<std::endl; 
    	show(a);
    	pop(a);
	}
	show(a); 
	return 0;
}
