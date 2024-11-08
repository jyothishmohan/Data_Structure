#include<stdio.h>
#define max 5
int queue[max];
int rear=-1;
int front=-1;
int item;

void enqueue()
{
	if(rear==max-1)
	{
		printf("Queue is full");	
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		printf("insert element : ");
		scanf("%d",&item);
		rear=rear+1;
		queue[rear]=item;
		printf(" %d Enqueued to queue\n",item);
		
	}
	
}
void dequeue()
{
	if(front==-1 || front>rear)
	{
		printf("Queue is empty");
		return;
	}
	else
	{

		printf("%d dequeued from the queue. \n",queue[front]);
		front=front+1;
	}
	
	
}
void traversal()
{
	if(front==-1 || front>rear)
	{
		printf("Queue is empty\n");
		
		
	}
	else
	{
		printf("elements in the queue : ");
		for(int i=front; i<=rear; i++)
		{
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
}

int main()
{
	int choice;
	
	do
	{
		
		printf("1 : enqueue\n");
		printf("2 : dequeue\n");
		printf("3 : traversal\n");
		printf("4 : exit\n");
		printf("Enter choices from 1 to 4 : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				traversal();

				break;
			case 4:
				break;
			default:
				printf("Wrong choice entered");				
		}
	}while(choice != 4);
return(0);
}
