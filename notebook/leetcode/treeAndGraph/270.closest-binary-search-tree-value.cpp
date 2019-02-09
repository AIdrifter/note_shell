/*
 * @lc app=leetcode id=270 lang=cpp
 *
 * [270] Closest Binary Search Tree Value
 *
 * https://leetcode.com/problems/closest-binary-search-tree-value/description/
 *
 * algorithms
 * Easy (42.83%)
 * Total Accepted:    76.5K
 * Total Submissions: 178.6K
 * Testcase Example:  '[4,2,5,1,3]\n3.714286'
 *
 * Given a non-empty binary search tree and a target value, find the value in
 * the BST that is closest to the target.
 * 
 * Note:
 * 
 * 
 * Given target value is a floating point.
 * You are guaranteed to have only one unique value in the BST that is closest
 * to the target.
 * 
 * 
 * Example:
 * 
 * 
 * Input: root = [4,2,5,1,3], target = 3.714286
 * 
 * ⁠   4
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \
 * 1   3
 * 
 * Output: 4
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    float diff = FLT_MAX;
    int node_value = 0;
    int closestValue(TreeNode* root, double target) {
        if(root==NULL)
            return node_value;


        if(fabs(root->val - target) <= diff){
            diff = fabs(root->val - target);
            node_value = root->val;
            // printf("diff %f  node %u \n",diff,node_value);
        }

        if(root->val > target)
            closestValue(root->left,  target);
        else
            closestValue(root->right, target);

        return node_value;

    }
};
