/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (50.93%)
 * Total Accepted:    336.9K
 * Total Submissions: 661.4K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 *
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 *
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 *
 * Example 1:
 *
 *
 * Input: "III"
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: "IV"
 * Output: 4
 *
 * Example 3:
 *
 *
 * Input: "IX"
 * Output: 9
 *
 * Example 4:
 *
 *
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 *
 *
 * Example 5:
 *
 *
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 */
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            vector<bool> a(s.size(),false);
            vector<int>  val(s.size(),0);

            for(int i=0; i < s.size(); i++)
            {
                if(i+1 < s.size())
                {
                    if(a[i] == false && a[i+1] == false )
                    {
                        if(s[i]=='I' && s[i+1]=='V')
                        {
                            val[i] = 4;
                        }
                        if(s[i]=='I' && s[i+1]=='X')
                        {
                            val[i] = 9;
                        }
                        if(s[i]=='X' && s[i+1]=='L')
                        {
                            val[i] = 40;
                        }
                        if(s[i]=='X' && s[i+1]=='C')
                        {
                            val[i] = 90;
                        }
                        if(s[i]=='C' && s[i+1]=='D')
                        {
                            val[i] = 400;
                        }
                        if(s[i]=='C' && s[i+1]=='M')
                        {
                            val[i] = 900;
                        }

                        if(val[i]!=0)
                        {
                            a[i] = true; a[i+1] = true;
                        }
                    }
                }

                if(a[i] ==false)
                {
                    if(s[i] == 'I')
                        val[i] = 1;
                    if(s[i] == 'V')
                        val[i] = 5;
                    if(s[i] == 'X')
                        val[i] = 10;

                    if(s[i] == 'L')
                        val[i] = 50;
                    if(s[i] == 'C')
                        val[i] = 100;
                    if(s[i] == 'D')
                        val[i] = 500;
                    if(s[i] == 'M')
                        val[i] = 1000;

                    if(val[i]!=0)
                    {
                        a[i] = true;
                    }

                }

            }

            int sum=0;
            for (int i =0;i<s.size();i++)
                sum += val[i];

            return sum;
        }
};

# if 0
int main()
{
    Solution S;
    S.romanToInt("III");
}
#endif
