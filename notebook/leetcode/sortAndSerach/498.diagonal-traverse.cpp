/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (45.08%)
 * Total Accepted:    38.3K
 * Total Submissions: 84.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 *
 *
 *
 * Example:
 *
 *
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 *
 * Output:  [1,2,4,7,5,3,6,8,9]
 *
 * Explanation:
 *
 *
 *
 *
 *
 * Note:
 *
 * The total number of elements of the given matrix will not exceed 10,000.
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


typedef struct pos
{
    int i;
    int j;
}pos_t;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        // collision happend : up, left , right , down,
        pos_t now = {0,0};

        // collision happend : up, left , right , down,
        pos_t pos[4] = {{0,1},{1,0},{1,0},{0,1}};

        // towards "up to right" "left to down"
        pos_t toward[2] = {{-1,1},{1,-1}};


        vector<int> ans;
        int step = 0;

        while(step < matrix.size() * matrix[0].size())
        {
            static int toward_flag = 0; // 0:(-1,1)   1:(1,-1)
            ans.push_back(matrix[now.i][now.j]);
            step++;

            pos_t pre;
            memcpy(&pre,&now,sizeof(pos_t));
            now.i += toward[toward_flag].i;
            now.j += toward[toward_flag].j;

            // upper collision
            if(now.i == -1)
            {
               now.i = pre.i;
               now.j = pre.j+1;
               (toward_flag)?toward_flag=0:toward_flag=1;
            }

            // right collision
            if(now.j == matrix[0].size())
            {
               now.i = pre.i + 1;
               now.j = pre.j;
               (toward_flag)?toward_flag=0:toward_flag=1;
            }

            // left collision
            if(now.i == -1)
            {
               now.i = pre.i+1;
               now.j = pre.j;
               (toward_flag)?toward_flag=0:toward_flag=1;
            }

            // down collision
            if(now.j == matrix.size())
            {
               now.i = pre.i;
               now.j = pre.j+1;
               (toward_flag)?toward_flag=0:toward_flag=1;
            }


        }
        return ans;

    }
};
