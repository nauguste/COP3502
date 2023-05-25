// Naseem Auguste Final Lab Exam

#include <stdio.h>
#include <stdlib.h>


typedef struct tree
{
  int count;
  int data;
  struct tree *left;
  struct tree *right;

}tree;

struct tree * create_node(int money, int people);
struct tree * insert (tree * root, tree * element);
void inorder (FILE * outfile, struct tree * current_ptr);
tree * maxVal(tree * root);
tree * maxValtwo(tree * root);
int children(tree * root);
int income(tree * root);



int main()
{
    FILE * infile;
    FILE * outfile;

    tree * root = NULL;
    tree * node;

    int money, people;
    int n, i, sum, max, max2;

    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    fscanf(infile, "%d", &n);

    for(i = 0; i < n; i++)
    {
        fscanf(infile, "%d %d", &money, &people);
        node = create_node(money, people);
        root = insert(root, node);
    }

    printf("Inorder: ");
    fprintf(outfile, "Inorder: ");
    inorder(outfile, root);

    max = maxVal(root);
    max2 = maxValtwo(root);
    printf("\nHighest income: %d\t# of People with Highest Income: %d", max, max2);
    fprintf(outfile,"\nHighest income: %d\t# of People with Highest Income: %d", max, max2);

    int kids = children(root);
    printf("\nAmount of single children in tree: %d", kids);
    fprintf(outfile, "\nAmount of single children in tree: %d", kids);

    sum = income(root);
    printf("\nIncome of the area: %d\n", sum);
    fprintf(outfile,"\nIncome of the area: %d\n", sum);

    fclose(infile);
    fclose(outfile);

return 0;
}

struct tree * insert(struct tree * root, struct tree * element)
{
    if (root == NULL)
    {
        return element;
    }
    else
    {
        if (element->data > root->data)
        {
            if (root->right != NULL)
                root->right = insert(root->right, element);
            else
                root->right = element;
        }
        else
        {
            if (root->left != NULL)
                root->left = insert(root->left, element);
            else
                root->left = element;
        }

    return root;
    }
}

void inorder(FILE * outfile, struct tree * current_ptr)
{
    if (current_ptr != NULL)
    {
        inorder(outfile, current_ptr->left);
        printf("(%d, %d) ", current_ptr->data, current_ptr->count);
        fprintf(outfile,"(%d, %d) ", current_ptr->data, current_ptr->count);
        inorder(outfile, current_ptr->right);
    }
}

struct tree * create_node(int money, int people)
{

    tree * temp = malloc(sizeof(tree));
    temp->count = people;
    temp->data = money;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

tree * maxVal(tree * root)
{

  if (root->right == NULL)
    return root->data;
  else
    return maxVal(root->right);
}

tree * maxValtwo(tree * root)
{

  if (root->right == NULL)
    return root->count;
  else
    return maxValtwo(root->right);
}

int children(tree * root)
{
	int child = 0;

	if (root != NULL)
	{
		if (root->left == NULL && root->right != NULL)
		{
			child++;
		}
		if (root->left != NULL && root->right == NULL)
		{
			child++;
		}
		child += children(root->left);
		child += children(root->right);
	}
	return child;
}

int income(tree * root)
{

  if (root != NULL)
    return root->data *root->count + income(root->left) + income(root->right);
  else
    return 0;

}
