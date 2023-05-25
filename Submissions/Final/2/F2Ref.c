#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 50

FILE *fout = NULL;

struct treenode
{
	struct treenode *lftChild;
	struct treenode *rtChild;
	char word[MAX];
}
*node;

//function declarations
void searchword(char word[], struct treenode **parent, struct treenode **pos);
void insertion(char word[]);
void noemptychld ( struct treenode *pos, struct treenode *parent);
void oneemptychld (struct treenode *pos, struct treenode *parent);
void twoemptychld (struct treenode *pos, struct treenode *parent);
int countbefore (struct treenode* root, char searchkey[]);
int del (char word[]);
int preorder (struct treenode *pointer);
void inorder (struct treenode *pointer);
void postorder (struct treenode *pointer);



int main()
{
	fout = fopen("out.txt","w");
	int numread, numsearch, numdelete, i;
	node = NULL;
	char word[MAX];

	struct treenode *pos;
	FILE *fin = fopen("in.txt","r");

	if (fin == NULL)
	{
		puts("Could not open the files. Please provide in.txt file.");
		return 0;
	}
	fscanf(fin, "%d %d %d", &numread, &numsearch, &numdelete);

	for (i = 1; i <= numread; i++)
	{
		fscanf(fin, "%s", word);
		insertion(word);
	}
	fprintf(fout, "Pre Order: ");
	fprintf(fout, "\nIn Order: ");
	fprintf(fout, "\nPost Order: ");
	fprintf(fout, "\nSearch Phase: ");

	for (i = 1; i <= numsearch; i++)
	{
		struct treenode *temp = node;

		fscanf(fin, "%s", word);
		int flg = 0;

		while (temp != NULL)
		{
			if (strcmp(word, temp -> word) == 0)
			{
				fprintf(fout, "\n%s: Found word.", word);
				fprintf(fout, "Items Before: %d", countbefore(node, word));

				flg = 1;
				break;
			}
			if (strcmp(word, temp -> word) <= 0)
			temp = temp -> lftChild;

			else

			temp = temp -> rtChild;
		}
		if (flg == 0)
		{
			fprintf(fout, "\n%s: Word Not Found.", word);
			fprintf(fout, "Items Before: 0");
		}
	}
		fprintf(fout, "\n\nDelete Phase:");
		for (i = 1; i <= numdelete; i++)
		{
			fscanf(fin, "%s", word);
			del(word);
		}
  fprintf(fout,"\n\nPre Order: ");
   preorder(node);

   fprintf(fout,"\nIn Order: ");
   inorder(node);

   fprintf(fout,"\nPost Order: ");
   postorder(node);

   fprintf(fout,"\n");

    fclose(fout);

   return 0;
}




void searchword(char word[], struct treenode **parent, struct treenode **pos)
{
	struct treenode *pointer, *temp;

	if (node == NULL)
	{
		*parent = NULL;
		*pos = NULL;

		return;
	}
	if (strcmp(word, node -> word) == 0)
	{
		*parent = NULL;
		*pos = node;

		return;
	}
	if (strcmp(word, node -> word) < 0)
	pointer = node -> lftChild;

	else
  pointer = node -> rtChild;
	temp = node;

	while (pointer != NULL)
	{
		if (strcmp(word, pointer -> word) == 0)
	{
		*parent = temp;
		*pos = pointer;

		return;
	}
	temp = pointer;

	if (strcmp(word, pointer -> word) <= 0)

	pointer = pointer -> lftChild;

	else

	pointer = pointer -> rtChild;
	}
	*parent = temp;
	*pos = NULL;
}





void insertion(char word[])
{
	struct treenode *parent, *temp, *pos;

	searchword(word, &parent, &pos);

	if (pos != NULL)
	{
		fprintf(fout,"This word is already in the tree.");
		return;
	}
temp = (struct treenode*) malloc(sizeof(struct treenode));

strcpy (temp -> word, word);
temp -> rtChild = NULL;
temp -> lftChild = NULL;

if (parent == NULL)
node = temp;

else

if (strcmp(word, parent -> word) <= 0)
parent -> lftChild = temp;

else
parent -> rtChild = temp;
}

