/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.36%)
 * Total Accepted:    438K
 * Total Submissions: 1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */

class Solution {
public:
    int fun(int i , int j, vector<int>& nums);
    int maxSubArray(vector<int>& nums) {
#if 0
        int max = INT_MIN;

        for (int i=0; i<nums.size(); i++)
        {
            for (int j=i; j<nums.size(); j++)
            {
                int sum = 0;
                for(int k=i; k<=j; k++)
                {
                    sum += nums[k];
                }

                //printf("%u %u %d \n", i, j,sum);
                if (max < sum)
                {
                    max = sum;
                }
            }
        }

#else
        int max = INT_MIN;
        int sum = 0;

        for (int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if (sum > max) // select A[i] or not
                max = sum;

            if (sum < 0)   // give up A[0]~~A[i] , next step start from A[i+1]
                sum = 0;
        }
#endif
        return max;


    }
};
