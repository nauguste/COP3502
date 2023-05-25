//COP3502
//The following code demonstrate the operations of sorted doubly linked list
#include<stdio.h>
#include<stdlib.h>

 typedef struct nod{
	int info;
	struct nod *next, *prev;
}node;
node *root;

void SortInsert(int item)
{
    node *temp;
    node *t;
    temp = (node *) malloc(sizeof(node));
    temp->info=item;
    temp->next=NULL;
    temp->prev=NULL;
    if (root==NULL || root->info >=item)
    {
            temp->next = root;
            temp->prev=NULL;
            root=temp;
            if(temp->next != NULL) //if there was an existing root, it would be true
                temp->next->prev=temp;
     }
     else
     {
            t = root;
            while (t->next != NULL && t->next->info <item)
                      t = t->next;
            temp->next = t->next;
            temp->prev = t;
            t->next = temp;

            if (temp->next != NULL)
                temp->next->prev = temp;
       }

}

int searchList(int item)
{
    node *t;
    t =  root;
    while(t!=NULL && t->info !=item)
        t= t->next;
    if (t!=NULL) //it means the item was found
        return 1;
    else
        return 0;
}

int printList()
{
    node * t;
    t=root;
    while(t!=NULL)
    {

        printf("%d  ", t->info);
        t= t->next;
    }
    printf("\n");
}

int DelList(int item)
{
    node *t,*temp;
    if (root == NULL)
        return 0;
    if (root -> info == item)
    {
        temp = root;
        root = root->next;
        if(root!=NULL)
            root->prev = NULL;
        free (temp);
        return 1;
    }
    else
    {
        t=root;
        while(t->next!=NULL && t->next->info!=item)
        {
            t=t->next;
        }
        if(t->next ==NULL)
            return 0;
        else
        {
            temp = t->next;
            t->next = t->next->next;
            if (t->next != NULL)
                t->next->prev=t;
        }


    }
}

void main()
{
	root=NULL;
	node *t;
	int ch,ele, status;
	printf("\nThis is a program to creat a sorted link list \n");
	while(1){
		printf("\n\nPress 1 for insert, 2 for delete, 3 for search and 9 for exit: ");
	    scanf("%d",&ch);
		if(ch==9)
		{
			printf("\n<<<<<<<GOOD BYE>>>>>>\n\n\n");
			break;
		}
		if(ch==1)
		{
			printf("\nEnter information(an integer): ");
			scanf("%d",&ele);
			SortInsert(ele);
			printf("\nPrinting Sorted link list.......");
			printList();
		}
		if(ch==2)
		{
			printf("\nEnter an integer to delete: ");
			scanf("%d",&ele);
			status = DelList(ele);
			if (status == 1)
            {
                printf("Item deleted");
                printf("\nPrinting Sorted link list.......");
                printList();
            }
            else
            {
                printf("Item NOT FOUND");
                printf("\nPrinting Sorted link list.......");
                printList();

            }
		}
		if(ch==3)
		{
			printf("\nEnter an integer to search: ");
			scanf("%d",&ele);
			status = searchList(ele);
			if (status == 1)
            {
                printf("Item FOUND");

            }
            else
            {
                printf("Item NOT FOUND");

            }
		}
	}
}

