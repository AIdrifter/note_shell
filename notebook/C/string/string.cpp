#include <iostream>
#include <string>
#include <vector>

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

    int myAtoi(string str) {

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

    cout<<obj.reverseString("1234567890")<<endl;

    cout<<obj.reverse(0xfff00f00)<<endl;

    cout<<obj.firstUniqChar("leetcode")<<endl;
    cout<<obj.firstUniqChar("loveleetcode")<<endl;

    cout<<obj.isAnagram("anagram","nagaram")<<endl;
    cout<<obj.isAnagram("rat","car")<<endl;


    cout<<obj.isPalindrome("A man, a plan, a canal: Panama")<<endl;
    cout<<obj.isPalindrome("race a car")<<endl;


    cout<<obj.myAtoi("42")<<endl;
    cout<<obj.myAtoi("   -42")<<endl;
    cout<<obj.myAtoi("4193 with words")<<endl;
    cout<<obj.myAtoi("words and 987")<<endl;
    cout<<obj.myAtoi("-91283472332")<<endl;

    cout<<obj.strStr("hello","ll")<<endl;
    cout<<obj.strStr("aaaaa","bba")<<endl;

    cout<<obj.countAndSay(1)<<endl;
    cout<<obj.countAndSay(5)<<endl;

    vector<string> mul_str = {"flower","flow","flight"};
    vector<string> mul_str1 = {"dog","racecar","car"};
    cout<<obj.longestCommonPrefix(mul_str)<<endl;
    cout<<obj.longestCommonPrefix(mul_str1)<<endl;

    return 0;
}
