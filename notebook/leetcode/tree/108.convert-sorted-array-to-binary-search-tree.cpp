/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (48.77%)
 * Total Accepted:    231.9K
 * Total Submissions: 475.3K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 * Example:
 *
 *
 * Given the sorted array: [-10,-3,0,5,9],
 *
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 *
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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

/*
 * [AVL Tree]
 * An empty tree is height-balanced. A non-empty binary tree T is balanced if:
 *    1) Left subtree of T is balanced
 *    2) Right subtree of T is balanced
 *    3) The difference between heights of left subtree and right subtree is not more than 1.
 */

class Solution {
public:
    TreeNode* buildTree(vector<int> &nums, int left, int right){
        if(left>right)
            return NULL;

        int mid = left + (right -left)/2;
        // new TreeNode : error: no matching function for call to 'TreeNode::TreeNode()'
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left  = buildTree(nums,left,mid-1);  // Don't forget to decrease 1
        cur->right = buildTree(nums,mid+1,right); // Don't foregt to increase 1
        return cur;
    }

    // If your use inoder traversal on BST
    // You will get ascending order array
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }


};
