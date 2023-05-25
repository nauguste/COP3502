#include<stdio.h>
#include<stdlib.h>

 typedef struct nod{
	int info;
	struct nod *next;
}node;
node *root;
void SortInsert(int item)
{
    node *temp;
    node *t;
    temp= (node *) malloc(sizeof(node));
    temp->info=item;
    temp->next=NULL;
    if (root==NULL || root->info >=item)
    {
            temp->next = root;
            root = temp;
    }
      else
      {
            t = root;
            while (t->next != NULL && t->next->info <item)
                      t = t->next;
            temp->next = t->next; //if the loop breaks for t->next == NULL, then temp next is becoming NULL too. So, no problem
            t->next = temp;
       }

}

void main()
{
	root=NULL;
	node *t;
	int ch,ele;
	printf("\nThis is a program to creat a sorted link list \n");
	while(1){
		printf("\n\nIf u want to link an information press 1 for exit press 2 : ");
	    scanf("%d",&ch);
		if(ch==2)
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
			t=root;
			while(t!=NULL)
			{
				printf("%d ",t->info);
				t=t->next;
			}
		}
	}
}

