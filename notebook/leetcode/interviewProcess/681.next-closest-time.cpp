/*
 * @lc app=leetcode id=681 lang=cpp
 *
 * [681] Next Closest Time
 *
 * https://leetcode.com/problems/next-closest-time/description/
 *
 * algorithms
 * Medium (42.36%)
 * Total Accepted:    44.5K
 * Total Submissions: 105K
 * Testcase Example:  '"19:34"'
 *
 * Given a time represented in the format "HH:MM", form the next closest time
 * by reusing the current digits. There is no limit on how many times a digit
 * can be reused.
 *
 * You may assume the given input string is always valid. For example, "01:34",
 * "12:09" are all valid. "1:34", "12:9" are all invalid.
 *
 * Example 1:
 *
 * Input: "19:34"
 * Output: "19:39"
 * Explanation: The next closest time choosing from digits 1, 9, 3, 4, is
 * 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs
 * 23 hours and 59 minutes later.
 *
 *
 *
 * Example 2:
 *
 * Input: "23:59"
 * Output: "22:22"
 * Explanation: The next closest time choosing from digits 2, 3, 5, 9, is
 * 22:22. It may be assumed that the returned time is next day's time since it
 * is smaller than the input time numerically.
 *
 *
 */
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#define PB push_back
#define ALL(v) v.begin(),v.end()
#define RALL(v) v.rbegin(),v.rend()
#define REP_0(i,m) for(int i=0;i<(int)(m);i++)
#define FOR_IT(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define MEMSET(a,b) memset(a,b,sizeof(a))

using namespace std;

/*
 * we need to consider 5 thing
 * 1. string to interger :atoi() pr stoi() , intger to string : sprintf()
 * 2. substring: substr()
 * 3. time conversion/difference
 * 4. string format
 * 5. set
 *     - includes(begin,end,begin.end)
 */
class Solution {
public:
    string nextClosestTime(string time) {
        // create set s to check new time's set includes or not.
        set<char> s = {time.begin(), time.end()};

        //   [0][1][2][3][4]
        //    1  2  :  3  3
        int hr = stoi(time.substr(0,2));
        int min = stoi(time.substr(3,2));

        while(1){
            min++;
            if(min==60){
               min = 0;
               hr++;
               if(hr==24) hr = 0;
            }

            char buf[6];
            //sprintf(buf, "%u:%u", hr, min); 0:0 is not correct
            sprintf(buf, "%02d:%02d", hr, min);
            string tmp(buf);
            set<char> now_time = {tmp.begin(), tmp.end()};

            // cout<<time<<" "<<tmp<<endl;

            //
            // https://www.geeksforgeeks.org/stdincludes-c-stl/
            //
            //  bool includes (initer1 beg1, initer1 end1,
            //                 initer2 beg2, initer2 end2,)
            // Return value : 
            //    True if every element of 2nd container lies in 1st container.
            if(includes(s.begin(), s.end(), now_time.begin(), now_time.end()))
                return tmp;
        }

        return {};

    }
};

#if 0
int main()
{
    Solution S;
    string time = {"23:59"};
    S.nextClosestTime(time);
    return 0;
}
#endif

