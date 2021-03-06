/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (53.30%)
 * Total Accepted:    404.6K
 * Total Submissions: 759.2K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int idx = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=0)
            {
                res[idx++] = nums[i];
            }
        }
        memcpy(&nums[0], &res[0], sizeof(int)*nums.size());
    }
};
