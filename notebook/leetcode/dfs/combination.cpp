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
#if 1
class Solution {
    vector<bool> visited;
public:
  vector<vector<int>> subsets(vector<int>& nums, int N) {
    vector<vector<int>> ans;
    vector<int> cur;
    // C(m,i) : i from 1 to n
    // C(m,0) + C(m,1) + C(m,2) ... C(m,n)
    for (int i = 0; i <= nums.size(); ++i)
      dfs_combination(nums, i, 0, cur, ans);
    return ans;
  }

  void setVisitedSize(int n)
  {
      static int flag = false;
      if(flag)
           return;

      visited.resize(n);
      for(int i=0; i<n; i++)
            visited[i] = false;

      flag = true;
  }

  void dfs_permutation(const vector<int>& nums, int n,
           vector<int>& cur, vector<vector<int>>& ans) {

    setVisitedSize(n);
    if (n == cur.size()) {
      ans.push_back(cur);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (visited[i]) continue;

      visited[i] = true;
      cur.push_back(nums[i]);
      dfs_permutation(nums, n, cur, ans);
      cur.pop_back();
      visited[i] = false;
    }
  }

private:

   /*
    * nums : elements of array
    * n    : c(m,n) number of elements to combination
    * s    : start of combination elements
    * cur  : combination result
    * ans  : final answer is vector of vector
    * void dfs_combination(const vector<int>& nums, int n, int s,
    */

  void dfs_combination(const vector<int>& nums, int n, int s,
           vector<int>& cur, vector<vector<int>>& ans) {
    if (n == cur.size()) {
      ans.push_back(cur);
      return;
    }
    for (int i = s; i < nums.size(); ++i) {
      cur.push_back(nums[i]);
      dfs_combination(nums, n, i + 1, cur, ans);
      cur.pop_back();
    }
  }


};
#else // binary bit operation
// Author: Huahua, running time: 4 ms
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums, int N) {
    const int n = nums.size();
    vector<vector<int>> ans;
    /*
     * 0 : ...000
     * 1 : ...001
     * 2 : ...010
     * 3 : ...011
     * 4 : ...100
     * 5 : ...101
     * 6 : ...110
     * 7 : ...111
    */
    for (int s = 0; s < 1 << n; ++s) {
      vector<int> cur;
      for (int i = 0; i < n; ++i)
        if (s & (1 << i)) cur.push_back(nums[i]);
      ans.push_back(cur);
    }

    // [FIXME] C(m,n) : keep vector size is equal to n

    return ans;
  }
};

#endif

#if 1
int main()
{
    Solution S;
    vector<int> A = {0,1,2};
    vector<vector<int>> ans;
    ans = S.subsets(A,2);

    vector<vector<int>> main_ans;
    vector<int> main_cur;
    S.dfs_permutation(A, 3, main_cur, main_ans);
    //cout<<ans<<endl;
    return 0;
}
#endif
