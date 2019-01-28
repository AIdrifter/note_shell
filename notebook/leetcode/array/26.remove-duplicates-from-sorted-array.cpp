/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (39.18%)
 * Total Accepted:    501.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being modified to 0, 1, 2, 3, and 4 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int hook=1;

        if(nums.size() == 0)
            return 0;

        for(int i=1; i<nums.size() ; i++)
        {
            printf("hook[%u]=%u I[%u]=%u \n",hook,nums[hook],i,nums[i]);
            if(nums[i]!=nums[hook])
            {
                nums[hook]   = nums[i];
                nums[hook+1] = nums[i];
                hook++;
                printf("[Move hook] hook[%u]=%u I[%u]=%u \n",hook,nums[hook],i,nums[i]);
            }
            else
                printf("[Dont move] hook[%u]=%u I[%u]=%u \n",hook,nums[hook],i,nums[i]);


            if(hook+1==nums.size() && nums[i]!=nums[hook-1])
                return hook+1;
        }


        return hook;
    }

};

#if 0
int main()
{
    Solution s;
    vector <int> A = {0,0,1,1,1,2,2,3,3,4};
    s.removeDuplicates(A);
    return 0;
}
#endif

