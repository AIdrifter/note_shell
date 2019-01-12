/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (69.76%)
 * Total Accepted:    208.7K
 * Total Submissions: 299K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note:
 * 0 ≤ x, y < 231.
 *
 *
 * Example:
 *
 * Input: x = 1, y = 4
 *
 * Output: 2
 *
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 *
 * The above arrows point to positions where the corresponding bits are
 * different.
 *
 *
 */
class Solution {
    public:
        int hammingDistance(int x, int y) {
            int xor_res = x^y;
            int nums_of_1 = 0;
            for (int i = 0; i<32; i++)
            {
                if(xor_res & 1)
                {
                   nums_of_1++;
                }
                xor_res = xor_res >> 1;
            }
            return nums_of_1;
        }
};
