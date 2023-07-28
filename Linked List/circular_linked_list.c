// BUGGY CODE. DO NOT RUN.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *next;
    struct Node *previous;
} Node;

int get_pos(Node **head, int key){
    Node *temp = *head;
    int pos = 0;
    while(temp != *head)
    {
        if(temp->key == key) return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

Node *create_node(int key)
{
    Node *new = malloc(sizeof(Node));
    new->key = key;
    new->next = NULL;
    new->previous = NULL;
    return new;
}

void insertAtLast(Node **head, int key){
    Node *newNode = create_node(key);
    
    if((*head) == NULL){
        (*head) = newNode;
        (*head)->next = (*head);
        (*head)->previous = (*head);
    }

    Node *last = (*head)->previous;
    (*head)->previous = newNode;
    last->next = newNode;
    newNode->previous = last;
    newNode->next = (*head);
}

void insertAtStarting(Node **head, int key){
    Node *newNode = create_node(key);
    Node *tail = (*head)->previous;
    newNode->next = (*head);
    (*head) = newNode;
    tail->next = *head;
    (*head)->previous = tail;
}

void insertAfter(Node **head, int node, int key){

    Node *newN = create_node(key);
    Node *temp = *head;
    Node *tail = (*head)->previous;

    while(temp != tail && temp->key != key)
    {
        temp = temp->next;
    }
}

void traverse(Node **head){
    Node *temp = *head;
    puts("///// Traversal /////");

    do {
        printf("- %d\n", temp->key);
        temp = temp->next;
    } while(temp != *head);
}

void removeFromHead(Node **head){
    (*head)->next->previous = (*head)->previous;
    (*head)->previous->next = (*head)->next;
    (*head) = (*head)->next;
}

void removeFromTail(Node **head){
    Node *tail = (*head)->previous;
    tail->previous->next = (*head);
    (*head)->previous = tail->previous; 
}

void removeNode(Node **head, int key){
	Node *temp = *head;
	while(temp->next != *head && temp->key != key){
		temp = temp->next;
	}

    if(temp == *head){
        return NULL;
    }
}

void print_stats(Node **head)
{
    printf("Head: %d, Tail: %d\n", (*head)->key, (*head)->previous->key);
}

int main(){
    int keys;
    int nodes;
    Node *head = NULL;

    printf("Enter the total nodes of a Circular Linked List: ");
    scanf("%d", &nodes);

    for(int i = 1; i <= nodes; i++){
        printf("Enter the value of Node %d: ", i);
        scanf("%d", &keys);
        insertAtLast(&head, keys);
    }    

    traverse(&head);
    removeFromHead(&head);
    removeFromTail(&head);
    insertAtStarting(&head, 69);
    traverse(&head);
    printf("%d\n", get_pos(&head, 4));   
    return 0;
}