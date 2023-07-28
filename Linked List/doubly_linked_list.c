/**
 * traverse();
 * Insertion Methods:
 * - insertAfter();
 * - insertAtLast();
 * - insertAtStarting();  
 * 
 * Deletion Methods:
 * - deleteFromStarting();
 * - deleteFromEnding();
 * - deleteFromSelection();   
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *previous;
} Node;

Node *createNodeInstance(int key){
    Node *newN = malloc(sizeof(Node));
    newN->data = key;
    newN->next = NULL;
    newN->previous = NULL;
    return newN;
}


// Deletion (Starting, Ending, Selection)
void deleteFromStarting(Node **head){
    (*head) = (*head)->next;
    free((*head)->previous);
}

void deleteFromEnding(Node **head){
    Node *temp = (*head);
    Node *temp2 = malloc(sizeof(Node));
    
    while(temp->next != NULL){
        temp = temp->next;
    };
    
    temp2 = temp->previous;
    temp2->next = NULL;
    free(temp);
}

void deleteFromSelection(Node **head, int key){
    int pos = get_pos(*head, key);
    Node *temp = (*head);   

    while(temp != NULL && temp->data != key){
        temp = temp->next;
    }
    
    if(temp->next != NULL){
        temp->next->previous = temp->previous;
    }
    
    if(temp->previous != NULL){
        temp->previous->next = temp->next;
    }

    if(temp == (*head)){
        *head = (*head)->next;
    }

    if(temp == NULL){
        return NULL;
    }
    free(temp);
}

// Insertion (LAST, STARTING, AFTER)
void insertAtLast(Node **head, int key){
    Node *newNode = createNodeInstance(key);
    
    if((*head) == NULL){
        (*head) = newNode;
    }

    Node *current = *head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
    newNode->previous = current;
    newNode->next = NULL;
}

void insertAtStarting(Node **head, int key){
    Node *newN = createNodeInstance(key);
    newN->next = (*head);
    newN->previous = NULL;
    
    if((*head) != NULL){
        (*head)->previous = newN;
    }
    (*head) = newN;
}

void insertAfter(Node **previous_node, int key){
    if(previous_node == NULL){
        puts("Previous Node cannot be NULL.");
        exit(-1);
    }

    Node *newN = createNodeInstance(key);
    newN->next = (*previous_node)->next;
    (*previous_node)->next = newN;
    
    if(newN->next != NULL){
        newN->next->previous=newN;
    }
}

// Traversal
void traverse(Node *head){
    Node *current = head;
    puts("//////TRAVERSAL//////");
    while(current != NULL){
        printf("- %d\n", current->data);
        current = current->next;
    }
    free(current);
    return;
}

int main(void){
    Node *head = NULL;
    int times;
    int key;

    printf("Enter the Total Nodes of a Doubly Linked List: ");
    scanf("%d", &times);

    for (int i = 1; i <= times; i++) {
        printf("Enter the value of %d Node: ", i);
        scanf("%d", &key);
        insertAtLast(&head, key);
    }
    traverse(head);    
    return 0;
}
