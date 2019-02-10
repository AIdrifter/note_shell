/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (33.21%)
 * Total Accepted:    49.5K
 * Total Submissions: 148.9K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 * 
 * Note: The length of path between two nodes is represented by the number of
 * edges between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * 
 * 
 * Output:
 * 
 * 2
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * 
 * 
 * Output:
 * 
 * 2
 * 
 * 
 * 
 * Note:
 * The given binary tree has not more than 10000 nodes.  The height of the tree
 * is not more than 1000.
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
    int longestPath(TreeNode* root, int *cross_val){
        if(!root) return 0;
        int left  = longestPath(root->left,cross_val);
        int right = longestPath(root->right,cross_val);
        left  = (root->left  && root->left->val  == root->val) ? left  + 1 : 0;
        right = (root->right && root->right->val == root->val) ? right + 1 : 0;

        /*
         * [Trick]
         *  If left's val is not equavalent to right's val,
         *  => left=0,right=0
         *  => cross_val will not changed.
         */

        *cross_val = max(*cross_val, left + right); // only edge...
        return max(left,right);
    }


    int longestUnivaluePath(TreeNode* root) {
        int ans = 0; // have to initialize, to get correct 'ans' . 
        longestPath(root,&ans);
        return ans;
    }
};
