/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (58.49%)
 * Total Accepted:    169.2K
 * Total Submissions: 289.2K
 * Testcase Example:  '1'
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n.
 *
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 *
 * Example:
 *
 * n = 15,
 *
 * Return:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> result;
            bool mul3 = false, mul5 = false;
            int i;
            for (i =1; i<=n; i++)
            {
                if(i%3==0)
                    mul3 = true;
                if(i%5==0)
                    mul5 = true;

                if(mul3 == false && mul5 == false)
                    result.push_back(std::to_string(i));
                else if(mul3 && mul5)
                    result.push_back("FizzBuzz");
                else if(mul3)
                    result.push_back("Fizz");
                else
                    result.push_back("Buzz");

                mul3 = false;
                mul5 = false;
            }
            return result;
        }
};


#if 0
int main()
{
    Solution s;
    vector<string> a = s.fizzBuzz(1);
}
#endif
