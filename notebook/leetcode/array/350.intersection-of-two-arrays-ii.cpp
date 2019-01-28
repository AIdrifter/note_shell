/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (46.34%)
 * Total Accepted:    168.5K
 * Total Submissions: 363.7K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 *
 *
 * Note:
 *
 *
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 *
 *
 * Follow up:
 *
 *
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            map <int,int> hash1;
            map <int,int> hash2;
            map <int,int>::iterator iter;
            vector<int> res;

            for (int i = 0; i < nums1.size(); i++)
            {
                hash1[nums1[i]]++;
            }

            for (int i = 0; i < nums2.size(); i++)
            {
                hash2[nums2[i]]++;
            }


            iter = hash1.begin();
            for (int i = 0; i < hash1.size(); i++)
            {
                if(hash2.find(iter->first) != hash2.end())
                {
                    while(iter->second != 0)
                    {
                        if(iter->second == 0 || hash2[iter->first] == 0)
                            break;

                        res.push_back(iter->first);
                        iter->second--;
                        hash2[iter->first]--;
                    }
                }
                iter++;
            }

            return res;

    }
};


#if 0
int main()
{
    Solution s;
    vector<int> nums1 = {3,1,2};
    vector<int> nums2 = {1,3};
    s.intersect(nums1,nums2);
    return 0;
}
#endif
