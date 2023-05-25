//Naseem Auguste Midterm Assignment 2

#include<stdio.h>
#include<stdlib.h>

typedef struct soldier
{

	int data;
	struct soldier * next, * prev;

} soldier;

soldier * head, * tail;
int n;

soldier * create_soldier(int sequence)
{
    soldier * soldierNode;

    soldierNode = (soldier *)malloc(sizeof(soldier));

        soldierNode -> data = sequence;
        soldierNode -> next = NULL;
        soldierNode -> prev = NULL;

        return soldierNode;

}

soldier * create_reverse_circle(int n)
{
    int i;
    i = n;
    soldier * ptr;

    ptr = create_soldier(n);

    for ( ; i> 0; i--)
     {

      if(ptr == NULL)
           printf("Error Overflow");
      else
        {
        if(head == NULL)
            {

                head = ptr;
                ptr -> next = head;
                ptr -> prev = head;
                tail = head;

            }
            else
            {

                ptr = create_soldier(i);

                tail -> next = ptr;
                ptr -> prev = tail;
                tail = ptr;
                //ptr -> next = head;

                tail->next = head;
                //tail->next = ptr;
                head->prev = tail;

            }

        }
     }
        return head;
}

soldier * rearrange_circle(soldier * head)
{
    int i;
    soldier * cur, * temp, * temp2;

    cur = head;
    temp = head -> prev;
    //temp2 = head -> next;
    //cur -> prev = cur;

    //printf("Rearranged List: \t");
    while(i < n)
    {

    //printf("cur:  %d\nhead:  %d\ncurNext:  %d\ncurPrev:  %d\ntail:  %d\n", cur->data, head->data, cur->next->data, cur->prev->data, tail->data);
    //printf("temp:  %d\ntemp2:  %d\n",temp->data, temp2->data);
    //printf("\n\n=============\n\n");

       // printf("%d ", cur->data);

        temp2 = cur->prev;
        cur -> prev = cur -> next;
        cur -> next = temp2;
        cur = cur -> next;

        //temp -> next = cur -> prev;
        //temp -> prev = temp2 -> prev;

        //cur -> prev = temp;
        //cur -> prev  = temp;
        //cur = temp;

        //temp = temp2;
        i++;

        //display(cur);
    }

    //printf("cur:  %d\nhead:  %d\ncurNext:  %d\ncurPrev:  %d\ntail:  %d\n", cur->data, head->data, cur->next->data, cur->prev->data, tail->data);
    //printf("temp:  %d\ntemp2:  %d\n",temp->data, temp2->data);
    //printf("\n\n=============\n\n");

        //printf("%d ", cur->data);
        //printf("\n\n======================================================================================\n\n");

        head = temp;
        return head;

}

void display(soldier * head)
{
    soldier * t;
    t= head;

    printf("%d ", t->data);
    t=t->next;

    while(t != head)
        {
        printf("%d ", t->data);
        t = t->next;
        }

}

int kill(soldier * head, int n, int k)
{
    soldier * temp, * temp2;
    int i;

    if(n==1)
        return head->data;

    temp = head;

    for(i = 0; i < k - 1; i++)
        temp = temp -> next;

    temp2 = temp -> next;
    temp -> next -> prev = temp -> prev;
    temp -> prev -> next = temp -> next;

    n--;

    printf("Prisoner #%d", temp -> data);
    if (temp != NULL)
        printf(" dies. ");

    return kill(temp2, n, k);
}


int main()
{

    head = NULL;

    int k, safe;
    printf("Please enter the execute count followed by the skip increments.\n");
    scanf("%d %d", &n, &k);

    printf("\n");

    //for ( ; n>= 0; n--)
    create_reverse_circle(n);

    display(head);
    printf("\n\n======================================================================================\n\n");

    rearrange_circle(head);
    display(head);

    safe = kill (head, n, k);

    printf("\n\n======================================================================================\n\n");

    printf("\n\nPrisoner #%d shall not be executed.\n\n", safe);




    return 0;
}


