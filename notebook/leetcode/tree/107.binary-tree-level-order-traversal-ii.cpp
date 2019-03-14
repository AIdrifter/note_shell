/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (45.79%)
 * Total Accepted:    211.8K
 * Total Submissions: 462.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 *
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 *
 *
 */


#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#define PB push_back
#define ALL(v) v.begin(),v.end()
#define RALL(v) v.rbegin(),v.rend()
#define REP_0(i,m) for(int i=0;i<(int)(m);i++)
#define FOR_IT(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define MEMSET(a,b) memset(a,b,sizeof(a))
using namespace std;

class Solution {
public:

    // C++ code
    void Levelorder(TreeNode *root, vector<vector<int>> &ans ){


        vector<int> cur_vec;
        std::queue<TreeNode*> q;

        q.push(root);                           // 把root作為level-order traversal之起點 推進queue中

        // Trick push NULL to maintain depth information
        q.push(NULL);

        while (!q.empty()){                     // 若queue不是空的, 表示還有node沒有visiting

            TreeNode *current = q.front();      // 取出先進入queue的node
            q.pop();
            //std::cout << current->val << " ";   // 進行visiting

            if (current==NULL)
            {
                  // save each level node information
                  ans.push_back(cur_vec);
                  cur_vec.resize(0);

                  // Keep depth information
                  if (q.size() > 0) q.push(NULL);
            }
            else
            {
                cur_vec.push_back(current->val);
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
            // error: could not convert '0' from 'long int' to 'std::vector<std::vector<int> >'
            if(!root)
                 return {};

            vector<vector<int>>  ans;
            vector<vector<int>>  reverse_ans;
            Levelorder(root, ans);


            for(int i =  ans.size()-1; i>=0; i--)
            {
                reverse_ans.push_back(ans[i]);
            }

            return reverse_ans;
    }

};

