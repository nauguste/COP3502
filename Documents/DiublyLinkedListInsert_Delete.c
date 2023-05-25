/* CS1 */

#include<stdio.h>
#include<stdlib.h>
typedef struct nod
{
     int data;
    struct nod *prev, *next;
} node;

node *root;

void insert_front(int item)
{
	node *t;
	node *temp;
	temp= (node *) malloc(sizeof(node));
	temp->data=item;
	temp->prev = NULL;
	temp->next=root;

	if(root!=NULL)
        root->prev=temp;

    root = temp;
}


void insert_end(int item)
{
	node *t;
	node *temp;
	temp=(node *) malloc( sizeof(node));
	temp->data=item;
	temp->next=NULL;
	if(root==NULL)
	{
	     temp->prev = NULL;
	     root=temp;
    }
	else
	{
 	      t=root;
	      while(t->next!=NULL)
            t=t->next;

	      t->next=temp;
          temp->prev = t;
	}

}

int DelListDoubly(int item)
{
	node *t;
	node *temp;
	if(root==NULL)
		return 0;
	if(root->data==item)
	{
		temp=root;
		root=root->next;
		if (root != NULL) //new condition for doubly
            root -> prev = NULL;
		free(temp);
		return 1;
	}
	t=root;
	while(t->next!=NULL && t->next->data != item)
		t=t->next;
	if(t->next==NULL)
		return 0;
	temp=t->next;
	t->next=t->next->next;
    if (t->next)               //new condition for doubly
       t->next->prev = t;

	free(temp);
	return 1;
}


int main()
{
	root=NULL;
	node *t,del;
	int ch,ele,v;
	while(1)
	{
		printf("\nMenu: 1. insert at front, 2. insert at end, 3. Delete 4. exit: ");
	    scanf("%d",&ch);
		if(ch==4)
		{
			printf("\nGOOD BYE>>>>\n");
			break;
		}
		if(ch==1)
		{
			printf("\nEnter information(an integer): ");
			scanf("%d",&ele);
			insert_front(ele);
			printf("\nPrinting ur link list.......");
			t=root;
			while(t!=NULL)
			{
				printf("%d ",t->data);
				t=t->next;
			}
		}
		if(ch==2)
		{
			printf("\nEnter information(an integer): ");
			scanf("%d",&ele);
			insert_end(ele);
			printf("\nPrinting ur link list.......");
			t=root;
			while(t!=NULL)
			{
				printf("%d ",t->data);
				t=t->next;
			}
		}
	   if(ch==3)
	   {
		 printf("\nEnter info which u want to DELETE: ");
		 scanf("%d",&ele);
		 v=DelListDoubly(ele);
		 if(v==1)
		 {
			printf("\nDELETing....");
			t=root;
			while(t!=NULL)
			{
				printf("%d ",t->data);
				t=t->next;
			}
		 }
		  else if(v==0)
			printf("\nUr info does not exist in the list");


	   }
	}
	return 0;
}
