// Circular Queue implementation in C
/**
 * Methods:
 * - create_queue()
 * - peek()
 * - display()
 * - enqueue()
 * - dequeue()
 * - getLast()
 * - isEmpty()
 * - clearQueue()
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
    Queue *q = malloc(sizeof(Queue));
    if(q == NULL){
        puts("Failed to Allocate the memory.");
        exit(EXIT_FAILURE);
    }
    q->front = NULL;
    q->rear = NULL;
    puts("Empty Queue initialized.");
    return q;
}

bool isEmpty(Queue *q){
    if(q->front == NULL) return true;
    return false;
}

void enqueue(Queue **q, int data){
    Node *n = malloc(sizeof(Node));

    if(n){
        n->data = data;
        if(isEmpty(*q)){
            (*q)->front = n;
            (*q)->rear = n;
        } else {
            (*q)->rear->next = n;
            (*q)->rear = n;
        }

        (*q)->rear->next=(*q)->front;
    } else {
        puts("Unable to allocate memory.");
        exit(EXIT_FAILURE);
    }
}

void display(Queue *q){
    Node *temp = q->front;
    puts("///// CIRCULAR QUEUE /////");
    
    do {
        printf("- %d\n", temp->data);
        temp = temp->next;
    } while(temp != q->front);
    free(temp);
}

int peek(Queue *q)
{
    if(isEmpty(q)){
        puts("The queue is empty.");
        exit(EXIT_FAILURE);
    }
    return q->front->data;
}

int getLast(Queue *q)
{
    if(isEmpty(q))
    {
        puts("The queue is empty.");
        exit(EXIT_FAILURE);
    }

    return q->rear->data;
}

void dequeue(Queue **q)
{
    if (isEmpty(*q)) {
        puts("The queue is empty.");
        return;
    }

    Node *front = (*q)->rear->next;
    (*q)->front = front->next;

    if (front == (*q)->rear) {
        (*q)->front = NULL;
        (*q)->rear = NULL;
    } else {
        (*q)->rear->next = (*q)->front;
    }
}

void clearQueue(Queue *q){
    if(isEmpty(q)){
        puts("The Queue is empty.");
        exit(EXIT_FAILURE);
    }
    free(q);
}

int main()
{
    Queue *q = create_queue();
    enqueue(&q, 69);
    enqueue(&q, 70);
    enqueue(&q, 71);
    display(q);
    dequeue(&q);
    display(q);
    clearQueue(q);
    return 0;
}