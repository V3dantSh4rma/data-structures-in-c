// Dynamic Queue implementation in C
/**
 * Methods:
 * - getLast()
 * - peek()
 * - display()
 * - enqueue()
 * - dequeue()
 * - isEmpty()
 * - create_queue()
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

Queue *create_queue(){
    Queue *queue = malloc(sizeof(Queue));
    if(queue == NULL)
    {
        puts("Unable to allocate the memory for queue.");
        exit(EXIT_FAILURE);
    }
    
    queue->front = NULL;
    queue->rear = NULL;
    puts("Empty Queue Initiated");
    return queue;
}

bool isEmpty(Queue *q){
    if(q->front == NULL) return true;
    return false;
}

int peek(Queue *q){
    if(q->front == NULL)
    {
        puts("The Queue is empty.");
        exit(EXIT_FAILURE);
    }

    return q->front->data;
}

int getLast(Queue *q){
    if(q->rear == NULL){
        puts("The QUEUE is empty.");
        exit(EXIT_FAILURE);
    }

    return q->rear->data;
}

void display(Queue *q){
    Node *current = q->front;
    puts("///// Queue /////");
    while(current != NULL){
        printf("- %d\n", current->data);
        current = current->next;
    }
}

void enqueue(Queue **q, int data){
    Node *n = malloc(sizeof(Node));
    if(n == NULL){
        puts("Failed to allocate memory for the NODE.");
        exit(EXIT_FAILURE);
    }
    
    n->data = data;
    n->next = NULL;

    if(isEmpty((*q))){
        (*q)->front = n;
        (*q)->rear = n;
    } else {
        (*q)->rear->next = n;
        (*q)->rear = n;
    }
}

void dequeue(Queue **q)
{
    if(isEmpty(*q)){
        puts("The Queue is empty.");
        exit(EXIT_FAILURE);
    }

    int data = (*q)->front->data;
    Node *temp = (*q)->front;
    
    if((*q)->front == (*q)->rear){
        (*q)->front = NULL;
        (*q)->rear = NULL;
    }

    (*q)->front = temp->next;
    free(temp);
}

void free_queue(Queue **q){
    while(!isEmpty(*q)) dequeue(q);
    free(q);
}

int main()
{
    Queue *q = create_queue();
    // Use methods here...
    return 0;
}