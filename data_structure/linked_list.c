 #include<stdio.h>
#include<stdlib.h>

// Node structure

struct Node
{
	int data;
	struct Node * link;
};

// creating header 

struct Node * header=NULL;

// crearting a node using a function

struct Node * create_Node(int data)
{
	struct Node * newnode;
	newnode=malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->link=NULL;
	return(newnode);
}


// Insert at front

void insert_at_front(int data)
{
	struct Node * newnode;
	newnode=create_Node(data);
	
	// Checking if this node is first one else inserting
	
	if(header==NULL)
	{
		header=newnode;
	}
	else
	{
		newnode->link=header;
		header=newnode;
	}

}

// Insert at end
void insert_at_end(int data)
{
    struct Node * newnode;
    newnode = create_Node(data);
    if (header == NULL)
    {
        header = newnode;
    }
    else
    {
        struct Node * temp = header;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode; 
    }
}

void traversal()
{
	struct Node * ptr;
	ptr=header;
	while(ptr !=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
}

int main()
{	
	insert_at_front(10);
	insert_at_front(20);
	insert_at_front(3000);
	printf("\n");
	insert_at_end(100);
	insert_at_end(200);
	insert_at_end(5000);
	traversal();
	return(0);
}
