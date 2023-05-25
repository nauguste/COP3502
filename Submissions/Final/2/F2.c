// Naseem Auguste Final Assignment 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
    char name[100];
    struct tree * left;
    struct tree * right;
}tree;

void preorder(struct tree * current_ptr);
void inorder (struct tree * current_ptr);
void postorder(struct tree * current_ptr);
int search( struct tree * current_ptr, int val);
struct tree * create_node (tree * root, char * names);
struct tree * insert (struct tree * root, struct tree * element);
struct tree * root, * node;

int main()
{

    int N, S, D, i;
    char names[100];

    FILE * IFP;
    IFP = fopen("in.txt", "r");

    fscanf(IFP, "%d\n%d\n%d", &N, &S, &D);
    printf("N: %d\nS: %d\nD: %d\n\n", N, S, D);

    fscanf(IFP, "%s", &names[i]);
    root = create_node(node, names);
    //node = insert(root, node);
    //root = insertion(node->name);


    for(i = 0; i < N; i++)
    {
        //fscanf(IFP, "%s", &node->name);

    }

     for(i = 0; i < N; i++)
        printf("%s\n", root->name);


     // preorder(root);


    return 0;
}







/*
void preorder(struct tree * current_ptr)
{

    if (current_ptr != NULL)
    {
        printf("%s ", &current_ptr->name);
        preorder(current_ptr->left);
        preorder(current_ptr->right);
    }
}
void inorder(struct tree * current_ptr)
{

    if (current_ptr != NULL)
    {
        inorder(current_ptr->left);
        printf("%s ", current_ptr->name);
        inorder(current_ptr->right);
    }
}
void postorder(struct tree * current_ptr)
{
    if (current_ptr != NULL)
    {
        postorder(current_ptr->left);
        postorder(current_ptr->right);
        printf("%s ", current_ptr->name);
    }
}
*/













/*

int search(struct tree * current_ptr, int val)
{

  // Check if there are nodes in the tree.
    if (current_ptr != NULL)
    {

    // Found the value at the root.
    if (current_ptr->data == val)
      return 1;

    // Search to the left.
    if (val < current_ptr->data)
      return search(current_ptr->left, val);

    // Or...search to the right.
    else
      return search(current_ptr->right, val);

    }
    else
        return 0;
}

*/













tree * create_node(tree * root, char * names)
{

    int i;

    tree * temp;
    temp = (tree *)malloc(sizeof(tree));
    temp->left = NULL;
    temp->right = NULL;
    strcpy(temp->name, names);

    if(root == NULL)
    {
        root = temp;
        return root;
    }


    if(strcmp(temp->name, root->name) == -1)
    {
        if(root->left != NULL)
            root->left = create_node(root->left, names);
        else
            root->left = temp;
    }
    else //(strcmp(temp->name, root->name) == -1)
    {
        if(root->right != NULL)
            root->right = create_node(root->right, names);
        else
            root->right = temp;
    }

    return root;
}



/*
tree * create_node(int num)
{

    int i;
    tree * temp;
    temp = (tree *)malloc(sizeof(tree));
    strcopy(temp->name, name);
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

*/



















/*
struct tree * insert(struct tree * root, struct tree *element)
{

  // Inserting into an empty tree.
  if (root == NULL){
         printf("Element data %d -> address: %p\n", element->data, &(element->data));
    return element;
  }
  else {

    // element should be inserted to the right.
    if (element->data > root->data) {

      // There is a right subtree to insert the node.
      if (root->right != NULL)
        root->right = insert(root->right, element);

      // Place the node directly to the right of root.
      else
        root->right = element;
    }

    // element should be inserted to the left.
    else {

      // There is a left subtree to insert the node.
      if (root->left != NULL)
        root->left = insert(root->left, element);

      // Place the node directly to the left of root.
      else
        root->left = element;
    }

    // Return the root pointer of the updated tree.
    return root;
  }
}
*/





















tree * insert(tree * root,tree * element)
{

    struct tree * temp;
    temp = (struct tree *) malloc(sizeof(struct tree));
    //strcpy (temp -> name, name);
    temp -> left = NULL;
    temp -> right = NULL;

    // Inserting into an empty tree.
    if (root == NULL)
    {
        printf("Element data %d -> address: %p\n", element->name, &(element->name));
        return element;
    }
    else
    {

        // element should be inserted to the right.
        if (element->name > root->name)
            {

            // There is a right subtree to insert the node.
            if (root->right != NULL)
                root->right = insert(root->right, element);

            // Place the node directly to the right of root.
            else
                root->right = element;
            }

        // element should be inserted to the left.
        else
        {

        // There is a left subtree to insert the node.
            if (root->left != NULL)
                root->left = insert(root->left, element);

        // Place the node directly to the left of root.
            else
                root->left = element;
        }

    // Return the root pointer of the updated tree.
    return root;
  }
}



/*

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

*/


