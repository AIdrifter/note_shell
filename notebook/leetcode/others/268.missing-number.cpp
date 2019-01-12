/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (46.98%)
 * Total Accepted:    232.2K
 * Total Submissions: 494.1K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 *
 * Example 1:
 *
 *
 * Input: [3,0,1]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 *
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            if(nums.size()==0)
                return 0;

            vector<bool> check(nums.size(),false);
            //printf(" show %lu %lu \n",nums.size(),check.size());

            int n = 0;
            for(int i=0; i<nums.size(); i++)
                check[nums[i]] = true;

            int i;
            for(i=0; i<nums.size(); i++)
            {
                if(!check[i])
                    return i;
            }

            // [0,1,2] return 3
            return i;
        }
};
