#include <stdio.h>
#include <stdlib.h>
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


#define PRIME_NUM 10001

bool prime[PRIME_NUM];
//vector<int> production = {217, 1891, 4819, 2291, 2987, 3811, 1739, 2491, 4717, 445, 65, 1079, 8383, 5353, 901, 187, 649, 1003, 697, 3239, 7663, 291 ,123 ,779 ,1007, 3551 ,1943 ,2117 ,1679 ,989 ,3053};
vector<int> production = {3292937 ,175597 ,18779 ,50429 ,375469, 1651121, 2102 ,3722 ,2376497 ,611683 ,489059, 2328901, 3150061, 829981, 421301, 76409, 38477 ,291931, 730241 ,959821, 1664197, 3057407 ,4267589, 4729181, 5335543};

vector<int> ans;
void factor(int production,int &x, int &y)
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

void eratosthenes()
{
    for (int i=0; i<PRIME_NUM; i++)  // 初始化
        prime[i] = true;

    prime[0] = false;   // 0 和 1 不是質數
    prime[1] = false;

    // 找下一個未被刪掉的數字
    for (int i=2; i<PRIME_NUM; i++)
        if (prime[i])
            // 刪掉質數i的倍數，從兩倍開始。保留原本質數。
            for (int j=i+i; j<PRIME_NUM; j+=i)
                prime[j] = false;
}

int main()
{
    eratosthenes();
    for(int i=PRIME_NUM; i>0; i--)
    {
       // push all possible primes
       ans.push_back(i);
    }

    puts("");
    map<int,char> hash;

    int x,y,divisor;
    int first_x,first_y;
    for(int i=0;i<production.size();i++)
    {
        if(i==0)
        {
            factor(production[i],x,y);
            hash[x]++;
            hash[y]++;
            first_x = x;
            first_y = y;
            continue;
        }

        divisor = (production[i])/x;

        if( divisor * x == production[i])
        {
             hash[divisor]++;
             y = divisor;
        }
        else
        {
            divisor = (production[i])/y;
            hash[divisor]++;
            x = divisor;
            if(i==1)
            {
                first_x=y;
                first_y=x;
            }
        }

        printf(" %u = %u * %u \n",production[i],x,y);
        if(hash.size()==26)
            break;
    }

    char alpha = 'A';
    map<char,int> res;
    for(auto itr = hash.begin(); itr != hash.end(); ++itr){
        itr->second = alpha;
        res[alpha++] = itr->second;
		cout <<" "<< itr->first << ": " << itr->second << endl;
	}

    string final_ans;
    x = first_x;
    y = first_y;
    for(int i=0;i<production.size();i++)
    {
        if(i==0)
        {
            final_ans.push_back(hash[first_y]);
            final_ans.push_back(hash[first_x]);
            continue;
        }

        divisor = (production[i])/x;

        if( divisor * x == production[i])
        {
             final_ans.push_back(hash[divisor]);
             y = divisor;
        }
        else
        {
            divisor = (production[i])/y;
            final_ans.push_back(hash[divisor]);
            x = divisor;
        }

        if(final_ans.size()==production.size()+1)
            break;

    }

    cout<<final_ans<<endl;

    return 0;
}
