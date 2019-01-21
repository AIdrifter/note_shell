/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (42.91%)
 * Total Accepted:    336.3K
 * Total Submissions: 783.7K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Note: Given n will be a positive integer.
 *
 * Example 1:
 *
 *
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 *
 */
class Solution {
public:
    int climbStairs(int n) {
#if 0
        int sum;
        map<int,int> hash_table;

        if(n==1)
            hash_table[1] = 1;
        if(n==2)
            hash_table[2] = 2;

        // n does not exist in hashtable
        if(hash_table.find(n) == hash_table.end() )
        {
            sum  =  climbStairs(n-1) +  climbStairs(n-2);
            hash_table[n] = sum;
        }

        return hash_table[n];
#elif 0
      if(n==1)
            return 1;
      if(n==2)
            return 2;

      return climbStairs(n-1) + climbStairs(n-2);
#else
    vector<int> C(n+1,0);
    C[1] = 1;
    C[2] = 2;
    for(int i=3; i <=n ; i++)
        C[i] = C[i-1] + C[i-2];

    return C[n];
#endif
    }
};
