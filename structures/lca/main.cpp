// A recursive C program to find LCA of two nodes n1 and n2.
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	node* left, *right;
	node (int val)
	{
        data = val;
        left = nullptr;
        right = nullptr;
	}

	~node()
	{
        if (left)
            delete left;
        if (right)
            delete right;
	}
};

/* Function to find LCA of n1 and n2. The function assumes that both
n1 and n2 are present in BST */
node *lca(struct node* root, int n1, int n2)
{
	if (root == NULL) return NULL;

	// If both n1 and n2 are smaller than root, then LCA lies in left
	if (root->data > n1 && root->data > n2)
		return lca(root->left, n1, n2);

	// If both n1 and n2 are greater than root, then LCA lies in right
	if (root->data < n1 && root->data < n2)
		return lca(root->right, n1, n2);

	return root;
}

/* Helper function that allocates a new node with the given data.
struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

 Driver program to test lca() */
int main()
{
	// Let us construct the BST shown in the above figure
	node *root	 = new node(20);
	root->left			 = new node(8);
	root->right			 = new node(22);
	root->left->left		 = new node(4);
	root->left->right	 = new node(12);
	root->left->right->left = new node(10);
	root->left->right->right = new node(14);

	int n1 = 10, n2 = 14;
	struct node *t = lca(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);

	n1 = 14, n2 = 8;
	t = lca(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);

	n1 = 10, n2 = 22;
	t = lca(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);

	return 0;
}
