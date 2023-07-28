#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void peek();
void isFull();
void isEmpty();

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *next;
} Queue;

int main()
{
    return 0;
}