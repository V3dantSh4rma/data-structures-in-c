/**
 * Methods:
 * - Insertion
 * - Deletion
 * - Traverse 
 * - Reversing a Linked List
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_linked_list(int nodes){
    Node *head = NULL;
    Node *temp = NULL;
    Node *current = head;

    for(int i = 1; i <= nodes; i++){
        temp=malloc(sizeof(Node));
        printf("Enter the Value of %d node: ", i);
        scanf("%d", &temp->data);
        temp->next = NULL;


        if(head == NULL){
            head = temp;
        } else {
            current = head;
            while(current->next!=NULL) current = current->next;
            current->next=temp;
        }
    }
    
    return head;
}

bool does_exists(Node *head, int key){
    while(head!=NULL){
        if(head->data == key) return true;
        head = head->next; 
    }
    return false;
}

int get_position(Node *head, int key){
    bool exists = does_exists(head, key);
    if(exists == false) return -1;
    int counts = 0;
    Node *curr = head;
    while(curr != NULL){
        if(curr->data == key) return counts;
        counts++;
        curr = curr->next;
    }
    return counts;
}

// Methods
void traverse(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

Node *insert(Node *head, int key){
    bool exists = does_exists(head, key);
    if(exists == true){
        puts("The Node already exists in the linked list. Try again.");
        exit(-1);
    }
    Node *new_node = malloc(sizeof(Node));
    new_node->data=key;
    new_node->next=head;
    head=new_node;
    return head;
}

Node *delete(Node *head, int key){
    Node *prev = head;
    Node *current = head;
    int pos = get_position(head, key);
    
    if(pos==-1){
        puts("The node is not present in the Linked List. Try again.");
        exit(-1);
    }
    
    if(pos==0){
        head = head->next;
        return head;
    }

    for(int i = 0; i < pos; i++){
        current = current->next;
    }

    for(int j = 0; j < pos-1; j++){
        prev = prev->next;
    }

    prev->next=current->next;
    return head;
}

Node *reverse(Node *head){
    Node *prev = NULL;
    Node *current = head;
    Node *nextNode;

    while(current != NULL){
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

int main(void){
    int nodes;
    Node *head = NULL;
    int key;

    
    printf("Enter the Total Nodes of a Linked List: ");
    scanf("%d", &nodes);
    
    head = create_linked_list(nodes);

    traverse(head);
    printf("Enter the Node which you want to insert: ");
    scanf("%d", &key);  

    head = insert(head, key);
    
    puts("////LINKED LIST AFTER INSERTION////");
    traverse(head);

    printf("Enter the Node which you want to remove from the Linked List: ");
    scanf("%d", &key);
    
    head = delete(head, key);
    
    puts("////////LINKED LIST AFTER DELETION////////");
    traverse(head);

    puts("////////LINKED LIST AFTER REVERSING///////");
    head = reverse(head); // reverses the node you gave as the input
    traverse(head);
    head = reverse(head); // reverses the "reversed" linked list back to the original.
    traverse(head);
    return 0;
}
