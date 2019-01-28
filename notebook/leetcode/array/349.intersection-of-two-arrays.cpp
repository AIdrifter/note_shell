/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (52.18%)
 * Total Accepted:    187.9K
 * Total Submissions: 360K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 *
 *
 * Note:
 *
 *
 * Each element in the result must be unique.
 * The result can be in any order.
 *
 *
 *
 *
 */
class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            map <int,int> hash1;
            map <int,int> hash2;
            map <int,int>::iterator iter;
            vector<int> res;

            for (int i = 0; i < nums1.size(); i++)
            {
                if(hash1.find(nums1[i])==hash1.end())
                {
                    hash1[nums1[i]]++;
                }
            }

            for (int i = 0; i < nums2.size(); i++)
            {
                if(hash2.find(nums2[i])==hash2.end())
                {
                    hash2[nums2[i]]++;
                }
            }


            iter = hash1.begin();
            for (int i = 0; i < hash1.size(); i++)
            {
                if(hash2.find(iter->first) != hash2.end())
                {
                    res.push_back(iter->first);
                }
                iter++;
            }

            return res;

        }
};
