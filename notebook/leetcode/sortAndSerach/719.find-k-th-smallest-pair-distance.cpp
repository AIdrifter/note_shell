/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 *
 * https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
 *
 * algorithms
 * Hard (28.65%)
 * Total Accepted:    17.2K
 * Total Submissions: 60K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * Given an integer array, return the k-th smallest distance among all the
 * pairs. The distance of a pair (A, B) is defined as the absolute difference
 * between A and B.
 *
 * Example 1:
 *
 * Input:
 * nums = [1,3,1]
 * k = 1
 * Output: 0
 * Explanation:
 * Here are all the pairs:
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * Then the 1st smallest distance pair is (1,1), and its distance is 0.
 *
 *
 *
 * Note:
 *
 * 2 .
 * 0 .
 * 1 .
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
    int smallestDistancePair(vector<int>& nums, int k) {
        // 1.sort ascending order array
        sort(nums.begin(),nums.end());
        // return the last element
        const int N = nums.back();
        vector<int> count(N + 1, 0);

        // 2.find the k smallest distance with combinational
        for(int i = 0; i<nums.size() ; i++ )
        {
            for(int j = i+1; j<nums.size() ; j++ )
            {
                ++count[nums[j]-nums[i]];
            }
        }

        // 3. sort distance again => time limit
        //    use bucket sort can save next sorting time.
        //    sort(smallest.begin(),smallest.end());
        for(int i=0; i<=N; i++)
        {
            k -= count[i];
            // () is not k - 1
            if(k <= 0 ) return i;
        }
        return 0;
    }
};
