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
#include <climits>
#define PB push_back
#define ALL(v) v.begin(),v.end()
#define RALL(v) v.rbegin(),v.rend()
#define REP_0(i,m) for(int i=0;i<(int)(m);i++)
#define FOR_IT(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define MEMSET(a,b) memset(a,b,sizeof(a))
using namespace std;

inline int get_length(int x)
{
        using namespace std;
        int leng=0;
        while(x)
        {
                x/=10;
                leng++;
        }
        return leng;
}

#if 1
int main()
{
    int T;
    int N;
    string path;
    int element;

    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>N;
        cin>>path;
        string ans_path(path.size(),0);
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='S') ans_path[i] = 'E';
            if(path[i]=='E') ans_path[i] = 'S';
        }

        printf("Case #%u: %s \n",i,ans_path);

        //cout<<"Case #"<<i<<": "<<smallest<<endl;
    }

    return 0;
}
#endif

