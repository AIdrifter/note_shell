/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (46.55%)
 * Total Accepted:    325.8K
 * Total Submissions: 699.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 *
 * return its level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
    vector<vector<int>> levelOrder(TreeNode* root) {

        // error: could not convert '0' from 'long int' to 'std::vector<std::vector<int> >'
        if(!root)
            return {};

        // Queue : FIFO => First In First Out
        std::queue<TreeNode*> q;
        vector<vector<int> > result;
        vector<int> cur_vec;

        q.push(root);

        // Trick push NULL to maintain depth information
        q.push(NULL);

        while (!q.empty()){
            TreeNode *current = q.front();
            q.pop();

            if (current==NULL)
            {
                // save each level node information
                result.push_back(cur_vec);
                cur_vec.resize(0);

                // Keep depth information
                if (q.size() > 0) q.push(NULL);
            }
            else
            {
                cur_vec.push_back(current->val);
                if (current->left != NULL)  q.push(current->left);
                if (current->right != NULL) q.push(current->right);
            }
        }

        return result;
    }
};
