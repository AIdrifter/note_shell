#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <climits>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    public:
        int i = 0;
        TreeNode* bstFromPreorder(vector<int>& A, int min = INT_MIN ,int max = INT_MAX) {
            if (i == A.size() || !(A[i] < max && A[i] > min )) return NULL;
            TreeNode* root = new TreeNode(A[i++]);
            root->left  = bstFromPreorder(A, min , root->val);
            root->right = bstFromPreorder(A, root->val, max );
            return root;
        }
};

// A utility function to print inorder traversal of a Binary Tree
void printInorder (struct TreeNode* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->val);
	printInorder(node->right);
}



#if 1
int main()
{
    Solution S;
    vector<int> Pre = {10, 5, 1, 7, 40, 50};
    TreeNode *root = S.bstFromPreorder(Pre);
	printInorder(root);
    return 0;
}
#endif
