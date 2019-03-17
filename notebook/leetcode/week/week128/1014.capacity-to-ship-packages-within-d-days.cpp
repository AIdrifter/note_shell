/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Capacity To Ship Packages Within D Days
 *
 * https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
 *
 * algorithms
 * Medium (46.34%)
 * Total Accepted:    2K
 * Total Submissions: 4.4K
 * Testcase Example:  '[1,2,3,4,5,6,7,8,9,10]\n5'
 *
 * A conveyor belt has packages that must be shipped from one port to another
 * within D days.
 *
 * The i-th package on the conveyor belt has a weight of weights[i].  Each day,
 * we load the ship with packages on the conveyor belt (in the order given by
 * weights). We may not load more weight than the maximum weight capacity of
 * the ship.
 *
 * Return the least weight capacity of the ship that will result in all the
 * packages on the conveyor belt being shipped within D days.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
 * Output: 15
 * Explanation:
 * A ship capacity of 15 is the minimum to ship all the packages in 5 days like
 * this:
 * 1st day: 1, 2, 3, 4, 5
 * 2nd day: 6, 7
 * 3rd day: 8
 * 4th day: 9
 * 5th day: 10
 *
 * Note that the cargo must be shipped in the order given, so using a ship of
 * capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6,
 * 7), (8), (9), (10) is not allowed.
 *
 *
 * Example 2:
 *
 *
 * Input: weights = [3,2,2,4,1,4], D = 3
 * Output: 6
 * Explanation:
 * A ship capacity of 6 is the minimum to ship all the packages in 3 days like
 * this:
 * 1st day: 3, 2
 * 2nd day: 2, 4
 * 3rd day: 1, 4
 *
 *
 * Example 3:
 *
 *
 * Input: weights = [1,2,3,1,1], D = 4
 * Output: 3
 * Explanation:
 * 1st day: 1
 * 2nd day: 2
 * 3rd day: 3
 * 4th day: 1, 1
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= D <= weights.length <= 50000
 * 1 <= weights[i] <= 500
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
#include <numeric>
#define PB push_back
#define ALL(v) v.begin(),v.end()
#define RALL(v) v.rbegin(),v.rend()
#define REP_0(i,m) for(int i=0;i<(int)(m);i++)
#define FOR_IT(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define MEMSET(a,b) memset(a,b,sizeof(a))

using namespace std;

/*
 * 410.Split Array Largest Sum
 * https://blog.csdn.net/xx_123_1_rj/article/details/80470774
 * 給n個正整數a1, a2, a3, ... ... an，將n個數順序排成一列後分割成m段，
 * 每一段的分數被記為這段內所有數的和，該次分割的分數則被記為m段分數的最大值。問所有的分割方案中分割分數的最小值是多少？
 */

/*
 * Intuition
 * The smallest capacity (l) we can use is the weight of the largest package.
 * The largest capacity (r) is the sum of weights of all packages.
 * Our result is within this interval.
 *
 * [Linearithmic Solution]
 * We use binary search to find the minimum capacity. For each capacity we analyze, we count the number of days required to ship all packages.
 *
 * We decrease the capacity if it takes less days than D,
 * and increase otherwise. Note that, when the number of days equals D,
 * this algorithm keeps decreasing the capacity while it can, therefore finding the smallest capacity required.
 *
 *        weights = [1,4,2,3,5], D = 3
 *         l                                   r
 *         5  6  7  8  9  10  11  12  13  14  15
 */
class Solution {
    public:

        int countDays(vector<int>& weights, int tot_cap, int cur_cap = 0, int res = 1) {
            for (auto w : weights) {
                cur_cap += w;
                if (cur_cap > tot_cap) ++res, cur_cap = w;
            }
            return res;
        }
        int shipWithinDays(vector<int>& ws, int D) {
            // Returns an iterator pointing to the element with the largest value in the range [first,last).
            // 最優解一定不小於最大元素
            auto l = *max_element(begin(ws), end(ws));
            // sum the elements in vec starting the summation with the value 0(3rd paramter)
            // 最優解一定不大於sum(nums)，這個很好理解，因為無論它如何分割，子段的最大值不會超過這個序列的總和。
            auto r = accumulate(begin(ws), end(ws), 0);
            while (l < r) {
                auto m = (l + r) / 2;
                auto d = countDays(ws, m);
                if (d <= D) r = m;
                else l = m + 1;
            }
            return l;
        }
};
