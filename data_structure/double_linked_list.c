#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
};
struct node *header=NULL;

struct node *create_node(int data)
{
	struct node *newnode;
	newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->llink = NULL;
	newnode->llink = NULL;
	return newnode;
}
void insert_at_front(int data)
{
	struct node *newnode;
	newnode = create_node(data);

	if (header==NULL)
	{
		header=newnode;
	}
	else
	{
		newnode->rlink=header;
		header->llink=newnode;
		header=newnode;
	}
}
void insert_at_end(int data)
{
	struct node *newnode;
	newnode = create_node(data);

	struct node *ptr=header;
	while (ptr !=NULL)
	{
		ptr->rlink=newnode;
		newnode->llink=ptr;
	}
	
}

void traversal()
{
	struct node *ptr = header;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->rlink;
	}
	printf("\n");
}

int main()
{
	insert_at_front(22);
	insert_at_front(33);
	insert_at_front(44);
	insert_at_end(100);
	traversal();
	return 0; 
}

