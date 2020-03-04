#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
char a[100] ;
char symbol[100] ; // 符号
double num[100] ; // 数字 
int symbolhead = 0 ; // 符号指针 
int numhead = 0 ; // 数字指针 
char temp[20];

void math(char f) 
{
    switch(f)
    {
        case '+' : num[-- numhead] += num[numhead + 1] ; break ;
        case '-' : num[-- numhead] -= num[numhead + 1] ; break ;
        case '*' : num[-- numhead] *= num[numhead + 1] ; break ;
        case '/' : num[-- numhead] /= num[numhead + 1] ; break ;
    }
    -- symbolhead ;  
    num[numhead + 1] = 0 ;
}

int main()
{
    gets(a);
    int len = strlen(a)-1;
    for(int i = 0 ; i <= len ; ++ i )
    {    
        if(a[i] == '(' ) 
		{ 
            symbol[++ symbolhead] = a[i] ;
            continue ;
        }
        if(a[i]==')') 
		{ 
            while(symbol[symbolhead] != '(')
            	math(symbol[symbolhead]) ;
            -- symbolhead ;
            continue ;
        }
        if(a[i] >= '0' && a[i] <= '9')
		{     
            ++ numhead ;
            for(int j=0;a[i] >= '0' && a[i] <= '9'||a[i]=='.';)
            {
            	temp[j]=a[i];
               	//num[numhead] = num[numhead] *10 + a[i] - '0' ;
				i++;
				j++;
			}
			num[numhead]=atof(temp);
			temp[0]=temp[1]=temp[2]=temp[3]=temp[4]=temp[5]=temp[6]=temp[7]=' '; //数组重定义，简单出爆 
            i--;
            continue;
        }
        else 
		{
            if(a[i] == '/' || a[i] == '*')
			{ 
                symbol[++symbolhead] = a[i];
                continue;
            }
            else 
                while(symbol[symbolhead] == '*' || symbol[symbolhead] == '/' || symbol[symbolhead] == a[i])
				{ 
                    math(symbol[symbolhead]);
                } 
            
            symbol[++ symbolhead] = a[i] ;
        }
    }
    while(symbolhead != 0) 
	{
        math(symbol[symbolhead]);
    } 
    cout << num[numhead] ; 
    return 0 ;
}
