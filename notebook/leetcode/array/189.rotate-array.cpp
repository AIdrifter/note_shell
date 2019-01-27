/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (28.42%)
 * Total Accepted:    254.3K
 * Total Submissions: 894.9K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstring> // Furthermore dont forget to include the header for the memcpy function
#include <map>

using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {

            // note you should prefer std::copy over memcpy. Especially when dealing with STL containers:
            /*
             *  basically it works like this:
             *  std::copy( src, src + size, dest );
             *
             *  so, you would do this:
             *  std::copy( pnIntArray, pnIntArray + 1, vIntVector.begin() );
             */
            k = k % nums.size();
            // if k < nums.size()
            vector<int> res(nums.size(),0);

            std::memcpy(&res[0] + k          ,&nums[0]                   ,(nums.size()-k) * sizeof(int));
            std::memcpy(&res[0]              ,&nums[nums.size()-k]       ,k*sizeof(int));
            std::memcpy(&nums[0]             ,&res[0]                    ,sizeof(int)*nums.size());
            //copy( nums.begin()     ,nums.end() - k    , res.begin());
            //copy( nums.begin() + k ,nums.begin() + k  ,res.begin() + k);
            //copy( res.begin()      ,res.begin() + k   ,nums.begin());

        }
};

#if 0
int main()
{
    Solution s;
    vector <int> A = {1,2,3,4,5,6,7};
    s.rotate(A,3);
    return 0;
}
#endif

