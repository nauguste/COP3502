//this code illustrate a simple array based stack which is globally declared
#include <stdio.h>
#define size 6
int stack[size];
int top;
void PUSH(int element)
{
    if (top >= size-1)
        printf("STACK FULL !!!");
    else
    stack[++top] = element;
}
int POP()
{
    if(top<0)
    {
        printf("STACK IS EMPTY!!!");
        return 0;
    }
    return stack[top--];
}

void display()
{
    printf("\nPrinting the Current stack...");
    for(int i=0; i<=top; i++)
        printf("%d ", stack[i]);
}
int main(void)
{
    int ele;
    int ch;
    top = -1;
    while(1)
    {
        printf("\npress 1 for Push, press 2 for POP, press 3 for displaying, press 4 for Exit\nEnter your choice: ");
        scanf("%d",&ch);
        if(ch==4)
        {
            printf("<<EXIT>>");
            break;
        }
        else if (ch==1)
        {
            printf("Enter an element to PUSH in the stack: ");
            scanf("%d",&ele);
            PUSH(ele);
        }
        else if (ch==2)
        {
            ele = POP();
            if(ele!=0 )
            {
                printf(" ITEM POPED :%d ",ele);
            }
        }
        else if(ch==3)
        {
            display();
        }
    }
	return 0;
}
