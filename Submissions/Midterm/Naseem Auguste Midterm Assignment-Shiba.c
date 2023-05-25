// COP 3502C Midterm Assignment One
// This program is written by: Naseem Auguste

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define EMPTY -1

typedef struct
{
    int items[SIZE];
    int top;

} stack;

char* Menu();
int Parentheses(char *);
char* Postfix(char *);
void Evaluate(char *);
int Operator(char c);
int Priority(char c);
int IntegerConvert(char c);
int Calculate(int a, int b, char op);

void initialize(stack *stackPtr);
int pop(stack *stackPtr);
int push(stack *stackPtr, int value);
int empty(stack *stackPtr);
int full(stack *stackPtr);
int peek(stack *stackPtr);

int main(void)
{
    int i, postFix;
    // stack myStack;
    char * str;

    while(strcmp(str = Menu(), "exit")!=0)
    {
        if (Parentheses(str))
        {
            //postFix = Postfix(str);
            //printf("Output: %s", postFix);
            //evaluate(postFix);
        }
    else
        printf("Parentheses imbalanced");
    }


 return 0;
}





char* Menu()
{
    char choice;
    char Infix[50];

    printf("Howdy there! Welcome to the menu!\n");
    printf("Please choose an command.\n");
    printf("E to Enter an Infix Equation.\n");
    printf("X to Exit the Program.\n");

    scanf("%c", choice);
/*
    while(choice != 'E' || choice != 'e' || choice != 'X' || choice != 'x')
    {
        printf("Invalid input please try again.");
        scanf("%s", choice);
    }
*/
    if (choice == 'E' || choice == 'e')
    {
        printf("Please input your equation.\n");
        scanf("%[^n]s", Infix);
        int length = strlen(Infix);
        length = length + 1;
        char * InfixPTR = (char *)malloc(length * sizeof(char));
        strcpy(InfixPTR, Infix);
        return InfixPTR;
    }
    if (choice == 'X' || choice == 'x')
    {
        char exit[5] = "exit";
        char * InfixPTR = (char *)malloc(exit[5] * sizeof(char));
        return InfixPTR;
    }
}

int Parentheses(char *exp)
{
    char c, valid;
    stack myStack;

    printf("Howdy");

    for (int i = 0; i != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(&myStack, exp[i]);

        else if (exp[i] == ')')
        {
            pop(&myStack);
            if (c == 'I' || c != '(')
            {
            valid = 'I';
            printf("Invalid for ) at [%d].\n", i);
            break;
            }
        }

        else if (exp[i] == '}')
        {

            pop(&myStack);
            if (c == 'I' || c != '{')
            {
            valid = 'I';
            printf("Invalid for } at [%d].\n", i);
            break;
            }
        }

        else if (exp[i] == ']')
        {
            pop(&myStack);
            if (c == 'I' || c != ']')
            {
            valid = 'I';
            printf("Invalid for ] at [%d].\n", i);
            break;
            }
        }
    }

    if(!empty(&myStack))
    {
        printf("There are still excess characters in stack.\n");
        return 0;
    }
}













void initialize(stack *stackPtr)
{
    stackPtr->top = -1;
}

int push(stack *stackPtr, int value)
{

    if (full(stackPtr))// Check if the stack is full.
        return 0;

    stackPtr->items[stackPtr->top + 1] = value; // Add value to the top of the stack and adjust the value of the top.
    (stackPtr->top)++;
    return 1;
}

int full(stack *stackPtr)
{
    return (stackPtr->top == SIZE - 1);
}

int empty(stack *stackPtr)
{
    return (stackPtr->top == -1);// Returns true iff the stack pointed to by stackPtr is empty.
}

int pop(stack *stackPtr)
{

    if (empty(stackPtr)) // Check the case that the stack is empty.
        return EMPTY;

    int retval = stackPtr->items[stackPtr->top];// Retrieve the item from the top of the stack, adjust the top and return the item.
    (stackPtr->top)--;
    return retval;
}

int peek(stack *stackPtr)
{

    if (empty(stackPtr))// Take care of the empty case.
        return EMPTY;

    return stackPtr->items[stackPtr->top]; // Return the desired item.
}
