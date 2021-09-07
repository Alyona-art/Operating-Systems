#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
    int value;
    struct node *next;
};

// a function print_list() prints out the value of each element

void print_list(struct node *head, int size) {
    if(size == 0)
        printf("Linked List is empty.\n");
    else {
        struct node tmp = *(head);
        printf("Current Linked List:\n");
        printf("%d ", tmp.value);
        if (size > 1)
            for (int i = 0; i < size-1; i++) {
                tmp = *tmp.next;
                printf("%d ", tmp.value);
            }
        printf("\n");
    }
}

// a function insert_node() inserts a new element after some existing element
// or at the beginning of the list if the element is denoted as "0"

void insert_node( struct node **head, int current, int new, int *size) {
    struct node *tmp = *head;
    if(current == 0) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->value = new;
        newNode->next = *head;
        *head = newNode;
        *size = *size + 1;
        printf("Node \"%d\" was inserted at the beginning of the Linked List\n", new);
        return;
    }
    while (tmp->value != current && tmp->next != NULL) {
        tmp = tmp->next;
    }
    if (tmp->next == NULL && tmp->value != current)
        printf("There is no element \"%d\" in the Linked List to insert after\n", current);

    else {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->value = new;
        newNode->next = tmp->next;
        tmp->next = newNode;
        *size = *size + 1;
        printf("Node \"%d\" was inserted after node \"%d\"\n", new, current);
    }
}

// a function delete_node() deletes a certain element

void delete_node(struct node **head, int toDelete, int *size) {
    struct node *tmp = *head;
    struct node *nextTmp = (*head)->next;
    if (tmp->value == toDelete) {
        free(*head);
        *head = nextTmp;
        printf("Node \"%d\" was deleted\n", toDelete);
        *size = *size - 1;
        return;
    }
    while (tmp->next != NULL && tmp->next->value != toDelete) {
        tmp = tmp->next;
    }
    if (tmp->next == NULL && tmp->value != toDelete)
        printf("There is no element \"%d\" in the Linked List to delete\n", toDelete);
    else {
        struct node *afterNext = tmp->next->next;
        free(tmp->next);
        tmp->next = afterNext;
        *size = *size - 1;
        printf("Node \"%d\" was deleted\n", toDelete);

    }
}

int main() {
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    int size = 0;
    int current, new;
    char str[1000];

    while(strcmp(str, "exit")) {
        printf("\n\"insert\" - to insert a new element\n"
               "\"delete\" - to delete element from the Linked List\n"
               "\"print\" - to print current Linked List\n"
               "\"exit\" - to finish work with the List:\n");
        scanf("%s", str);

        if(strcmp(str, "insert") == 0) {
            print_list(head, size);
            printf("Enter an element after which a new one will be inserted\n"
                   "or enter \"0\" to insert at the beginning of the list:\n");
            scanf("%d", &current);
            printf("Enter a new element:\n");
            scanf("%d", &new);

            insert_node(&head, current, new, &size);
        }
        else if(strcmp(str, "delete") == 0) {
            print_list(head, size);
            printf("Enter an element to delete from the list:\n");
            scanf("%d", &current);

            delete_node(&head, current, &size);
        }
        else if(strcmp(str, "print") == 0) {
            print_list(head, size);
        }
        else if(!strcmp(str, "exit") == 0) {
            printf("Wrong command. Try again:\n");
        }
    }
    return 0;
}
