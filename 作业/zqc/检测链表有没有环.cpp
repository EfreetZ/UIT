#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct node {
	int data;
	struct node* next;
}node, * list;
bool isLoop(list head)
{
	list fast = head;
	list slow = head;
	if (fast == NULL)
	{
		return false;
	}
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return true;
		}
	}
	return !(fast == NULL || fast->next == NULL);
}

int main()
{
	int i = 6, k = 3, j = 2;
	node* yesloop6;		//不首尾相接的 6 环   \ 
			//首尾相接的 0 环 	  >	长度都为 6 
	node* noloop;		//不成环的 链表 	  /
	yesloop6 = (node*)malloc(sizeof(node));
	yesloop6->next = NULL;
	node* yesloop0;
	yesloop0 = (node*)malloc(sizeof(node));
	yesloop0->next = NULL;
	noloop = (node*)malloc(sizeof(node));
	noloop->next = NULL;
	node* r;
	r = (node*)malloc(sizeof(node));
	r = noloop;
	while (i--)			//i=6     noloop
	{
		node* p;
		p = (node*)malloc(sizeof(node));
		r->next = p;
		r = p;
	}
	r->next = NULL;
	node* n4;    //第四个节点为环的头 
	r = yesloop6;			//yesloop6 
	while (k--)		//k=3
	{
		node* p;
		p = (node*)malloc(sizeof(node));
		r->next = p;
		r = p;
	}
	n4 = r;
	while (j--)		//j=2
	{
		node* p;
		p = (node*)malloc(sizeof(node));
		r->next = p;
		r = p;
	}
	r->next = n4;

	r = yesloop0;
	i = 6;
	while (i--)			//i=6     yesloop0
	{
		node* p;
		p = (node*)malloc(sizeof(node));
		r->next = p;
		r = p;
	}
	r->next = yesloop0;
	if (isLoop(yesloop6))
		printf("yesloop6有环。\n");
	else
		printf("yesloop6无环。\n");

	if (isLoop(yesloop0))
		printf("yesloop0有环。\n");
	else
		printf("yesloop0无环。\n");

	if (isLoop(noloop))
		printf("noloop有环。\n");
	else
		printf("noloop无环。\n");

	return 0;
}

