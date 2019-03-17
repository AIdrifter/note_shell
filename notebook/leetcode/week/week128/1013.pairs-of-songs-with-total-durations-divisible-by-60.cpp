/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Pairs of Songs With Total Durations Divisible by 60
 *
 * https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
 *
 * algorithms
 * Easy (39.37%)
 * Total Accepted:    3.2K
 * Total Submissions: 8.1K
 * Testcase Example:  '[30,20,150,100,40]'
 *
 * In a list of songs, the i-th song has a duration of time[i] seconds. 
 * 
 * Return the number of pairs of songs for which their total duration in
 * seconds is divisible by 60.  Formally, we want the number of indices i < j
 * with (time[i] + time[j]) % 60 == 0.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [30,20,150,100,40]
 * Output: 3
 * Explanation: Three pairs have a total duration divisible by 60:
 * (time[0] = 30, time[2] = 150): total duration 180
 * (time[1] = 20, time[3] = 100): total duration 120
 * (time[1] = 20, time[4] = 40): total duration 60
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [60,60,60]
 * Output: 3
 * Explanation: All three pairs have a total duration of 120, which is
 * divisible by 60.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= time.length <= 60000
 * 1 <= time[i] <= 500
 * 
 * 
 */

#include <cstring>
#include <string.h>
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

#define DFS 0
#define HASH_TABLE 1

class Solution {
public:
    int count;
    void dfs_combination(const vector<int>& nums, int n, int s,
            vector<int>& cur, vector<vector<int>>& ans) {
#if DFS // O(n^2)
        if (n == cur.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = s; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs_combination(nums, n, i + 1, cur, ans);
            cur.pop_back();
        }
#else  // loop unrolling
        for (int i = 0; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            for (int j = i+1; j < nums.size(); j++) {
                cur.push_back(nums[j]);
                if((cur[0]+cur[1]) % 60 == 0)this->count++;
                cur.pop_back();
            }
            cur.pop_back();
        }
#endif
    }

    int numPairsDivisibleBy60(vector<int>& time) {
#if DFS
        vector<vector<int>> ans;
        vector<int> cur;
        dfs_combination(time, 2, 0, cur, ans);
        for(int i = 0; i<ans.size() ; i++  )
            if( (ans[i][0] + ans[i][1])%60 == 0)
                this->count++;
#elif HASH_TABLE
        map<int,int>::iterator iter;
        map<int,int> hashT;
        for(int i = 0 ; i<time.size() ;i++ )
        {
            hashT[time[i]%60]++;
        }

        // consider much case
        for(iter=hashT.begin(); iter!=hashT.end(); iter++)
        {
            cout<<(iter->first)<<endl;
            if(iter->first > 30)
                break;

            // 30 => 150 , 90 ...
            // 0  => 0 , 60 , 120
            // C(n,2)
            if(iter->first == 30 || iter->first == 0){
                 this->count += (iter->second * (iter->second -1)) / 2;
                 //cout<<"case 1"<<endl;
            }
            else{
                if(hashT.find((60 - iter->first) % 60) != hashT.end()) {// Actually we can remove module operation
                    this->count += iter->second * hashT[(60 - iter->first) % 60];
                    //cout<<"case 2"<<endl;
                }
            }
        }
#endif
        return this->count;
    }
};
