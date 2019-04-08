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


void fermat(int n,int &out_x,int &out_y)
{
    for (int a = 2;  a<=ceil(sqrt(n)); ++a)
    {
        if(n%a==0)
        {
            out_x = a;
            break;
        }

    }
    out_y = n/out_x;
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
    int T=1;
    srand (time(NULL));
    cout<<T<<endl;
    for(int i=1;i<=T;i++)
    {
        string ans_str;
        int N=random()%10000,L=50;
        cout<<N<<" ";
        cout<<L<<endl;

        vector<int> prime_set = eratosthenes(N);
        vector<int> prime26;

        for(int i=0;i<=25;i++)
        {
            int index = random()%prime_set.size();
            prime26.push_back(prime_set[index]);
            prime_set.erase(prime_set.begin()+index);
        }


        sort(prime26.begin(),prime26.end());
        vector<int> production;

        vector<bool> repeat(26,false);
        string ans;
        int element;
        int idx = random()%26;
        repeat[idx] = true;

        int previous = prime26[idx];
        ans.push_back(idx+'A');
        for(int i=0;i<L;i++)
        {
            while(repeat[idx])
            {
               static int i = 0;
               i++;
               idx = random()%26;
               if(i%100==0)
               {
                    for(int i=0;i<26;i++)
                        if(repeat[i]==false)
                        {
                            idx = i;
                            break;
                        }
               }
            }
            repeat[idx] = true;

            int new_prime = prime26[idx];
            ans.push_back(idx+'A');
            cout<<new_prime*previous<<" ";
            previous = new_prime;
        }
        cout<<endl;

        char alpha = 'A';
        for(int i = 0; i<=25 ;i++)
        {
            cout<<alpha++<<" "<<prime26[i]<<endl;
        }

        cout<<ans<<endl;

    }

    return 0;
}
#endif

