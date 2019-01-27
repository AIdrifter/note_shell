/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (40.03%)
 * Total Accepted:    1.4M
 * Total Submissions: 3.4M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 *
 *
 */
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            /*
             *   1.Brute Forece
             *   O(n^2)
             */
#if 0
            vector<int> ret = {0,0};
            for (int i=0; i<nums.size(); i++)
            {
                for (int j=i+1; j<nums.size(); j++)
                {
                    if(nums[i] + nums [j] == target)
                    {
                        printf(" %u %u found\n",i,j);
                        ret[0] = i;
                        ret[1] = j;
                        return ret;

                    }
                    else
                    {
                        //printf(" %u %u not found\n",i,j);
                    }
               }
            }
#else
            /*
             *   2.hash map
             *   saved the diff in hash table
             *
             */
            map<int,int> HashTable;
            vector<int> ret = {0,0};
            map<int,int>::iterator iter;

           for (int i=0; i<nums.size(); i++)
           {
                iter = HashTable.find(target - nums[i]);
                if(iter == HashTable.end())
                    HashTable[nums[i]] = i;
                else
                {
                    ret[0] = iter->second;
                    ret[1] = i;
                    return ret;
                }
            }

#endif

           return ret;
        }
};
