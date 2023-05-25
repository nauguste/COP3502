// Naseem Auguste Final Assignment 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
    char * names;
    struct tree * left;
    struct tree * right;
}tree;

tree * makeString(char * temp);
tree * insert(tree * root, tree * node);
void preorder(FILE * OFP, tree * root);
void inorder(FILE*OFP, tree * root);
void postorder(FILE*OFP, tree * root);
int totalCharacters(tree * root);
int * isBalanced(tree * root);
int max(int a, int b);
int height(tree * root);
int find(tree * root, char * search);
int countbefore(tree * root, char * search);
tree * delete(tree * root, char * remove);
int hasOnlyRightChild(tree * node);
int hasOnlyLeftChild(tree * node);
int isLeaf(tree * node);
tree * parent(tree * root, tree * node);
tree * findNode(tree * root, char * remove);
tree * minVal(struct tree * root);
tree * maxVal(struct tree * root);


int main()
{

    int N, S, D, i;
    tree * root = NULL;
    char * temp = malloc(100*sizeof(char));
    char * search = malloc(100*sizeof(char));
    char * remove = malloc(100*sizeof(char));
    tree * node;

    FILE * IFP;
    IFP = fopen("in.txt", "r");
    FILE * OFP = fopen("out.txt", "w");


    fscanf(IFP, "%d\n%d\n%d", &N, &S, &D);

    for(i = 0; i < N; i++)
    {
        fscanf(IFP, "%s", temp);
        node = makeString(temp);
        root = insert(root, node);
    }

    printf("==================================================================\n");
    printf("Insert Phase\n==================================================================\n\n");

    fprintf(OFP,"==================================================================\n");
    fprintf(OFP,"Insert Phase\n==================================================================\n\n");

    printf("Preorder: ");
    fprintf(OFP,"Preorder: ");
    preorder(OFP,root);

    printf("\nInorder: ");
    fprintf(OFP,"\nInorder: ");
    inorder(OFP,root);

    printf("\nPostorder: ");
    fprintf(OFP,"\nPostorder: ");
    postorder(OFP,root);

    printf("\n");
    fprintf(OFP,"\n");

    int total = totalCharacters(root);
    printf("\nTotal Characters: %d", total);
    fprintf(OFP,"\nTotal Characters: %d", total);

    printf("\n");
    fprintf(OFP,"\n");

    int * balance = isBalanced(root);
    printf("\nLeft Tree Height: %d\nRight Tree Height: %d\n", balance[1],balance[2]);
    fprintf(OFP,"\nLeft Tree Height: %d\nRight Tree Height: %d\n", balance[1],balance[2]);
    if(balance[0] == 0)
    {
        printf("This tree is not balanced.\n");
        fprintf(OFP,"This tree is not balanced.\n");
    }
    else
        {
        printf("This tree is balanced.\n");
        fprintf(OFP,"This tree is balanced.\n");
      }

    printf(" \n==================================================================\n");
    printf("Search Phase\n==================================================================\n\n");
    fprintf(OFP,"==================================================================\n");
    fprintf(OFP,"Search Phase\n==================================================================\n\n");

    for(i = 0; i < S; i++)
    {
        fscanf(IFP, "%s", search);
        int HoM = find(root, search);
        printf("%s, ", search);
        fprintf(OFP,"%s, ", search);
        if (HoM == 1)
        {
            printf("Found. ");
            fprintf(OFP,"Found. ");
        }
        else
        {
            printf("Found. ");
            fprintf(OFP,"Found. ");
        }
        int items = countbefore(root,search);

        if(HoM != 1)
            items = 0;

        printf("Items found: %d", items);
        fprintf(OFP,"Items found: %d", items);

        printf("\n");
        fprintf(OFP,"\n");
    }
    printf("\n==================================================================\n");
    printf("Delete Phase\n==================================================================\n\n");

    fprintf(OFP,"==================================================================\n");
    fprintf(OFP,"Delete Phase\n==================================================================\n\n");


    for(i = 0; i < D; i++)
    {
        fscanf(IFP, "%s", remove);
        delete(root, remove);
        printf("Deleted: %s \n", remove);
        fprintf(OFP,"deleted: %s \n", remove);

    }
    printf("\nInorder: ");
    fprintf(OFP,"\nInorder: ");
    inorder(OFP,root);
    total = totalCharacters(root);
    printf("\nTotal Characters: %d\n", total);
    fprintf(OFP,"\nTotal Characters: %d\n", total);
    printf("\n==================================================================\n");
    fprintf(OFP,"==================================================================\n");

    return 0;
}


tree * makeString(char * temp)
{
        tree * stringNode = malloc(sizeof(tree));
        stringNode->names = malloc(strlen(temp)*sizeof(char));
        stringNode->left = NULL;
        stringNode->right = NULL;
        strcpy(stringNode->names, temp);

        return stringNode;
}

tree * insert(tree * root, tree * node)
{
    if (root == NULL)
        return node;
    else
    {

        if(strcmp(root->names, node->names) < 0)
        {
            if(root->right != NULL)
                root->right = insert(root->right, node);
            else
                root->right = node;
        }
        else
        {
            if(root->left != NULL)
                root->left = insert(root->left, node);
            else
                root->left = node;
        }
        return root;
    }
}


