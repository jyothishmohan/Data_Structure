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
    newnode->rlink = NULL;
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
    struct node *ptr = header;

    if (header == NULL)
    {
        header = newnode;
        return;
    }

    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
    }

    ptr->rlink = newnode;
    newnode->llink = ptr;
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
    if (header == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = header;
    header = ptr->rlink;
    if (header != NULL)
    {
        header->llink = NULL;
    }
    free(ptr);
}

void delete_at_end()
{
    struct node *ptr;
    if (header == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = header;
    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
    }
    if (ptr->llink != NULL)
    {
        ptr->llink->rlink = NULL;
    }
    else
    {
        header = NULL;
    }
    free(ptr);
}

void delete_at_any(int position)
{
    struct node *ptr = header;

    if (header == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position == 1)
    {
        delete_at_front();
        return;
    }

    for (int i = 1; i < position && ptr != NULL; i++)
    {
        ptr = ptr->rlink;
    }

    if (ptr == NULL)
    {
        printf("Position out of bounds\n");
    }
    else
    {
        if (ptr->rlink != NULL)
        {
            ptr->rlink->llink = ptr->llink;
        }
        if (ptr->llink != NULL)
        {
            ptr->llink->rlink = ptr->rlink;
        }
        free(ptr);
    }
}

int search(int value)
{
    struct node *ptr = header;
    int position = 1;
    int found = 0;

    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            printf("Element %d found at position %d\n", value, position);
            found = 1;
        }
        ptr = ptr->rlink;
        position++;
    }

    if (!found)
    {
        printf("Element %d not found in the list.\n", value);
    }

    return found;
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
    insert_at_any(333, 4);
    insert_at_end(100);
    delete_at_front();
    delete_at_end();
    traversal();
    search(22);
    search(44);
    delete_at_any(2);
    traversal();
    return 0;
}
