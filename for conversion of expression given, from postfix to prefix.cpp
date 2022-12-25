#include<stdio.h>//standard input output
#include<string.h>
#include<stdlib.h>//standard library
 
#define MAX 20
 
char str[MAX], stack[MAX];//declaration of string and stack 
int top = -1;//to check if the stack is empty
 
void push(char k)//function to perform push operation 
{
 stack[++top] = k;
}
 
char pop()//function to perform pop operation
{
 return stack[top--];
}
// A utility function to check if the given character is operand
int checkIfOperand(char ch)
{
 return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
 
//function to check if the symbol is an operator
int isOperator(char x)
{
 switch (x) {
 case '+':
 case '-':
 case '/':
 case '*':
   return 1;
 }
 return 0;
}
	 
void postfixToprfix()// function to convert the given postfix expression 
{
 int n, i, j = 0;//declaration of counter variables 
 char r[20];
 char a1, a2, op;
 
 printf("Enter the postfix expression\n");
 scanf("%s", str);
 
 n = strlen(str);//variable that keeps track of the string length 
 
 for (i = 0; i < MAX; i++)
 		  stack[i] = '\0';//checks for end of string 
 printf("Prefix expression is:\t");
 
 for (i = n - 1; i >= 0; i--)
 {
 				  if (isOperator(str[i]))//checks for operator
 			  {
  				   push(str[i]);
  				 } else
 			  {
     r[j++] = str[i];
 		    while ((top != -1) && (stack[top] == '#'))//makes sure the stack is not empty
     {
  			     a1 = pop();
      			    r[j++] = pop();
   		  }
  		   push('#');
   }
 }
 r[j] = '\0';
 
 i = 0;
 j = strlen(r) - 1;//as the indexing starts from 0
 char d[20];
 
 while (r[i] != '\0')
 {
  		 d[j--] = r[i++];
 }
 
 printf("%s\n", d);
 
}
int main()
{
 postfixToprfix();//function call
 
 return 0;
}
