#include <stdio.h>
#include <string.h>
#include <algorithm>
/* ��������
	���� insert ��   | ����  ��  ������� 
	���� max           ���� ���ȼ���ߵ��� 
	���� deletemax     ���� ɾ�����ȼ���ߵ��� 
	���� size          ���� ���еĳ��� 
	��ֻ����ô���룩 
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
		return -999999;  //error�� ��������� 
	max=a[1];
	a[1]=a[h];			//��ĩβ�����ƶ����� 
	h--; 				//�ѳ��ȼ�һ 
	maxHeapify(1);		//�������� 
	return max;			//�������ֵ 
}
void increaseKey(int i,int key)
{
	if(key<a[i])     //������Ԫ��С�ڵ�ǰԪ�أ���ΪҪ��֤��Ԫ��Ҫ���ڵ�ǰԪ��ʱ�ű���ѣ�
		return;		 //���仰˵�������ǰԪ�ر���һ�ڵ�С���Ͳ���Ҫ���� 
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
