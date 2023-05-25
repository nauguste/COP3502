// Naseem Auguste 2/13/2020
// Lab 4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY -1
#define SIZE 6

typedef struct
{

    int accountNo;
    char name[100];

} customers;

typedef struct
{

    customers * elements;
    int front;
    int numCallers;
    int queueSize;


} queue;



void displayQueue(queue * qPtr);
void initialization(queue * qPtr);
void enqueue(queue * qPtr);
void dequeue(queue * qPtr);
int empty(queue * qPtr);


int main()
{
    queue* qPtr = (queue *) malloc (sizeof(queue));
    char choice[2] = {'c','s'};

    initialization(qPtr);

    while(1)
    {

        int i = rand() % 2;

         if(choice[i]== 'c')
         {

            printf("Answering Call...\n");
            enqueue(qPtr);

         }

         else if(choice[i]== 's')
         {

            printf("Serving Caller...\n");
            dequeue(qPtr);

         }

    displayQueue(qPtr);

    }
    return 0;
}



void displayQueue(queue * qPtr)
{

    printf("Status: ");

    if(empty(qPtr))
        printf("EMPTY\n\n");
    else
    {

    printf("(%d Customers) \n", qPtr->numCallers);
    int i, j;
    for(i = 0; i < qPtr->numCallers; i++)
        {

        j = (qPtr->front + i) % qPtr->queueSize;
        printf("%d %s", qPtr->elements[j].accountNo, qPtr->elements[j].name);
        printf("\n\n");

        }

    }
}

void initialization(queue * qPtr)
{

     qPtr->elements = (customers *) malloc (sizeof(customers) * SIZE);
     qPtr->front = 0;
     qPtr->numCallers = 0;
     qPtr->queueSize = SIZE;

}



void enqueue(queue * qPtr)
{

    int i;

    if (qPtr->numCallers != qPtr->queueSize)
    {

        int newcaller = (qPtr->front + qPtr->numCallers) % qPtr->queueSize;

        printf("We appreciate you calling. Please enter your account number.\n");
        scanf("%d", &qPtr->elements[newcaller].accountNo );

        printf("To proceed with the process, please enter your name.\n");
        scanf("%s", qPtr->elements[newcaller].name);
        printf("\n");

        (qPtr->numCallers)++;

    }

    else
        printf("Sorry out phone lines are facing a\nhigh volume of calls. Please call back later.\n\n");

}



void dequeue(queue * qPtr)
{

    if (empty(qPtr))
        printf("There are no customers in the caller queue right now.\n");
    else
    {

     printf("Customer served: %d %s\n\n", qPtr->elements[qPtr->front].accountNo, qPtr->elements[qPtr->front].name);

    qPtr->front = (qPtr->front + 1)% qPtr->queueSize;
    (qPtr->numCallers)--;

    }
}



int empty(queue * qPtr)
{
    return qPtr->numCallers == 0;
}


