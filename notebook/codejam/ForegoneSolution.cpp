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

inline bool check_4(int x)
{
    std::string s = std::to_string(x);
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='4')
            return true;
    }

    return false;
}

#if 1
int main()
{
    int T;
    int N,P;
    int element;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        cin>>N;
        int A = 0,B = 3, digits = 10;
        A = N - B;

        while(N-B < 0)
        {
            B--;
            A++;
        }


        while(check_4(A) && check_4(B))
        {
            A++;
            B--;
        }
        printf("Case #%u: %u %u \n",i,A,B);

        //cout<<"Case #"<<i<<": "<<smallest<<endl;
    }

    return 0;
}
#endif
