/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (52.36%)
 * Total Accepted:    190.4K
 * Total Submissions: 363.5K
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
        map<int,int> hash_table1;
        map<int,int> hash_table2;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
            hash_table1[nums1[i]]++;

        for(int i=0;i<nums2.size();i++)
            hash_table2[nums2[i]]++;

        for(auto iter = hash_table1.begin();iter!=hash_table1.end();iter++)
            for(auto iter2 = hash_table2.begin();iter2!=hash_table2.end();iter2++)
                if(iter->first==iter2->first)
                    ans.push_back(iter->first);

        return ans;
    }
};
