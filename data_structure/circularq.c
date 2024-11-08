#include<stdio.h>
#define max 10

int cqueue[max];
int front=-1;
int rear=-1;
int item;

void enqueue()
{
    if((rear+1)%max==front)
    {
        printf("Queue is full, insertion not possible\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear=(rear+1)%max;
        printf("Enter item : ");
        scanf("%d",&item);
        cqueue[rear]=item;
        printf("Inserted item : %d",cqueue[rear]);
    }
    printf("\n");
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty, no elements to dequeue\n");
    }
    else
    {
        if(front==rear)
        {
            printf("Deleted item : %d",cqueue[front]);
            front=rear=-1;
        }
        else
        {
            printf("Deleted item : %d",cqueue[front]);
            front=(front+1)%max;
        }
    }
    printf("\n");
}
void traversal()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty, no items to show\n");
    }
    else
    {
        int i=front;
        printf("Elements in queue: ");
        while(i!=rear)
        {
            printf("%d ",cqueue[i]);
            i=(i+1)%max;
        }
        printf("%d ", cqueue[rear]);
    }
    printf("\n");
}

int main()
{

    int choice;
    do
    {
        printf(" 1 for Enqueue \n 2 for Dequeue \n 3 for Trversal \n 4 for Exit \n");
        printf("Enter one of 4 choices : ");
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
            printf("You entered wrong choice \n");
        }
    }while(choice !=4);
return 0;
}