void preorder(FILE*OFP, tree * root)
{
    	if (root == NULL)
        {
            //printf("Binary Tree is empty.");
            return;
        }
        else
        {
            printf("%s ", root->names);
            fprintf(OFP,"%s ", root->names);
            preorder (OFP, root->left);
            preorder (OFP, root->right);
        }
}
void inorder(FILE*OFP, tree * root)
{
    	if (root == NULL)
        {
            return;
        }
        else
        {

            inorder (OFP,root->left);
            printf("%s ", root->names);
            fprintf(OFP,"%s ", root->names);
            inorder (OFP,root->right);
        }
}
void postorder(FILE*OFP, tree * root)
{
    	if (root == NULL)
        {
            return;
        }
        else
        {
            postorder (OFP,root->left);
            postorder (OFP,root->right);
            fprintf(OFP,"%s ", root->names);
            printf("%s ", root->names);
        }
}










int totalCharacters(tree * root)
{
    int total = 0;

  if (root != NULL)
    return total = strlen(root->names) + totalCharacters(root->left) + totalCharacters(root->right);
  else
    return 0;
    printf("\nTotal Characters: %d", total);
}







int * isBalanced(tree * root)
{
    int lh;
    int rh;
    int * temp = (int *)malloc(sizeof(int) * 3);


    if (root == NULL)
        return temp;

    lh = height(root->left);
    rh = height(root->right);

	*(temp + 1) = lh-1;
	*(temp + 2) = rh-1;

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
        *temp = 1;
        return temp;
    }
     else
    {
        *temp = 0;
        return temp;
    }

}

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int height(tree * root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}











int find(tree * root, char * search)
{

    if (root != NULL)
    {

        if ((strcmp(root->names, search))== 0)
            return 1;

        if ((strcmp(root->names, search)) < 0)
            return find(root->right, search);
        else
            return find(root->left, search);

    }
    else
        return 0;

}

int countbefore(tree * root, char * search)
{
	int count = 0;

	if (root != NULL)
	{
		if (strcmp(root->names, search) < 0)
		{
			count++;
		}
		count += countbefore(root->left, search);
		count += countbefore(root->right, search);
	}
	return count;
}







tree * delete(tree * root, char * remove)
{
    tree * delnode, * new_del_node, * save_node, * par;
    char save[25];

    delnode = findNode(root, remove);

    par = parent(root, delnode);

    if (isLeaf(delnode))
    {

        if (par == NULL)
        {
            free(root);
            return NULL;
        }

        if (strcmp(remove, root->names) < 0)
        {
            free(par->left);
            par->left = NULL;
        }
        else
        {
            free(par->right);
            par->right = NULL;
        }
    return root;
  }

    if (hasOnlyLeftChild(delnode))
    {
        if (par == NULL)
        {
            save_node = delnode->left;
            free(delnode);
            return save_node;
        }

        if (strcmp(remove, root->names) < 0)
        {
            save_node = par->left;
            par->left = par->left->left;
            free(save_node);
        }
        else
        {
            save_node = par->right;
            par->right = par->right->left;
            free(save_node);
        }
    return root;
    }

    if (hasOnlyRightChild(delnode))
    {
        if (par == NULL)
        {
            save_node = delnode->right;
            free(delnode);
            return save_node;
        }

        if (strcmp(remove, root->names) < 0)
        {
            save_node = par->left;
            par->left = par->left->right;
            free(save_node);
        }
        else
        {
            save_node = par->right;
            par->right = par->right->right;
            free(save_node);
        }
    return root;
    }

  new_del_node = minVal(delnode->right);

  strcpy(save, new_del_node->names);

  delete(root, save);

  strcpy(delnode->names, save);

 return root;
}








int hasOnlyRightChild(tree * node)
{
  return (node->left== NULL && node->right != NULL);
}

int hasOnlyLeftChild(tree * node)
{
  return (node->left!= NULL && node->right == NULL);
}

int isLeaf(tree * node)
{
  return (node->left == NULL && node->right == NULL);
}






tree * parent(tree * root, tree * node)
{

  if (root == NULL || root == node)
    return NULL;

  if (root->left == node || root->right == node)
    return root;

  if ((strcmp(node->names, root->names)) < 0)
    return parent(root->left, node);

  else if ((strcmp(node->names, root->names)) > 0)
    return parent(root->right, node);

  return NULL;

}

tree * findNode(tree * root, char * remove)
{

  if (root != NULL)
    {

    if ((strcmp(root->names, remove))== 0)
      return root;

    if ((strcmp(root->names, remove)) > 0)
      return findNode(root->left, remove);
    else
      return findNode(root->right, remove);

  }
  else
    return NULL;
}


tree * minVal(tree * root)
{

  if (root->left == NULL)
    return root;

  else
    return minVal(root->left);
}


tree * maxVal(tree * root)
{

  if (root->right == NULL)
    return root;

  else
    return maxVal(root->right);
}
