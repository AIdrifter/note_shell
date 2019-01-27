/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (58.46%)
 * Total Accepted:    400.4K
 * Total Submissions: 684.9K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * Example 1:
 *
 *
 * Input: [2,2,1]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: [4,1,2,1,2]
 * Output: 4
 *
 *
 */


#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map <int,int> hash;
        //map <int,int> iterator iter;;
        int i;
        for(i=0; i<nums.size(); i++)
        {
        //    if(hash.find(i) == hash.end())
            {
                hash[nums[i]]++;
            }
        }

        for(i=0; i<nums.size(); i++)
        {
            if(hash[nums[i]]==1)
                return nums[i];
        }
        return nums[i];
    }
};


#if 0
int main()
{
    Solution s;
    vector <int> A = {4,1,2,1,2};
    s.singleNumber(A);
    return 0;
}
#endif

