#include<stdio.h>
#define max 5

int stack[max];
int top=-1;


void push()
{
	int item;
	if(top==max-1)
	{
		printf("Stack is full\n");
	}
	else
	{
		printf("enter item to be pushed: ");
		scanf("%d", &item);
		top=top+1;
		stack[top]=item;
		printf("pushed item : %d\n", item);	
	}
}

void pop()
{
	if(top<0)
	{
		printf("Stack is Empty, No item to pop\n");
	}
	else
	{
		int poppeditem=stack[top];
		printf("Popped item :%d \n",poppeditem);
		top--;
	}
}

void traversal()
{
	if(top<0)
	{
		printf("Stack is Empty, No item to show\n");			
	}
	else
	{
		printf("Stack items are : ");
		for(int i =top; i>=0; i--)
		{
			printf("%d\t\n",stack[i]);  
		}
	}
}

int main()
{
	int choice;
	
	
	do
	{
		
		printf("1 : Push\n");
		printf("2 : Pop\n");
		printf("3 : traversal\n");
		printf("4 : exit\n");
		printf("Enter choices from 1 to 4 : ");

		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				push();
				break;

			case 2:
				pop();
				break;
			
			case 3:
				traversal();
				break;
		
			case 4:
				break;
	
			default:
				printf("wrong choice entered");
		}
	
	}while(choice !=4);
	return(0);	
}
