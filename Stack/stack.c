// Dynamic Stack implementation (FILO)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Stack *create_empty_stack(){
    Stack *stk = malloc(sizeof(Stack));
    if(stk == NULL){
        puts("Memory allocation failed.");
        exit(-1);
    }
    stk->top = NULL;
    puts("Empty Stack created."); 
    return stk;
}

// check if the stack is empty
int isEmpty(Stack *sk){
    if(sk->top == NULL) return  1;
    return 0;
}

// add the element to the stack
void push(Stack **stk, int data){
    Node *newN = malloc(sizeof(Node));
    newN->data = data;
    newN->next = (*stk)->top;
    (*stk)->top = newN;
}

// remove the first element from the stack
void pop(Stack **stk){
    if(isEmpty(*stk)){
        puts("The STACK is empty.");
        return;
    }

    int d = (*stk)->top->data;  
    Node *temp = (*stk)->top;
    (*stk)->top = (*stk)->top->next;
    free(temp);
}

// get the top most element
void peek(Stack *stk){
    if(stk->top == NULL){
        puts("The Stack is Empty.");
        return;   
    }

    printf("%d\n", stk->top->data);
}

void display_stack(Stack *stk){
    if(stk->top == NULL)
    {
        puts("The STACK is empty.");
        return;
    }

    Node *curr = stk->top;
    while(curr != NULL)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

int main(){
    Stack *stk = create_empty_stack();
    printf("%s", isEmpty(stk) == true ? "true\n": "false\n");
    push(&stk, 69);
    push(&stk, 70);
    push(&stk, 71);
    pop(&stk);
    peek(stk);
    display_stack(stk);
    return 0;
}