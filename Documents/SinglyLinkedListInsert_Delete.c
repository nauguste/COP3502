/* CS1
This code
*/

#include<stdio.h>
#include<stdlib.h>
 typedef struct node{
	int data;
	struct node *next;
}node;
node *root; //root globally declared

//this function takes an item and insert it in the linked list pointed by root.
void insert_front(int item)
{
	node *temp;
	//create a new node and fill-up the node
	temp= (node *) malloc(sizeof(node));
	temp->data=item;
	temp->next=NULL;
	if(root==NULL) //if there is no node in the linked list
        root=temp;
    else //there is an existing linked list, so put existing root after temp
    {
        temp->next = root; //put the existing root after temp
        root = temp; //make the temp as the root!
    }

}

//this function takes an item and insert it in the end of the linked list
void insert_end(int item)
{
	node *t;
	node *temp;
	//create a new node and fill-up the node
	temp= (node *) malloc(sizeof(node));
	temp->data=item;
	temp->next=NULL;
	if(root==NULL) //if there is no node in the linked list, make temp as the root
		root=temp;
	else //there is an existing linked list and we need to traverse to reach the end node
	{
		t=root; //t is being used to start traversing
        while(t->next!=NULL) //keep going till the end
            t=t->next;

        t->next=temp; //t is at the last node of the linked list, so add temp after t.
	}
}

/*this function deletes a given item from linked list.
it returns 1 if the item found and deleted.
If the item does not exist, it returns 0
*/
int DelList(int item)
{
	node *t;
	node *temp;
	if(root==NULL) //if there is no linked list, just return 0 that item does not exist
		return 0;
	if(root->data==item) //if root contains the item, remove the current root and change it to the next node
	{
		temp=root; //put existing root to temp so that we can free it. Otherwise, there will be memory leak
		root=root->next; //change the root by the next node of the current root.
		free(temp);
		return 1;
	}

	//the code will reach here if the item is not in the root. So, we need to traverse.
	t=root;

	/*keep going until we reach to the end or we find the item.
	note that we look ahead so that we will be one node before the node we will be deleting
	*/
	while(t->next!=NULL && t->next->data != item)
		t=t->next;
	if(t->next==NULL) //if the above loop breaks for this reason, it means the item does not exist
		return 0;
    /*if the code reach here, it indicates the loop exited as the item was found
    now, the node we want to delete is in t->next.*/

	temp=t->next; //we will delete t->next. So, putting it in temp
	t->next=t->next->next; //change the t->next to the the next of the node we will be deleting
	free(temp);
	return 1;
}
void main()
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
		 scanf("%d",&del.data);
		 v=DelList(del.data);
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
}
