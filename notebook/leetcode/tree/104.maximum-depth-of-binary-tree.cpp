/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (58.72%)
 * Total Accepted:    441.2K
 * Total Submissions: 750.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * return its depth = 3.
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right
    t;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        TreeNode *cur = root;

        if (cur==NULL)
            return 0;

        int left  =  maxDepth(cur->left) + 1;
        int right =  maxDepth(cur->right) + 1;
        if (left > right)
            return left;
        else
            return right;
    }
};
