// Naseem Auguste 2/13/2020
// Lab 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY -1

struct node
{

 int data;
 struct node * next;

}node;

struct queue
{

struct node * front;
struct node * back;

}queue;



void initialization(struct queue * qPtr);
int front(struct queue * qPtr);
int enqueue(struct queue * qPtr, int vol);
int dequeue(struct queue * qPtr);
int empty(struct queue * qPtr);
int display(struct node * front);


int main()
{

    struct queue * qPtr = (struct queue *) malloc (sizeof(queue));
    initialization(qPtr);
    enqueue(qPtr,10);
    enqueue(qPtr,100);
    enqueue(qPtr,1000);
    enqueue(qPtr,10000);
    enqueue(qPtr,100000);
    enqueue(qPtr,1000000);

    // printf("%d\n", qPtr->front->data);
    display(qPtr->front);

    dequeue(qPtr);
    display(qPtr->front);

    dequeue(qPtr);
    display(qPtr->front);

    dequeue(qPtr);
    display(qPtr->front);

    dequeue(qPtr);
    display(qPtr->front);

    dequeue(qPtr);
    display(qPtr->front);

    dequeue(qPtr);
    display(qPtr->front);

    return 0;

}



void initialization(struct queue * qPtr)
{

if (qPtr != NULL)
   qPtr->front = NULL;
    qPtr->back = NULL;

}



int front(struct queue * qPtr)
{
    if (qPtr != NULL && qPtr->front != NULL)
        return qPtr->front->data;
    else
        return EMPTY;
}



int enqueue(struct queue * qPtr, int num)
{

    struct node * temp = (struct node *)malloc (sizeof(node));

    if (temp != NULL)
    {
        temp->data = num;
        temp->next = NULL;

        if(qPtr!=NULL && qPtr->back != NULL)
            qPtr->back->next = temp;
        else
            qPtr->front = temp;
        qPtr->back = temp;

        return 1;
    }
    else
        return 0;
}



int dequeue(struct queue * qPtr)
{

    if (qPtr != NULL && qPtr->front == NULL)
     return EMPTY;

    struct node * temp = qPtr->front;
    qPtr->front = qPtr->front->next;

    if(empty(qPtr))
        qPtr->back = NULL;

    int retval = temp->data;
    free(temp);

    return retval;

}



int empty(struct queue * qPtr)
{

  return qPtr->front == NULL;

}


int display(struct node * front)
{
    if(front == NULL)
    {
        printf("NULL\n\n");
    }
    else
    {
        printf("%d\n", front -> data);
        display(front->next);
    }
}