int countbefore (struct treenode* root, char searchkey[])
{
	int c = 0;

	if (root != NULL)
	{
		if (strcmp(root -> word, searchkey) < 0)
		{
			c++;
		}
		c += countbefore(root -> lftChild, searchkey);
		c += countbefore(root -> rtChild, searchkey);
	}
	return c;
}

void noemptychld ( struct treenode *pos, struct treenode *parent)
{
	struct treenode *next, *prev, *pointer, *temp;

	temp = pos;
	pointer = pos -> rtChild;

	while (pointer -> lftChild != NULL)
	{
		temp = pointer;
		pointer = pointer -> lftChild;
	}
	next = pointer;
	prev = temp;

	if (next -> lftChild == NULL && next -> rtChild == NULL)
  	twoemptychld (prev , next);

	else
	oneemptychld (prev, next);

   	if (parent == NULL)
	  node = next;

	else

   	if (pos == parent -> lftChild)
  	parent -> lftChild = next;

		else

		parent -> rtChild = next;
		next -> lftChild = pos -> lftChild;
		next -> rtChild = pos -> rtChild;

}

void oneemptychld (struct treenode *pos, struct treenode *parent)
{
 struct treenode *chld;

 if (pos -> lftChild != NULL)
 chld = pos -> lftChild;

 else

  chld = pos -> rtChild;

  if (parent == NULL)
	node = chld;

}

void twoemptychld (struct treenode *pos, struct treenode *parent)
{
	if (parent == NULL)
	node = NULL;

	 else

	if (pos == parent -> lftChild)
	parent -> lftChild = NULL;

	 else

	parent -> rtChild = NULL;
}

int preorder (struct treenode *pointer)
{
	if (node == NULL)
	{
		fprintf(fout, "Binary Tree is empty.");

		return 0;
	}
	if (pointer != NULL)
	{
		fprintf(fout, "%s", pointer -> word);

		preorder (pointer -> lftChild);
		preorder (pointer -> rtChild);
	}
	return 1;
}

void inorder (struct treenode *pointer)
{
	if (node == NULL)
	{
		fprintf(fout, "Binary Tree is empty.");
		return;
	}
	if (pointer != NULL)
	{
		inorder (pointer -> lftChild);
		fprintf(fout, "%s", pointer -> word);
		inorder (pointer -> rtChild);
	}
}

void postorder (struct treenode *pointer)
{
	if (node == NULL)
	{
		fprintf(fout, "Binary Tree is empty.");
		return;
	}
	if (pointer != NULL)
	{
		postorder (pointer -> lftChild);
		postorder (pointer -> rtChild);
		fprintf(fout, "%s", pointer -> word);
	}
}

int del (char word[])
{
	struct treenode *parent, *pos;

	if (node == NULL)
	{
		fprintf(fout, "Binary Tree is empty.");
		return 0;
	}
	searchword (word, &parent, &pos);

	if (pos == NULL)
	{
		fprintf(fout, "Word not found in Binary Tree.");
		return 0;
	}
	if (pos -> lftChild == NULL && pos -> rtChild == NULL)
	twoemptychld (parent, pos);

	if (pos -> lftChild != NULL && pos -> rtChild == NULL)
	oneemptychld (parent, pos);

	if (pos -> lftChild == NULL && pos -> rtChild != NULL)
	oneemptychld (parent, pos);

	if (pos -> lftChild != NULL && pos -> rtChild != NULL)
	noemptychld (parent, pos);

	fprintf(fout, "\n%s: deleted",pos -> word);
	free (pos);
	return 1;
}

void alphabet (struct treenode *pointer)
{
	if (pointer != NULL)
	{
		alphabet (pointer -> lftChild);
		alphabet (pointer -> rtChild);
	}
}


