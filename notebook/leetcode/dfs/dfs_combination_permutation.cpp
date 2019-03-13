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
#define NUMBER_SET 5
using namespace std;
string gesture[NUMBER_SET] = {"A","B","C","D","E"};
bool visited[NUMBER_SET] = {false};
string arrangement[NUMBER_SET];

void dfs(int layer){
    if (layer == NUMBER_SET){
        for (int i = 0; i < NUMBER_SET; i++){
            cout << arrangement[i] << "\t";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < NUMBER_SET; i++){
        if (visited[i]){
            continue;
        }
        visited[i] = true;
        arrangement[layer] = gesture[i];
        dfs(layer + 1);
        visited[i] = false;
    }
}



#if 1
int main()
{
    dfs(0);
    return 0;
}
#endif
