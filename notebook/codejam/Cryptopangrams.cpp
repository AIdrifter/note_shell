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


void factor(const vector<int> &ans,int production,int &x, int &y)
{
    pair<int,int> res;
    for(int i=0;i<ans.size();i++)
        for(int j=i;j<ans.size();j++)
            if(ans[i]*ans[j]== production)
            {
                x = ans[i];
                y = ans[j];
            }
}

vector<int> eratosthenes(int N)
{
    vector<bool> prime(N,false);
    vector<int> prime_set;
    for (int i=0; i<N; i++)  // 初始化
        prime[i] = true;

    prime[0] = false;   // 0 和 1 不是質數
    prime[1] = false;

    // 找下一個未被刪掉的數字
    for (int i=2; i<N; i++)
        if (prime[i])
            // 刪掉質數i的倍數，從兩倍開始。保留原本質數。
            for (int j=i+i; j<N; j+=i)
                prime[j] = false;

    for(int i=0;i<prime.size();i++)
        if(prime[i])
            prime_set.push_back(i);

    return prime_set;
}

#if 1
int main()
{
    int T;
    int N,L;
    string path;
    int element;

    cin>>T;
    for(int i=1;i<=T;i++)
    {
        string ans_str;
        cin>>N;
        cin>>L;
        vector<int> production;
        for(int i=0;i<L;i++)
        {
            cin>>element;
            production.push_back(element);
        }


        // get prime set
        vector<int> prime_set = eratosthenes(N+1);


        // compute production and get x, y
        int x,y,divisor;
        int first_x,first_y;
        map<int,char> hash;

        for(int j=0;j<L;j++)
        {
            if(j==0)
            {
                factor(prime_set,production[j],x,y);
                hash[x]++;
                hash[y]++;
                first_x = x;
                first_y = y;
    //            printf(" %u = %u * %u \n",production[j],x,y);
                continue;
            }

            divisor = (production[j])/x;

            if( divisor * x == production[j])
            {
                hash[divisor]++;
                y = divisor;
            }
            else
            {
                if(j==1)
                {
                    first_x=y;
                    first_y=x;
                }

                divisor = (production[j])/y;
                hash[divisor]++;
                x = divisor;
            }

//            printf(" %u = %u * %u \n",production[j],x,y);
            if(hash.size()==26)
                break;
        }

        char alpha = 'A';
        for(auto itr = hash.begin(); itr != hash.end(); ++itr){
            itr->second = alpha++;
  //          cout <<" "<< itr->first << ": " << itr->second << endl;
        }


        string final_ans;
        x = first_x;
        y = first_y;
        for(int j=0;j<production.size();j++)
        {
            if(j==0)
            {
                final_ans.push_back(hash[first_y]);
                final_ans.push_back(hash[first_x]);
                continue;
            }

            divisor = (production[j])/x;

            if( divisor * x == production[j])
            {
                final_ans.push_back(hash[divisor]);
                y = divisor;
            }
            else
            {
                divisor = (production[j])/y;
                final_ans.push_back(hash[divisor]);
                x = divisor;
            }

            if(final_ans.size()==production.size()+1)
                break;

        }

        cout<<"Case #"<<i<<": "<<final_ans<<endl;
    }

    return 0;
}
#endif

