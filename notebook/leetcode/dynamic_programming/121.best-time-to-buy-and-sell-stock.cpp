/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (45.86%)
 * Total Accepted:    421.6K
 * Total Submissions: 919.2K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 *
 * Note that you cannot sell a stock before you buy one.
 *
 * Example 1:
 *
 *
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 *
 *
 * Example 2:
 *
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 *
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
#if 0
        int max = 0;
        for (int i=0; i<prices.size(); i++)
            for (int j = i+1; j<prices.size(); j++)
            {
                int tmp = prices[j] - prices[i];
                if (max < tmp)
                    max = tmp;
            }
        return max;
#elif 0   //  Make sure min_element is the minimumal value in array before position i
        if(prices.size()==0)
            return 0;

        int max_val = 0, min_element = prices[0];
        for (int i=1; i<prices.size(); i++)
        {
            if(min_element > prices[i])
                min_element = prices[i];
            else
                max_val = max(prices[i] - min_element, max_val);
        }
        return max_val;
#else
        if(prices.size()==0)
            return 0;
        // dp[i] means the larget number from right to i
        vector<int> dp;
        int n = prices.size();
        dp.resize(n);

        dp[n-1] = 0;
        for (int i=n-2; i>=0 ;i--)
            dp[i] = max(dp[i+1], prices[i+1]);

        int max_diff = INT_MIN;
        for (int i=0; i < n;i++)
            max_diff = max(max_diff,dp[i]-prices[i]);

        return max_diff>0 ? max_diff:0;

#endif
    }
};
