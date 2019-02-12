/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (49.32%)
 * Total Accepted:    67K
 * Total Submissions: 135.9K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Shuffle a set of numbers without duplicates.
 *
 *
 * Example:
 *
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 *
 * // Shuffle the array [1,2,3] and return its result. Any permutation of
 * [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 *
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 *
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 *
 *
 */
class Solution {
public:
    vector<int> oriArray;
    Solution(vector<int> nums) {
        oriArray = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return oriArray;
    }

    /** (Knuth shuffle) Returns a random shuffling of the array. */
    /*
     * 這裡需要注意的是i + rand() % (res.size() - i)不能寫成rand() % res.size()，
     * 雖然也能通過OJ，但是根據這個帖子的最後部分的概率圖表，
     * 前面那種寫法不是真正的隨機分佈
     * https://yjk94.wordpress.com/2017/03/17/%E6%B4%97%E7%89%8C%E7%9A%84%E6%AD%A3%E7%A1%AE%E5%A7%BF%E5%8A%BF-knuth-shuffle%E7%AE%97%E6%B3%95/
     */
        vector<int> res = oriArray;
        for (int i = 0; i < res.size(); ++i) {
            int t = i + rand() % (res.size() - i);
            swap(res[i], res[t]);
        }
        return res;
    }












};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
