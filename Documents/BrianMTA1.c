/*COP 3502 Midterm Assignment One
This program is written by: Brian Anthony Malyszka*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define SIZE 50
#define EMPTY -1

typedef struct {
    int top;
    char *equation;
} stack;

typedef struct {
    int top;
    int *equation;
} intStack;

int isBalancedParenthesis(char *);
void evaluate(char *postFix);
int calculate(int a, int b, char op);
int convertToInt(char c);
char *convertToPostfix(char *);
int getOperatorPriority(char c);
int isOperator(char c);
void initialize(stack* stackPtr);
void initialize_int(intStack* stackPtr);
int full(stack* stackPtr);
int full_int(intStack* stackPtr);
int push(stack* stackPtr, char value);
int push_int(intStack* stackPtr, int value);
int empty(stack* stackPtr);
int empty_int(intStack* stackPtr);
char pop(stack* stackPtr);
int pop_int(intStack* stackPtr);
int top(stack* stackPtr);
char peek(stack* stackPtr);
char *menu();


int main(void)
{
 char *str, *postFix;


 while(strcmp(str = menu(), "exit") != 0)
    {
        if (isBalancedParenthesis(str))
            {
                postFix = malloc(strlen(str)*sizeof(char));
                postFix = convertToPostfix(str);
                printf("Output: %s", postFix);
                evaluate(postFix);
            }
        else
            printf("parenthesis: imbalanced\npostfix: n/a\nvalue: n/a");
    }

    free(str);
    free(postFix);
 return 0;
}

void evaluate(char *postFix)
{
    intStack *operands = malloc(sizeof(intStack));
    operands->equation = (int *) malloc(sizeof(int));
    initialize_int(operands);

    int i, temp, evaluation, multiDigit = 0;
    int operand1, operand2;

    for(i = 0; i < strlen(postFix); i++)
    {
        if(isdigit(postFix[i]) != 0)
        {
            multiDigit = postFix[i] - '0';
            temp = i;
            while(postFix[temp+1] != 32)
            {
                temp++;
                multiDigit = multiDigit*10;
                multiDigit = multiDigit + convertToInt(postFix[temp]);
                i++;
            }
            push_int(operands, multiDigit);
        }
        if(isOperator(postFix[i]) == 1)
        {
            operand2 = pop_int(operands);
            operand1 = pop_int(operands);
            evaluation = calculate(operand1, operand2, postFix[i]);
            push_int(operands, evaluation);
        }
    }

    printf("\nvalue: %d\n", pop_int(operands));
    free(operands->equation);
    free(operands);
}

int calculate(int a, int b, char op)
{

    switch(op)
    {
    case '+':
        return (a+b);
    case '*':
        return (a*b);
    case '/':
        return (a/b);
    case '-':
        return (a-b);
    case '^':
        return (a^b);
    case '%':
        return (a%b);
    }
}


int convertToInt(char c)
{
    return atoi(&c);
}

char *convertToPostfix(char *inFix)
{
    char *postFix = calloc(SIZE, sizeof(char));
    stack *operators = malloc(sizeof(stack));
    operators->equation = calloc(SIZE, sizeof(char));

    initialize(operators);
    int i, j = 0, counter, currentStack;

    for(i = 0; i < strlen(inFix); i++)
    {
        //if(inFix[i] == 32) continue; //skips over spaces; 32 is ascii code for space
        if(isOperator(inFix[i]) == 0)
        {
            postFix[j] = inFix[i];
            j++;
        }
        if(isOperator(inFix[i]) == 2)
            push(operators, inFix[i]);
        if(isOperator(inFix[i]) == -2)
        {
            currentStack = strlen(operators->equation);
            for(counter = i; counter > 0; counter--)
            {
                if(operators->equation[operators->top] == '(' || operators->equation[operators->top] == '[' || operators->equation[operators->top] == '{')
                {
                 pop(operators);
                 break;
                }
                postFix[j] = 32;
                j++;
                postFix[j] = pop(operators);
                j++;
                postFix[j] = 32;
                j++;
            }
        }
        if(empty(operators) != EMPTY && isOperator(inFix[i]) != 2 && isOperator(inFix[i]) != -2)
        {
            while(getOperatorPriority(inFix[i]) <= getOperatorPriority(peek(operators)) && empty(operators) != EMPTY)
            {
                postFix[j] = 32;
                j++;
                postFix[j] = pop(operators);
                j++;
            }
        }
        if(isOperator(inFix[i]) == 1)
        {
             postFix[j] = 32;
             j++;
             push(operators, inFix[i]);
        }

        }
    currentStack = strlen(operators->equation);
    for(i = 0; i < currentStack; i++)
    {
        if(empty(operators) == EMPTY)
            break;
        postFix[j] = 32;
        j++;
        postFix[j] = pop(operators);
        j++;
    }

    free(operators->equation);
    free(operators);
    return postFix;
}

int getOperatorPriority(char c)
{
    if(c == '(' || c == '[' || c == '{' || c == ')' || c == ']' || c == '}') return 0;
    if(c == '^') return 3;
    if(c == '*' || c == '/' || c == '%') return 2;
    if(c == '+' || c == '-') return 1;
}

int isOperator(char c)
{
    if(c == '+') return 1;
    if(c == '*') return 1;
    if(c == '/') return 1;
    if(c == '-') return 1;
    if(c == '^') return 1;
    if(c == '%') return 1;
    if(c == '(' || c == '[' || c == '{') return 2;
    if(c == ')' || c == ']' || c == '}') return -2;
    return 0;
}

int isBalancedParenthesis(char* expression)
{
    int i;
    char test;
    stack *parenthesis = malloc(sizeof(stack *));
    parenthesis->equation = malloc(SIZE*sizeof(char));
    initialize(parenthesis);

    for(i=0;i<SIZE;i++)
    {
        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
            push(parenthesis, expression[i]);
        if(expression[i] == ')')
        {
            test = pop(parenthesis);
            if(test != '(') return 0;
        }
        if(expression[i] == ']')
        {
            test = pop(parenthesis);
            if(test != '[') return 0;
        }
        if(expression[i] == '}')
        {
            test = pop(parenthesis);
            if(test != '{') return 0;
        }
    }
    if(empty(parenthesis) != -1)
        return 0;

    printf("parenthesis: balanced\n");
    free(parenthesis->equation);
    free(parenthesis);
    return 1;
}

void initialize(stack* stackPtr) {
     stackPtr->top = -1;
}

void initialize_int(intStack* stackPtr) {
     stackPtr->top = -1;
}

int full(stack* stackPtr) {
    return (stackPtr->top == SIZE - 1);
}

int full_int(intStack* stackPtr) {
    return (stackPtr->top == SIZE - 1);
}

char peek(stack* stackPtr)
{
    char retval;
    retval = stackPtr->equation[stackPtr->top];
    return retval;
}

int push(stack* stackPtr, char value) {


    if (full(stackPtr))
        return 0;


    stackPtr->equation[stackPtr->top+1] = value;
    (stackPtr->top)++;
    return 1;
}

int push_int(intStack* stackPtr, int value) {


    if (full_int(stackPtr))
        return 0;


    stackPtr->equation[stackPtr->top+1] = value;
    (stackPtr->top)++;
    return 1;
}

int empty(stack* stackPtr) {
    if(stackPtr->top == -1)
    return EMPTY;
}

int empty_int(intStack* stackPtr) {
    if(stackPtr->top == -1)
    return EMPTY;
}

char pop(stack* stackPtr) {

    char retval;


    if (empty(stackPtr) == EMPTY)
        return EMPTY;


    retval = stackPtr->equation[stackPtr->top];
    (stackPtr->top)--;
    return retval;
}

int pop_int(intStack* stackPtr) {

    int retval;


    if (empty_int(stackPtr) == EMPTY)
        return EMPTY;


    retval = stackPtr->equation[stackPtr->top];
    (stackPtr->top)--;
    return retval;
}

int top(stack* stackPtr) {


    if (empty(stackPtr))
        return EMPTY;


    return stackPtr->equation[stackPtr->top];
}

char *menu()
{
    char choice = 'a';
    char *str;

    while(1)
    {
    scanf("%c", &choice);
    switch(choice)
    {
        case 'e':
        str = malloc(SIZE*sizeof(char));
        scanf(" %50[^\n]", str);

        printf("infix: %s\n", str);
        return str;
    case 'x':
        return "exit";
    }
    }

}
