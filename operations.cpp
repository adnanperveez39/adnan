#include<stdio.h>//standard input output
#include<stdlib.h>	//standard library
#define size 4//declaring the size to 4
int top=-1,array[size],i;// declaring the top 
void push();//push function 
void pop();// pop function
void display();//display function
int main()//main fuction
    {
        int choice;// declaration of choice variable
        while(1)//checks the condition and enters the while loop
            {
              	  printf("Operation performed by stack\n");//printing statement
              	  printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");//printing statement
               	 printf("Enter the choice\n");//printing statement
              	  scanf("%d",&choice);//stors the value of variable
                switch(choice)//chooses what operation to perform 
                    {
                        case 1:push();//to push the elements 
                      	  break;
                        case 2:pop();//to pop the elements
                    		    break;
                        case 3:display();//to display the elements
                     	   break;
                        case 4:exit(0);//if option is 4 exit the loop
                     	   default:printf("Invalid choice\n");
                    }
            }
    }
void push()//function to perform push operation.
{
        int k;
        if(top==size-1)//checks if stack is full 
         		   printf("Overflow\n");
      		  else
          		  {
               			 printf("Enter the element to be inserted:\n");
                			scanf("%d",&k);//takes the character that is to be pushed to the stack
              	  top=top+1;//incrementation of top

               		 array[top]=k;//assigning the value of k to top position of the array
        		    }
    }
void pop()  //function to perform pop operation 
    {
      	  if(top==-1)//checks if stack is empty 
         		   printf("Underflow\n");
       	 else
          		  {
               	 printf("Popped the element %d\n",array[top]);
               		 top=top-1;//decrement of top
       		     }
    }
void display()//function to display htr 
    {
        if(top>=0)//condition check
            {
           	 printf("Elements in the stack:\n");
          			  for(i=top;i>=0;i--)// loop for printing the elements in stack
               	 {
                 		   printf("%d\n",array[i]);// I value decides the place of top
              	  }
            }
        else
            		printf("Stack is empty\n");//empty stack, no elements present
    }
