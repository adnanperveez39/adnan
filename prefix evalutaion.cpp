#include<stdio.h>//standard input output
#include<stdlib.h>//standard library
#include<math.h>//math function 
#include<string.h>
#define MAX 20
int stack[MAX],a1,a2,top=-1; //declaring operands , stack and top
void push(int x)//function that performs push operation
		{   
			top++;
			stack[top]=x;
		}
int pop()//function that performs pop operation
		{   
	   	 char k;
	   	 k=stack[top];
	 	 top=top-1;
	   	 printf("%c",k);
		}
int evaluation()
{ 
 		   	int len;
			char prefix[20];
			int res,i;
			gets(prefix);
			len=strlen(prefix);
			for(i=len-1;prefix[i]>=0;i--)
		{
			if(isdigit(prefix[i]))// checks if the symbol is operand 
			{
	 push(prefix[i]-48);//ascii conversion 
	}
	else
	{
	a1=pop();//first operand
	a2=pop();//second operand 
	switch(prefix[i])
		{
			case '+':
push(a1+a2);//addition
			 break;
			case '-':
push(a1-a2);//subtraction 
			  break;
		    	case '*':
push(a1*a2);//multiplication 
			  break;
			case '/':
push(a1/a2);//division 
			   break;
			case '^':res=pow(a1,a2);//math function
			        	 push(res);
			         break;
		}
		
	   }
   }   
	printf("result is %d",pop());
}
int main()
{   
    char prefix[20];
	printf("enter string");
	scanf("%s",prefix);a
	prefixeval(prefix);
	return 0;
} 

