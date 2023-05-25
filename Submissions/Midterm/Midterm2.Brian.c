//Naseem Auguste Midterm Assignment 2

#include<stdio.h>
#include<stdlib.h>

typedef struct soldier
{

	int data;
	struct soldier * next, * prev;

} soldier;

soldier * head, * tail;

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
    soldier * ptr;

    ptr = create_soldier(n);

    for ( ; n> 0; n--)
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

                ptr = create_soldier(n);

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

    soldier * cur, * temp, * temp2;
/*
    cur = head;
    temp = cur -> next;
    cur -> next = cur -> prev;
    temp2 = cur -> prev;
    cur -> prev = temp;

    while (cur != head)
    {

    }

    printf("cur:  %d\nhead:  %d\ncurNext:  %d\ncurPrev:  %d\ntail:  %d\n", cur->data, head->data, cur->next->data, cur->prev->data, tail->data);
    printf("temp:  %d\ntemp2:  %d\n",temp->data, temp2->data);
*/

    temp = head;
    cur = head -> prev;
    temp2 = head -> next;
    //cur -> prev = cur;

    printf("Rearranged List: \t");
    while(cur != head)
    {

    //printf("cur:  %d\nhead:  %d\ncurNext:  %d\ncurPrev:  %d\ntail:  %d\n", cur->data, head->data, cur->next->data, cur->prev->data, tail->data);
    //printf("temp:  %d\ntemp2:  %d\n",temp->data, temp2->data);
    //printf("\n\n=============\n\n");

        printf("%d ", cur->data);

        temp = cur;
        cur = cur -> prev;
        temp2 = temp2 -> next;

        //temp -> next = cur -> prev;
        //temp -> prev = temp2 -> prev;

        //cur -> prev = temp;
        //cur -> prev  = temp;
        //cur = temp;

        //temp = temp2;


        //display(cur);
    }

    //printf("cur:  %d\nhead:  %d\ncurNext:  %d\ncurPrev:  %d\ntail:  %d\n", cur->data, head->data, cur->next->data, cur->prev->data, tail->data);
    //printf("temp:  %d\ntemp2:  %d\n",temp->data, temp2->data);
    //printf("\n\n=============\n\n");
        printf("%d ", cur->data);
        printf("\n\n======================================================================================\n\n");


        return cur;

}

void display(soldier * head)
{
    if (head == NULL)
        return;

    soldier * s;
    s = head;

    printf("List:           \t");
    while (s->next != head)
        {
            printf("%d ", s->data);
            s = s->next;
        }
        printf("%d ", s->data);


}

int kill(soldier * head, int n, int k)
{
    soldier * temp, * temp2, * temp3;
    int i,j;
    j=n;

    temp = head->prev;

    while(head->next != head)
        {

    for(i = 0; i < k - 1 ; i++)
        temp = temp -> prev;

    temp2 = temp -> next;
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;

    j--;

    printf("Prisoner #%d", temp -> data);
    if (temp != NULL)
        printf(" dies. ");
        }

    return temp2->data;
}


int main()
{

    head = NULL;

    int n, k, safe;
    printf("Please enter the execute count followed by the skip increments.\n");
    scanf("%d %d", &n, &k);

    printf("\n");

    //for ( ; n>= 0; n--)
    create_reverse_circle(n);

    display(head);
    printf("\n\n======================================================================================\n\n");

    rearrange_circle(head);
    //display(head);

    safe = kill (head, n, k);

    printf("\n\n======================================================================================\n\n");

    printf("\n\nPrisoner #%d shall not be executed.\n\n", safe);




    return 0;
}


