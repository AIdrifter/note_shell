/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (53.37%)
 * Total Accepted:    410.1K
 * Total Submissions: 768.3K
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
            int len = nums.size();

            // https://kw0006667.wordpress.com/2014/02/06/cstl-vector-erase-%E5%B0%8E%E8%87%B4%E8%BF%B4%E5%9C%88%E9%8C%AF%E8%AA%A4/
            // 宣告一個 iterator i，並將它指向 IntegerVec 的開始（begin）
            // 迴圈中會檢查 iterator 是否已經指向了 IntegerVec 的結尾（end）
            // 不讓迴圈自己在每圈都對 iterator + 1，而是讓我自在迴圈裡自己控制
            for(vector<int>::iterator iter = nums.begin(); iter != nums.end();){
                if((*iter)==0){
                    iter = nums.erase(iter);
                }
                else
                    iter++;
            }
            nums.resize(len);
        }
};
