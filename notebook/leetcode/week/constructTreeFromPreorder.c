#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>


/* A O(n^2) program for construction of BST from preorder traversal */
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

// A utility function to create a node
struct node* newNode (int data)
{
	struct node* temp = (struct node *) malloc( sizeof(struct node) );

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}
#if SQUARE
// A recursive function to construct Full from pre[]. preIndex is used
// to keep track of index in pre[].
struct node* constructTreeUtil (int pre[], int* preIndex,
								int low, int high, int size)
{
	// Base case
	if (*preIndex >= size || low > high)
		return NULL;

	// The first node in preorder traversal is root. So take the node at
	// preIndex from pre[] and make it root, and increment preIndex
	struct node* root = newNode ( pre[*preIndex] );
	*preIndex = *preIndex + 1;

	// If the current subarry has only one element, no need to recur
	if (low == high)
		return root;

	// Search for the first element greater than root
	int i;
	for ( i = low; i <= high; ++i )
		if ( pre[ i ] > root->data )
			break;

	// Use the index of element found in preorder to divide preorder array in
	// two parts. Left subtree and right subtree
	root->left = constructTreeUtil ( pre, preIndex, *preIndex, i - 1, size );
	root->right = constructTreeUtil ( pre, preIndex, i, high, size );

	return root;
}

// The main function to construct BST from given preorder traversal.
// This function mainly uses constructTreeUtil()
struct node *constructTree (int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil (pre, &preIndex, 0, size - 1, size);
}
#elif LINEAR
/*
 *
 *  Method 2 ( O(n) time complexity )
 *  The idea used here is inspired from method 3 of this post. 
 *  The trick is to set a range {min .. max} for every node. 
 *  Initialize the range as {INT_MIN .. INT_MAX}. 
 *  The first node will definitely be in range, so create root node. 
 *  To construct the left subtree, set the range as {INT_MIN …root->data}. 
 *  If a values is in the range {INT_MIN .. root->data}, the values is part part of left subtree. 
 *  To construct the right subtree, set the range as {root->data..max .. INT_MAX}.
 *
 */

// A recursive function to construct BST from pre[]. preIndex is used
// to keep track of index in pre[].
struct node* constructTreeUtil( int pre[], int* preIndex, int key,
                                int min, int max, int size )
{
    // Base case
    if( *preIndex >= size )
        return NULL;

    struct node* root = NULL;

    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if( key > min && key < max )
    {
        // Allocate memory for root of this subtree and increment *preIndex
        root = newNode ( key );
        *preIndex = *preIndex + 1;

        if (*preIndex < size)
        {
            // Contruct the subtree under root
            // All nodes which are in range {min .. key} will go in left
            // subtree, and first such node will be root of left subtree.
            root->left = constructTreeUtil( pre, preIndex, pre[*preIndex],
                                        min, key, size );

            // All nodes which are in range {key..max} will go in right
            // subtree, and first such node will be root of right subtree.
            root->right = constructTreeUtil( pre, preIndex, pre[*preIndex],
                                         key, max, size );
        }
    }

    return root;
}

// The main function to construct BST from given preorder traversal.
// This function mainly uses constructTreeUtil()
struct node *constructTree (int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil ( pre, &preIndex, pre[0], INT_MIN, INT_MAX, size );
}
#endif

// A utility function to print inorder traversal of a Binary Tree
void printInorder (struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

// Driver program to test above functions
int main ()
{
	int pre[] = {10, 5, 1, 7, 40, 50};
	int size = sizeof( pre ) / sizeof( pre[0] );

	struct node *root = constructTree(pre, size);

	printf("Inorder traversal of the constructed tree: \n");
	printInorder(root);

	return 0;
}

