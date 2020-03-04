#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;
char a[100] ;
char symbol[100] ; // ·ûºÅ
int num[100] ; // Êı×Ö 
int symbolhead = 0 ; // ·ûºÅÖ¸Õë 
int numhead = 0 ; // Êı×ÖÖ¸Õë 

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
            while(a[i] >= '0' && a[i] <= '9')
            {
               	num[numhead] = num[numhead] *10 + a[i] - '0' ;
				i++;
			}
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
