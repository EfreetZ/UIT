#include<stdio.h>
struct Node {
	int p,l,r;
}; 
struct Node T[100];
void inParse (int u)
{
	if(u==-1)
		return;
	inParse(T[u].l);
	printf(" %d",u);
	inParse(T[u].r);	
}
int main()
{
	int n,i,v,l,r,root;
	scanf("%d",&n);     //�ڵ���� 
	for(i=0;i<n;i++)
	{
		T[i].p=-1;      //�����ڵ� 
	}
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&v,&l,&r);		//��ֵ 
		T[v].l=l;						//����ʾ����    9 							 ��Ϊ��	 		 0
		T[v].r=r;						//				0 1 4 									   /  \ 
		if(l!=-1)						//				1 2 3									1		4
			T[l].p=v;					/*				2 -1 -1								   / \      / \      */ 
		if(r!=-1)						//				3 -1 -1								  2   3    5   8  
			T[r].p=v;					/*				4 5 8										  / \        */ 
	}									//				5 6 7										 6  7
	for(i=0;i<n;i++)					//				6 -1 -1
		if(T[i].p==-1)					//				7 -1 -1
			root=i;						//				8 -1 -1
										//�����        2 1 3 0 6 5 7 4 8  
	inParse(root);
	printf("\n");
	return 0; 
}
