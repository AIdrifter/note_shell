/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (29.89%)
 * Total Accepted:    312.5K
 * Total Submissions: 1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 *
 * Example 1:
 *
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "race a car"
 * Output: false
 *
 *
 */
class Solution {
    public:
        bool isPalindrome(string s) {
            vector<char> alphaStr;
            for(int i = 0; i<s.size(); i++)
            {
                if('0' <= s[i] &&  s[i]<='9')
                    alphaStr.push_back(s[i]);
                if('a' <= s[i] &&  s[i]<='z')
                    alphaStr.push_back(s[i]);
                if('A' <= s[i] &&  s[i]<='Z')
                    alphaStr.push_back(s[i]+('a'-'A'));
            }

            int mid = alphaStr.size()/2;
            int idx = 0;

            if(!mid)
                return true;

            if(alphaStr.size()%2==0)
            {
                while(mid - idx -1 >= 0)
                {
                    //printf("mid+idx[%u]%c  mid-idx-1[%u]%c alphaStr.size() %u\n",mid+idx,alphaStr[mid+idx],mid-idx-1,alphaStr[mid-idx-1],alphaStr.size());
                    if(alphaStr[mid+idx] == alphaStr[mid-idx-1])
                        idx++;
                    else
                        return false;
                }
            }
            else
            {
                while(mid -idx >= 0)
                {
                    //printf("mid+idx[%u]%c  mid-idx[%u]%c alphaStr.size() %u\n",mid+idx,alphaStr[mid+idx],mid-idx,alphaStr[mid-idx],alphaStr.size());
                    if(alphaStr[mid+idx] == alphaStr[mid-idx])
                        idx++;
                    else
                        return false;
                }
            }

            return true;

        }

};
