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
class Solution
{
};

void add2(int i) {
   cout << i+2 << endl;
}

template<int val>
void addVal(int i) {
   cout << val+i << endl;
}

class AddValue {
   int val;
   public:
   AddValue(int j) : val(j) { }
   void operator()(int i) {
      cout << i+val << endl;
   }
};

int main()
{
   vector<int> vec = { 2, 3, 4, 5};   
   //for_each(vec.begin(), vec.end(), add2); // {4, 5, 6, 7}
   int x = 2;
   //for_each(vec.begin(), vec.end(), addVal<x>); // {4, 5, 6, 7} , you will compile failed ... 
   for_each(vec.begin(), vec.end(), AddValue(x)); // {4, 5, 6, 7}
}

