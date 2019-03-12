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

// Author: Huahua, running time: 4 ms
#if DFS
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> cur;
    for (int i = 0; i <= nums.size(); ++i)
      dfs(nums, i, 0, cur, ans); // s:start point , cur : current numbers 會變大變小
    return ans;
  }

private:
  void dfs(const vector<int>& nums, int n, int s,
           vector<int>& cur, vector<vector<int>>& ans) {
    if (n == cur.size()) {
      ans.push_back(cur);
      return;
    }
    for (int i = s; i < nums.size(); ++i) {
      cur.push_back(nums[i]);
      dfs(nums, n, i + 1, cur, ans);
      cur.pop_back();
    }
  }
};
#else // binary bit operation
// Author: Huahua, running time: 4 ms
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> ans;
    for (int s = 0; s < 1 << n; ++s) {
      vector<int> cur;
      for (int i = 0; i < n; ++i)
        if (s & (1 << i)) cur.push_back(nums[i]);
      ans.push_back(cur);
    }
    return ans;
  }
};

#endif

#if 1
int main()
{
    Solution S;
    vector<int> A = {1,2,3,4};
    S.subsets(A);

    return 0;
}
#endif
