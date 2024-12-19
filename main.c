#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int count=0;

struct node* creationandinsertion(struct node* head, int* count) {
    struct node *newnode, *temp = NULL;
    int choice = 1;

    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (!newnode) {
            printf("Memory allocation failed\n");
            return head;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        (*count)++;
        printf("Press 1 to continue and 0 to exit: ");
        scanf("%d", &choice);
    }
    return head;
}

void reverselinkedlist(struct node **head) {
    struct node *previous = NULL, *current = *head, *nextnode = NULL;

    while (current != NULL) {
        nextnode = current->next;
        current->next = previous;
        previous = current;
        current = nextnode;
    }
    *head = previous;
    printf("Linked list reversed successfully.\n");
}

void displaylinkedlist(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice = 1, option;

    while (choice) {
        printf("******* Select an operation ********\n");
        printf("1. Create a linked list\n");
        printf("2. Reverse the given linked list\n");
        printf("3. Display linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            head = creationandinsertion(head, &count);
            break;
        case 2:
            reverselinkedlist(&head);
            break;
        case 3:
            displaylinkedlist(head);
            break;
        case 4:
            printf("Program exited\n");
            exit(0);
        default:
            printf("Invalid choice, try again\n");
            break;
        }
    }
    return 0;
}
