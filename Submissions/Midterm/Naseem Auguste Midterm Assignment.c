// COP 3502C Midterm Assignment One
// This program is written by: Naseem Auguste

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10
#define EMPTY -1

typedef struct
{
    int items[SIZE];
    int top;
}stack;

int STACK[SIZE];
int TOP;

char* Menu();
int Parentheses(char *);
char * Postfix(char *);
void Evaluate(char *);
int Operator(char c);
int Priority(char c);
int Conversion(char c);
int Calculate(int a, int b, char op);

void PUSH(int value);
int POP();
void initialize(stack * stackPtr);
char pop(stack * stackPtr);
int push(stack * stackPtr, int value);
int empty(stack * stackPtr);
int full(stack * stackPtr);
int peek(stack * stackPtr);

int main(void)
{
    int i;
    stack myStack;
    initialize(&myStack);
    char * postFix;
    char * str;

    printf("Howdy there! Welcome to the menu!\n");

    while(strcmp(str = Menu(), "exit")!=0)
    {
        printf("Infix: %s.\n\n", str);
        if (Parentheses(str))
        {
            printf("Parentheses Balanced\n\n");
            postFix = Postfix(str);
            printf("Postfix: %s\n", postFix);
            Evaluate(postFix);
        }
    else
        {
        printf("Parentheses imbalanced.\n");
        printf("Postfix: N/A\n");
        printf("Value: N/A\n");
        break;
        }
    }
 return 0;
}

char * Menu()
{
    char choice;
    char Infix[50];

    printf("Please choose an command.\n");
    printf("E to Enter an Infix Equation.\n");
    printf("X to Exit the Program.\n\n");

    scanf("%c", &choice);

    while(choice != 'E' && choice != 'e' && choice != 'X' && choice != 'x')
    {
        printf("Invalid input please try again.\n");
        scanf(" %c", &choice);
    }

    if (choice == 'E' || choice == 'e')
    {
        printf("Please input your equation.\n");
        scanf("%s", Infix);

        int length = strlen(Infix);
        length = length + 1;
        char * InfixPTR = (char *)malloc(length * sizeof(char));
        strcpy(InfixPTR, Infix);
        return InfixPTR;
    }
    else if (choice == 'X' || choice == 'x')
    {
        char * InfixPTR = (char *)malloc(5 * sizeof(char));
        strcpy(InfixPTR, "exit");
        return InfixPTR;
    }
}

int Parentheses(char * exp)
{
    int i;
    char c;
    stack myStack;
    initialize(&myStack);

    printf("Balancing...\n");

    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(&myStack, exp[i]);

        if (exp[i] == ')')
        {
            c = pop(&myStack);

            if(c != '(')
                 return 0;
        }


        if (exp[i] == '}')
        {
            c = pop(&myStack);

            if(c != '{')
                 return 0;
        }

        if (exp[i] == ']')
        {
            c = pop(&myStack);

            if(c != '[')
                 return 0;
        }
    }

            if (!empty(&myStack))
            {
                printf("There are still excess characters in stack.\n");
                return 0;
            }
            else
                return 1;

}

char * Postfix(char * exp)
{

int i = 0, j = 0, k = 0;
char * temp = (char *)malloc(SIZE * sizeof(char));

stack myStack;
initialize(&myStack);

for(i = 0, k = 0; i , k < strlen(exp); k++, i++)
    {
        if (!Operator(exp[i]))
        {
            exp[j++] = exp[i];
            temp[k++]= ' ';
        }
        else if (exp[i] == '(')
        {
            push(&myStack, exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!empty(&myStack) && peek(&myStack) != '(')
                    exp[j++] = pop(&myStack);
                if(!empty(&myStack) && peek(&myStack) != '(')
                    return 0;
                else
                     pop(&myStack);
        }
        else
        {
            while (!empty(&myStack) && Priority(exp[i]) <= Priority(peek(&myStack)))
                exp[j++] = pop(&myStack);
            push(&myStack, exp[i]);
        }
    }
 while(!empty(&myStack))
    exp[j++] = pop(&myStack);

    exp[j++]= '\0';

  printf("Postfix: %s\n", exp);//, temp);
 return exp;

}

void Evaluate(char * exp)
{
int i = 0, digit = 0, num1, num2, result;
int value = 0;
int integer[strlen(exp)];

stack myStack;
initialize(&myStack);

    for( i = 0; i < strlen(exp); i++){
         if(isdigit(exp[i]) && isdigit(exp[i+1]) && isdigit(exp[i+2]) && isdigit(exp[i+3]))
         {
             digit = Conversion(exp[i]);
             digit = digit * 10 + Conversion(exp[i+1]);
             digit = digit * 10 + Conversion(exp[i+2]);
             digit = digit * 10 + Conversion(exp[i+3]);
             PUSH(digit);
         }
         else if(isdigit(exp[i]) && isdigit(exp[i+1]) && isdigit(exp[i+2]))
         {
             digit = Conversion(exp[i]);
             digit = digit * 10 + Conversion(exp[i+1]);
             digit = digit * 10 + Conversion(exp[i+2]);
             PUSH(digit);
         }
         else if(isdigit(exp[i]) && isdigit(exp[i+1]))
         {
             digit = Conversion(exp[i]);
             digit = digit * 10 + Conversion(exp[i+1]);
             PUSH(digit);
         }
        else if (Operator(exp[i]))
        {
            num2 = POP();
            num1 = POP();
            result = Calculate(num1, num2, exp[i]);
            PUSH(digit);
        }
        else if (exp[i] != ' ')
        {
            digit = Conversion(exp[i]);
            PUSH(digit);
        }
    }
        result = POP();
        printf("Value : %d\n\n", result);
}

int Calculate(int a, int b, char op)
{
  int math;
    if (op == '+')
        math = a + b;
        return math;

    if (op == '-')
    math = a - b;
        return math;
    if (op == '*')
    math = a * b;
        return math;
    if (op == '/')
    math = a / b;
        return math;
    if (op == '%')
    math = a % b;
        return math;
    if (op == '^')
    {
        while (b != 0)
            a *= a;
        return a;
    }
}


int Conversion(char c)
{
    int x;
    x = c-'0';
    return x;
}

int Priority(char c)
{
    if( c == '+' || c == '-')
        return 1;
    else if( c == '*' || c == '/' || c == '%')
        return 2;
    else if( c == '^')
        return 3;
    else
        return 0;
}

int Operator(char c)
{
    if(c == '+' || c == '-' || c == '/' || c == '*' || c == '%' || c == '^' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')
        return 1;
    else
        return 0;
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
    return (stackPtr->top == -1);// Returns true if the stack pointed to by stackPtr is empty.
}

char pop(stack *stackPtr)
{

    if (empty(stackPtr)) // Check the case that the stack is empty.
        return EMPTY;

    char retval = stackPtr->items[stackPtr->top];// Retrieve the item from the top of the stack, adjust the top and return the item.
    (stackPtr->top)--;
    return retval;
}

int peek(stack *stackPtr)
{

    if (empty(stackPtr))// Take care of the empty case.
        return EMPTY;

    return stackPtr->items[stackPtr->top]; // Return the desired item.
}


void PUSH(int value)
{
    if (TOP >= SIZE-1)
        return ;
    else
    STACK[++TOP] = value;
}
int POP()
{
    if(TOP<0)
    {
        return 0;
    }
    return STACK[TOP--];
}




