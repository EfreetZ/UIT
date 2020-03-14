#include <stdio.h>                        
#include <stdlib.h>
                   
int insert_operand(double *operand , int * top_num ,double num)          
{
    (*top_num) ++;  
    operand[*top_num] = num;                  
    
    return 0;                            
}  
int insert_oper (char * oper , int *top_oper , char ch)               
{  
    (*top_oper)++;  
    oper[*top_oper] = ch;                 
    return 0;                           
}       
int compare(char *oper , int *top_oper , char ch)                     
{     
    if((oper[*top_oper] == '-' || oper[*top_oper] == '+')            
    && (ch == '*' || ch == '/'))
    {  
        return 0;                      
    }   
    else if(*top_oper == -1 || ch == '('|| (oper[*top_oper] == '(' && ch != ')'))  
    {  
		return 0;                      
    }  
    else if (oper[*top_oper] =='(' && ch == ')' )        
    {  
		(*top_oper)--; 
		return 1;                       
    }  
    else  
    {  
        return -1;                                          
    }  
}  
int deal_date(double *operand ,char *oper ,int *top_num, int *top_oper)  
{  
    double num_1 = operand[*top_num];            
    double num_2 = operand[*top_num - 1];  
    
    double value = 0;  
    
    if(oper[*top_oper] == '+')                  
    { 
		value = num_1 + num_2;  
    }  
    
    else if(oper[*top_oper] == '-')             
    { 
		value = num_2 - num_1;  
    }  
    
    else if(oper[*top_oper] == '*')             
    { 
        value = num_2 * num_1;  
    }  
    
    else if(oper[*top_oper] == '/')              
    { 
		value = num_2 / num_1;  
    }  
    
    (*top_num) --;                             
    operand[*top_num] = value;                    
    (*top_oper) --;   
	
	return 0;
}  
int main()  
{  
	char *str = (char *) malloc (sizeof(char) * 100);               
    
    double operand[10] = {0};               
    int  top_num = -1;  
    
    char oper[50] = {0};                 
    int top_oper = -1;  
    
    scanf("%s",str);  
    char *temp;  
    char dest[50]="";  
    
    double num = 0;  
    int i = 0;  
    
    while(*str != '\0')  
    { 
		temp = dest;
		while((*str >= '0' && *str <= '9')||*str=='.')             
        {    
			*temp = *str;  
			str ++;   
			temp ++;            
		}                              
       
        if(*str != '(' && *(temp - 1) != '\0')   
		{    
			*temp = '\0';   
			num = atof(dest);					
			insert_operand(operand, &top_num,num);     
			printf("%lf\n",operand[0]);
		}
		while(1)  
		{    
			i = compare(oper,&top_oper,*str);      
			if(i == 0)  
			{      
				insert_oper(oper,&top_oper,*str);   
				break;    
			}       
			else if(i == 1)                       
			{ 
				str++; 
			}       
			else if(i == -1)                       
			{
				deal_date(operand,oper,&top_num,&top_oper);  
			}  
		}  
        str ++;                  
    }  
         
    return 0;                      
} 
