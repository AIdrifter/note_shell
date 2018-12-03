#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string reverseString(string s) {

    }

    int reverse(int x) {

    }

    /*
     * Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
     */
    int firstUniqChar(string s) {

    }

    bool isAnagram(string s, string t) {

    }

    bool isPalindrome(string s) {

    }

    // This solves the issue of using the standard abs() function
    unsigned int absu(int value) {
        return (value < 0) ? -((unsigned int)value) : (unsigned int)value;
    }
    /*
     *   The function first discards as many whitespace characters as necessary
     *   until the first non-whitespace character is found.
     */


    int myAtoi(string str) {
        bool negative = false;
        bool firstCH = false;
        long sum = 0;
        for (int i=0;i<str.size();i++){
            // translate to digits
            if(str[i]!=' ' && firstCH == false)
            {
                firstCH = true;
                if(str[i]=='-' )
                {
                    negative = true;
                    continue;
                }
                if(str[i]=='+' )
                {
                    negative = false;
                    continue;
                }
            }

            if(str[i]<='9' && str[i]>='0'){
                sum *= 10;
                sum += (str[i]-'0');
                // check overflow and underflow
                if(!negative){
                    if(sum > INT_MAX){
                        sum = INT_MAX;
                        break;
                    }
                }
                else{
                    if(sum > absu(INT_MIN)){
                        sum = INT_MIN;
                        break;
                    }
                }
            }
            else
            {
                // continuous numeric string is broken
                if(firstCH)
                    break;
            }
        }

        return negative?-sum:sum;
    }

    int strStr(string haystack, string needle) {

    }

    string countAndSay(int n) {

    }

    string longestCommonPrefix(vector<string>& strs) {

    }

    void assign_str(string s)
    {
        str = s;
    }


private:
    string str;

};


int main()
{
    Solution obj;
    obj.assign_str("1234567890");

    //cout<<obj.reverseString("1234567890")<<endl;

    //cout<<obj.reverse(0xfff00f00)<<endl;

    //cout<<obj.firstUniqChar("leetcode")<<endl;
    //cout<<obj.firstUniqChar("loveleetcode")<<endl;

    //cout<<obj.isAnagram("anagram","nagaram")<<endl;
    //cout<<obj.isAnagram("rat","car")<<endl;


    //cout<<obj.isPalindrome("A man, a plan, a canal: Panama")<<endl;
    //cout<<obj.isPalindrome("race a car")<<endl;


    cout<<obj.myAtoi("42")<<endl;
    cout<<obj.myAtoi("   -42")<<endl;
    cout<<obj.myAtoi("4193 with words")<<endl;
    cout<<obj.myAtoi("words and 987")<<endl;
    cout<<obj.myAtoi("-91283472332")<<endl;

    cout<<obj.strStr("hello","ll")<<endl;
    cout<<obj.strStr("aaaaa","bba")<<endl;

    //cout<<obj.countAndSay(1)<<endl;
    //cout<<obj.countAndSay(5)<<endl;

    //vector<string> mul_str = {"flower","flow","flight"};
    //vector<string> mul_str1 = {"dog","racecar","car"};
    //cout<<obj.longestCommonPrefix(mul_str)<<endl;
    //cout<<obj.longestCommonPrefix(mul_str1)<<endl;

    return 0;
}
