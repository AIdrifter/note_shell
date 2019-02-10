/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (48.75%)
 * Total Accepted:    218.6K
 * Total Submissions: 448.1K
 * Testcase Example:  '"leetcode"'
 *
 *
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 *
 *
 *
 *
 * Note: You may assume the string contain only lowercase letters.
 *
 */
class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> mark;
        int min_idx = INT_MAX;
        for(int i=0; i<s.size() ; i++)
        {
            if(mark.find(s[i]) == mark.end())
                mark[s[i]] = i;
            else
                mark[s[i]] = -1;
        }

        // You don't know hash table map sequence
        for(auto iter = mark.begin(); iter != mark.end() ; iter++)
        {
            printf(" %c %u \n",iter->first,iter->second);
            if(iter->second!=-1)
                if(min_idx > iter->second)
                    min_idx = iter->second;
        }

        if(min_idx == INT_MAX)
            return -1;

        return min_idx;
    }
};
