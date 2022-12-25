#include<stdio.h>//standard Input Output header file
#include<stdlib.h>//standard library header file
#include<ctype.h>
#include<string.h>
#define max 100//declaring the size to 5
int top=-1, stack[max];
void push(char x)//push function
   {
       stack[++top]=x;
   }
char pop()//pop function
  	 {
  	 if(top==-1)//checks if stack is empty
   		return -1;//indicates that the stack is empty
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
void strrev(char *exp)
 	  {
  		 char temp[50];
   		int size=strlen(exp);
  		 temp[size--]='\0';
   		int i=0;
   		while(exp[i]!='\0')
    	   {
      			 temp[size]=exp[i];
     			  i++;
     			  size--;
   	    }
  		 strcpy(exp,temp);
   }
void infixtoprefix(char infix[max],char prefix[max]) //funciton that converts infix to prefix
   {
  		     char temp,e;  //declaring temporary variable
 		      int i=0,j=0;
  		     strrev(infix);
       		while(infix[i]!='\0')//checks for the end of string
     	  {
         		  temp=infix[i];
         		 if(isalnum(temp))//checks if the symbol is operand
        		   {
           		    prefix[j++]=temp;
         		  }
       	    else if(temp==')')//pushes the contents of stack if closing parenthesis is encountered 
         		   push(temp);
          		 else if(temp=='(')
            	   {
        			    while((e=pop())!=')') //pops the contents of stack if opening parenthesis is encountered 
          		  {
        			     prefix[j++]=e;
          		  }
         		    }
        			   else
         		  {
while(priority(stack[top])>=priority(temp)) //checks the precedence of top of stack
               {
prefix[j++]=pop();}
              		     push(temp);
        	   }
       			    i++;
      		 }
     			  while(top!= -1)//checks for underflow 
     			  prefix[j++]=pop();
   			    prefix[j]='\0';
  			     strrev(prefix);
   }
int main()//main fuction
{
   char infix[max],prefix[max];
   printf("Enter the infix expression\n");
   scanf("%s",infix);
   printf("The infix expression is %s\n",infix);//output
 		  infixtoprefix(infix, prefix);
   printf("The prefix expression is %s\n",prefix); //output
   return 0;
}
