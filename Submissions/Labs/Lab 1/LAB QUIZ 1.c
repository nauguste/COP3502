/* INSTRUCTIONS:
You are not allowed to get help from the internet or from existing files on your computer.
The following code creates a linked list with 3, 4, 5, 6.
Function simplePrint prints the contents of the linked list.
You can run and test the code as provided.

What you have to do:

Complete the two blank functions bellow based on the requirements described as comments inside each function.
Run the code again and make sure your output matches the result listed as a comment on the calling line in main().

After completing the code and testing, submit the modified file in Webocurses BEFORE the due time.
Caution: No code will be accepted in email if you miss the deadline.
Do not share your code as sharing is considered cheating and will be treated accordingly.

                YOUR NAME : Naseem Auguste
                YOUR UCFID: 5043455

*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node * next;
}node;

node * insert_list(node * root, int item); // DO NOT TOUCH THIS FUNCTION
void simplePrint(node * root); // DO NOT TOUCH THIS FUNCTION
int countNodes (node * root); // write this function in spot below (5 points)
int check_sorted(node * root); // write this function in spot below (5 points)

int main(){// DO NOT TOUCH THIS FUNCTION

    node * head1=NULL;
	node * head2 = NULL;

    //----------------------------------------------------------------------------------------

	head1 = insert_list(head1,4);
	head1 = insert_list(head1,6);
	head1 = insert_list(head1,3);
	head1 = insert_list(head1,5);

    printf("\nContents List 1: ");
    simplePrint(head1);
    printf("\nCount Nodes: %d\n", countNodes(head1)); //modify the countNodes function to make it work
    printf("Is list 1 sorted? : %d\n", check_sorted(head1)); //it should display 0

    //----------------------------------------------------------------------------------------

    head2 = insert_list(head2,100);
	head2 = insert_list(head2,7);
	head2 = insert_list(head2,5);
	head2 = insert_list(head2,3);
    printf("\nContents List 2: ");
    simplePrint(head2);
    printf("\nIs list 2 sorted? : %d\n", check_sorted(head2)); //it should display 1

	return 0;
}

void simplePrint(node * root){
    node * t = root;
    while(t != NULL) {
        printf("%d ",t->info);
        t = t->next;
    }
}

node *  insert_list(node * root, int item){
    node * temp;
    temp = (node *) malloc(sizeof(node));
    temp->info = item;
    temp->next = root;
	return temp;
}

//----------------------------------------All questions are starting here ------------------------------------------

int countNodes (node* root){
    /*this function takes the head of a linked list and returns the number of nodes available in the linked list */
    if(root == NULL)
        return 0;

    node * t;
    int counter = 1;
    t = root;

    while(t->next != NULL)
    {
        t= t->next;
        counter++;
    }


    return counter; //this is a dummy return; REMOVE OR CHANGE WHEN YOU WRITE THIS FUNCTION
}

int check_sorted(node * root){
    /* this function takes the head of a linked list and checks whether the list is sorted in ASCENDING ORDER.
    If the list is sorted, the function will return 1, otherwise 0. */

    node * t;
    t = root;

    while(t->next != NULL)
    {
    if(t->info < t->next->info)
        t= t->next;
    else
        return 0;
    }

    return 1; //this is a dummy return; REMOVE OR CHANGE WHEN YOU WRITE THIS FUNCTION
}
