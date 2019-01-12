/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (41.24%)
 * Total Accepted:    162K
 * Total Submissions: 392.8K
 * Testcase Example:  '27'
 *
 * Given an integer, write a function to determine if it is a power of three.
 *
 * Example 1:
 *
 *
 * Input: 27
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: 0
 * Output: false
 *
 * Example 3:
 *
 *
 * Input: 9
 * Output: true
 *
 * Example 4:
 *
 *
 * Input: 45
 * Output: false
 *
 * Follow up:
 * Could you do it without using any loop / recursion?
 */
#include <iostream>
#include <vector>

using namespace::std;

static const auto kSpeedUp = []() {    std::ios::sync_with_stdio(false);    std::cin.tie(nullptr);    return nullptr;}();


class Solution {
public:
    bool isPowerOfThree(int n) {
        int Divisor = n, Remainder=0;
        if(n==0)
            return false;
        if(n==1)
            return true;

        while(Divisor!=0)
        {
            Remainder = Divisor%3;
            Divisor = Divisor/3;

            printf(" %u %u \n",Remainder,Divisor);
            if(Divisor==1 && Remainder==0)
                return true;

            if(Remainder!=0)
                return false;

        };
        return true;
    }
};
