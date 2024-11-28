#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;

struct Node* create_Node(int data) {
    struct Node* newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

void push(int data) {
    struct Node* newnode = create_Node(data);

    if (top == NULL) {
        top = newnode;
    } else {
        newnode->link = top;
        top = newnode;
    }
    printf("Pushed item: %d\n", data);
}

void pop() {
    if (top == NULL) {
        printf("Stack is Empty, No item to pop\n");
    } else {
        struct Node* temp = top;
        top = top->link;
        printf("Popped item: %d\n", temp->data);
        free(temp);
    }
}

void traversal() {
    if (top == NULL) {
        printf("Stack is Empty, No item to show\n");
    } else {
        struct Node* temp = top;
        printf("Stack items are: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
    printf("\n\n");
}

int main() {
    int choice, data;

    do {
        printf("1: Push\n");
        printf("2: Pop\n");
        printf("3: Traversal\n");
        printf("4: Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to be pushed: ");
                scanf("%d", &data);
                push(data);
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
                printf("Wrong choice entered\n");
        }
    } while (choice != 4);

    return 0;
}
