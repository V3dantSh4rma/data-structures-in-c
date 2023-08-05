# Windows 
SHELL=pwsh

sll: # Singly linked list
	gcc ./"Linked List"/singly_linked_list.c -o main
	./main.exe
	del main.exe

dll: # Doubly Linked List
	gcc ./"Linked List"/doubly_linked_list.c -o main
	./main.exe
	del main.exe

cll: # Circular Linked list
	gcc ./"Linked List"/circular_linked_list.c -o main
	./main.exe	
	del main.exe

stk:
	gcc ./Stack/stack.c -o main
	./main.exe
	del main.exe

q:
	gcc ./Queue/queue.c -o main
	./main.exe
	del main.exe

cq:
	gcc ./Queue/circular_queue.c -o main
	./main.exe
	del main.exe