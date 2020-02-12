#include<iostream> 
#include<stdio.h>
#include<algorithm>
typedef struct queue{
    int count;    
    int front;    
    int rear;     
    int data[5];  
}Queue;
void Init(Queue* ptr) //定义队列 
{ 
    ptr->count = 0;
    ptr->front = 0;
    ptr->rear = -1;
}
int queueFull(Queue* ptr) 
{   //判断队列是否满 
    return ptr->count >= 5;
}
int queueEmpty(Queue* ptr) 
{   //判断队列是否为空
    return ptr->count <= 0;
}
void push (Queue* ptr, int temp) 
{    //进入队列 
    if (queueFull(ptr)) 
	{
	    std::cout << "队列满了!" << std::endl; 
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
{  //出队  
	if (queueEmpty(ptr)) 
	{    
	    std::cout << "队列为空!" << std::endl;    
	    return;   
	}
	else 
	{        
		ptr->count --;        
		ptr->front = (ptr->front + 1) % 5;    
	}
}
int queueSize (Queue* ptr) 
{    //返回队列长度
    return ptr->count;
}
void show(Queue* ptr) 
{ //遍历队列    
	if(queueEmpty(ptr)) 
	{     
	   	std::cout << "队列为空!" << std::endl;        
	   	return;    
	}
	else 
	{     
	   std::cout << "队列遍历: ";        
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
    	std::cout<<"队列以满。"<<std::endl; 
	}
    pop(a);
    show(a);
    push(a,58);
    show(a);
    push(a,59);
    show(a);
    std::cout << "\n开始出队!" << std::endl; 
    for(int i=0;i<5;i++)
    {
    	std::cout<<"队列长度为："<<queueSize(a)<<std::endl; 
    	show(a);
    	pop(a);
	}
	show(a); 
	return 0;
}
