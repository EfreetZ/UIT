#include <stdio.h>
#include <string.h>
#include <algorithm>
/* 输入样例
	输入 insert 数   | 代表将  数  输进队列 
	输入 max           代表 优先级最高的数 
	输入 deletemax     代表 删除优先级最高的数 
	输入 size          代表 队列的长度 
	（只能这么输入） 
*/
using namespace std;

int h,a[2000];

void maxHeapify(int i)
{
	int l,r,largest;
	l=2*i;
	r=2*i+1;
	if(l<=h&&a[l]>a[i])
		largest=l;
	else
		largest=i;
	if(r<=h&&a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		maxHeapify(largest);
	}
}
int deleteMax()
{
	int max;
	if(h<1)
		return -999999;  //error！ 堆向下溢出 
	max=a[1];
	a[1]=a[h];			//将末尾的数移动到根 
	h--; 				//堆长度减一 
	maxHeapify(1);		//重新排列 
	return max;			//返回最大值 
}
void increaseKey(int i,int key)
{
	if(key<a[i])     //报错，新元素小于当前元素，因为要保证新元素要大于当前元素时才变更堆，
		return;		 //换句话说，如果当前元素比上一节点小，就不需要调换 
	a[i]=key;
	while (i>1&&a[i/2]<a[i])
	{
		swap(a[i],a[i/2]);
		i=i/2;
	}
}
void _insert(int key)
{
	h++;
	increaseKey(h,key);
}
int main()
{
	int key;
	char str[10];
	while(1)
	{
		scanf("%s",str);
		if(!strcmp(str,"end"))
			break;
		if(!strcmp(str,"insert"))
		{
			scanf("%d",&key);
			_insert(key);
		}
		else if(!strcmp(str,"max"))
			printf("%d\n",a[1]);
		else if(!strcmp(str,"deletemax"))
			printf("%d\n",deleteMax() );
		else if(!strcmp(str,"size"))
			printf("%d\n",h);
		else
			printf("error!\n");
	}
	return 0;
}
