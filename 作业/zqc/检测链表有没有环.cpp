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
	node* yesloop6;		//����β��ӵ� 6 ��   \ 
			//��β��ӵ� 0 �� 	  >	���ȶ�Ϊ 6 
	node* noloop;		//���ɻ��� ���� 	  /
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
	node* n4;    //���ĸ��ڵ�Ϊ����ͷ 
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
		printf("yesloop6�л���\n");
	else
		printf("yesloop6�޻���\n");

	if (isLoop(yesloop0))
		printf("yesloop0�л���\n");
	else
		printf("yesloop0�޻���\n");

	if (isLoop(noloop))
		printf("noloop�л���\n");
	else
		printf("noloop�޻���\n");

	return 0;
}

