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
	struct node *ptr;
	while (ptr->rlink !=NULL)
	{
		ptr=ptr->rlink;
	}
	if(newnode==NULL)
	{
		printf("Not enough memory");
	}
	else
	{
		ptr->rlink=newnode;
		newnode->llink=ptr;
	}
	
}
void insert_at_any(int data, int position)
    {
    	struct node *newnode, *ptr;
    	newnode = create_node(data);

    	if (position == 1)
    	{
        	insert_at_front(data);
        	return;
    	}	

    	ptr = header;
    	for (int i = 1; i < position - 1 && ptr != NULL; i++)
    	{
        	ptr = ptr->rlink;
    	}

    	if (ptr == NULL)
    	{
        	printf("Position out of bounds\n");
        	free(newnode);
    	} 
     	else
     	{
        	newnode->rlink = ptr->rlink;
        	newnode->llink = ptr;
        	if (ptr->rlink != NULL)
        	{
            		ptr->rlink->llink = newnode;
        	}
        	ptr->rlink = newnode;
    	}
}

void delete_at_front()
{
	struct node *ptr;
	ptr=header;
	header=ptr->rlink;
	free(ptr);
}
void delete_at_end()
{
     struct node *ptr ;
     struct node *ptr1;
     ptr=header;
     while (ptr->rlink != NULL) 
     
     {
     	ptr1 = ptr;
        ptr = ptr->rlink;
     }
     ptr1->rlink = NULL;
     free(ptr);
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
	insert_at_front(22);
	insert_at_front(33);
	insert_at_front(44);
	insert_at_any(333,4);
	insert_at_end(100);
	delete_at_front();
	delete_at_end();
	traversal();
	return 0; 
}
