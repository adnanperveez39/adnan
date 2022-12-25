//conversion of infix to postfix
#include<stdio.h> // standard input output 
#include<ctype.h>
char stack[20]; // stack size declaration 
int top=-1; //assuming top of the sack to be -1
void push(char x) //push function
{
       stack[++top]=x;//assigning the value of x to top of stack
}
char pop() // pop function
{
 if(top==-1)//checks if stack is empty
 return -1;
 else
 return stack[top--];
}
int priority(char symbol) //function to check the priority of operators.
{

     switch(symbol)
{
	case'+':
	case'=':
		return 2;// if the encountered operator is + or - then return 2
		break; 
	case'*':
	case'/':
		return 3;// if the encountered operater is * or / then return 3	
		break;
	case'^':
		return 4;// if the encountered operater is ^ then return 4	
		break;
	case'(':
	case')':
	case'#':
		return 1;// if the encountered symbol is ( , ) or # then return 1	
		break;
}
	
}
int main() // main function
{
       char *a,symbol; //declaring pointer a and the variable symbol 
       char exp[20];
       printf("enter the expression\n"); //displaying the expression
       scanf("%s",exp);
       a=exp; //appending the value of  expression to a
 
       while(*a!='\0') //checks for end of string
       {
               if(isalnum(*a))//checks if incoming character is operand
               printf("%c",*a);
               else if(*a=='(')
               push(*a); //checks the condition of else if and pushes the element
               else if(*a==')')
               {
                       while((symbol=pop())!='(')
                       printf("%c",symbol);
               }
               else
               {
               while(priority(stack[top])>=priority(*a)) //checks the priority of symbol to which top is pointing 
               printf("%c",pop());
               push(*a);
               }
       a++; //incrementation of a by 1
       }
       while(top!=-1) //checks if stack is empty
               {
               printf("%c",pop());
               }
printf("\n");                
return 0; //terminates the program
}

