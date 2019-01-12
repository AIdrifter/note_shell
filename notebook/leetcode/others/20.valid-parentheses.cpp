/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (35.46%)
 * Total Accepted:    478.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 != 0)
            return false;

        stack<char> barckets;
        int i = 0;
        for (i = 0; i < s.size(); i++)
        {
            if(barckets.empty())
            {
                barckets.push(s[i]);
                //printf(" 1.push %c \n",s[i]);
            }
            else
            {
                if( (barckets.top()=='(' && s[i] == ')') ||
                    (barckets.top()=='[' && s[i] == ']') ||
                    (barckets.top()=='{' && s[i] == '}'))
                {
                    barckets.pop();
                    //printf(" pop %c \n",s[i]);
                }
                else
                {
                    barckets.push(s[i]);
                    //printf(" 2.push %c \n",s[i]);
                }
            }
        }
        return (barckets.size() == 0);
    }
};
