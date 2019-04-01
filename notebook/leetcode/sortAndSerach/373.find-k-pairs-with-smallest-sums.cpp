/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (33.27%)
 * Total Accepted:    62.2K
 * Total Submissions: 186K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 *
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 *
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output: [[1,2],[1,4],[1,6]]
 * Explanation: The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 *
 * Example 2:
 *
 *
 * Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output: [1,1],[1,1]
 * Explanation: The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 *
 * Example 3:
 *
 *
 * Input: nums1 = [1,2], nums2 = [3], k = 3
 * Output: [1,3],[2,3]
 * Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
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
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int idx1 = 0, idx2 = 0;
        vector<pair<int, int>> ans;

        if(nums1.size()==0 || nums2.size()==0 )
            return ans;

        for(int i=0; i<min((int)nums1.size(),k) ; i++)
        {
            for(int j=0; j<min((int)nums2.size(),k) ; j++)
            {
                pair<int,int> res(nums1[i],nums2[j]);
                ans.push_back(res);
            }
        }

        // lamba
        sort(ans.begin(), ans.end(),  [](pair<int, int> &a, pair<int, int> &b){return a.first + a.second < b.first + b.second;} );


        if (ans.size() > k) res.erase(ans.begin() + k, ans.end());
        return ans;
    }
};



#if 0
int main()
{
    Solution S;
    int k = 3;
    vector<int> A0 = {2,4,6};
    vector<int> A1 = {1,7,11};
    S.kSmallestPairs(A0,A1,k);

    return 0;
}
#endif


