/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.50%)
 * Total Accepted:    338.7K
 * Total Submissions: 836.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 *
 *
 * Example 2:
 *
 *
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 *
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
        vector<int> plusOne(vector<int>& digits) {
            int carry = 1;
            for(int i = digits.size()-1; i>=0; i--)
            {
                if( digits[i] != 9)
                {
                    digits[i]++;
                    carry = 0;
                    break;
                }
                else
                {
                    digits[i]=0;
                    carry = 1;
                }

                //if(digits[i] != 9)
                //{
                //    printf("%u %u does not carry \n",i,digits[i]);
                //    digits[i]++;
                //    carry = 0;
                //    break;
                //}
                //else
                //{
                //    printf("%u %u carry \n",i,digits[i]);
                //    digits[i]=0;
                //    carry = 1;
                //}

                if(carry && digits[0]==0)
                {
                    vector<int> res(digits.size()+1,0);
                    res[0] = 1;
                    memcpy(&res[1], &digits[0], sizeof(int)*digits.size());
                    return res;
                }
            }
            return digits;
        }
};

#if 0
int main()
{
    Solution s;
    vector <int> A = {9};
    s.plusOne(A);
    return 0;
}
#endif

