/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 *
 * https://leetcode.com/problems/repeated-string-match/description/
 *
 * algorithms
 * Easy (31.31%)
 * Total Accepted:    58.1K
 * Total Submissions: 185.5K
 * Testcase Example:  '"abcd"\n"cdabcdab"'
 *
 * Given two strings A and B, find the minimum number of times A has to be
 * repeated such that B is a substring of it. If no such solution, return -1.
 *
 * For example, with A = "abcd" and B = "cdabcdab".
 *
 * Return 3, because by repeating A three times (“abcdabcdabcd”), B is a
 * substring of it; and B is not a substring of A repeated two times
 * ("abcdabcd").
 *
 * Note:
 * The length of A and B will be between 1 and 10000.
 *
 */
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int repeat = 1;
        string oriA = A; 
        while(A.size()<=10000)
        {
            if(-1 != A.find(B,0))
            {
                //printf("find %u repeat %u \n",A.find(B,0), repeat);
                return repeat;
            }
            else
            {
                A.append(oriA,0,oriA.size());
                ++repeat;
            }
        }

        return -1;
    }
};
