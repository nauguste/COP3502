// Arup Guha 6/20/07
// modifed by Tanvir Ahmed
// modified: Kazakova 01/28/2020
// Written in COP 3502 to illustrate an array implementation of a stack.
// The array will store the items in the stack, first in index 0, then 1, etc. top will represent the index
// to the top element in the stack. If the stack is empty top will be -1.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1

typedef struct{
    int items[SIZE];
    int top;//index of top element (-1 when empty)
} stack;

void initialize(stack *stackPtr);
int pop(stack *stackPtr);
int push(stack *stackPtr, int value);
int empty(stack *stackPtr);
int full(stack *stackPtr);
int peek(stack *stackPtr);
//--------------------------------------------------------------------------------------------------
int main(){
    int i;
    stack myStack;

    initialize(&myStack);// Setup stack
    printf("Pushing %d\n", 4);
    push(&myStack, 4);
    printf("Pushing %d\n", 5);
    push(&myStack, 5);
    printf("Popping... %d\n", pop(&myStack));
    printf("Pushing %d\n", 22);
    push(&myStack, 22);
    printf("Pushing %d\n", 16);
    push(&myStack, 16);
    printf("At top now = %d\n", peek(&myStack));

    for (i=0; i<3; i++) // Pop three off
        printf("Popping... %d\n", pop(&myStack));

    if (empty(&myStack))// Check empty()
        printf("The stack is empty as expected.\n");

    for (i = 0; i < 10; i++) {// Fill stack
    	printf("Pushing %d\n", i);
        push(&myStack, i);
    }

    if (full(&myStack))// Check full()
        printf("This stack is full as expected.\n");

    while (!empty(&myStack)) // Pop errything off
        printf("popping %d\n", pop(&myStack));

    //system("PAUSE");//ONLY ON WINDOWS CMD
    
    //printf("Press ENTER key to Continue\n");  
	//getchar(); 

    return 0;
}
//--------------------------------------------------------------------------------------------------
void initialize(stack *stackPtr){
    stackPtr->top = -1;
}
//--------------------------------------------------------------------------------------------------
// successful push returns 1; otherwise 0
int push(stack *stackPtr, int value){

    if (full(stackPtr))// Check if the stack is full.
        return 0;

    stackPtr->items[stackPtr->top + 1] = value; // Add value to the top of the stack and adjust the value of the top.
    (stackPtr->top)++;
    return 1;
}
//--------------------------------------------------------------------------------------------------
int full(stack *stackPtr) { // Returns true iff the stack pointed to by stackPtr is full.

    return (stackPtr->top == SIZE - 1);
}
//--------------------------------------------------------------------------------------------------
int empty(stack *stackPtr){
    return (stackPtr->top == -1);// Returns true iff the stack pointed to by stackPtr is empty.
}
//--------------------------------------------------------------------------------------------------
// Pre-condition: The stack pointed to by stackPtr is NOT empty.
// Post-condition: The value on the top of the stack is popped and returned.
// Note: If the stack pointed to by stackPtr is empty, -1 is returned.
int pop(stack *stackPtr){

    if (empty(stackPtr)) // Check the case that the stack is empty.
        return EMPTY;

    int retval = stackPtr->items[stackPtr->top];// Retrieve the item from the top of the stack, adjust the top and return the item.
    (stackPtr->top)--;
    return retval;
}
//--------------------------------------------------------------------------------------------------
// Pre-condition: The stack pointed to by stackPtr is NOT empty.
// Post-condition: The value on the top of the stack is returned.
// Note: If the stack pointed to by stackPtr is empty, -1 is returned.
int peek(stack *stackPtr){

    if (empty(stackPtr))// Take care of the empty case.
        return EMPTY;

    return stackPtr->items[stackPtr->top]; // Return the desired item.
}