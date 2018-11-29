#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
using namespace std;



class Solution {
public:


    void reverse_str(char* str,int size)
    {
        int i;
        char *final = (char*)malloc(size);
        for (i=0;i<size;i++)
            final[size-i-1] = str[i];

        memcpy(str,final,size);
    }

    int reverse(int x) {
        char str[256] = {0};
        int tmp=(x>0)?x:-x;
        sprintf(str,"%d",tmp);
        reverse_str(str,strlen(str));
        long check_x = atoi(str);
        long int_min = INT_MIN;
        int_min = -int_min;
        printf("%d %d \n ",INT_MAX,INT_MIN);
        if(x>0)
            if(check_x > INT_MAX)
                return 0;
            else
                return check_x;
        else
            if( 0 > int_min - check_x)
                return 0;
            else
                return -check_x;


    }

    int firstUniqChar(string s) {
        int repeat[26] = {0};
        int index[26] = {0};

        for(int i=0;i<s.size();i++)
        {
            repeat[s[i]-97]++;
            if(index[s[i]-97]==0)
                index[s[i]-97]=i;
        }

        for(int i=0;i<26;i++)
        {
            if(repeat[i]==1)
                return index[i];
        }
        return -1;
    }

    string countAndSay(int n) {
        string S;
        int count=0;
        char tmp=0;

        if(n==1)
        {
            S="1";
            return S;
        }
        else
        {
            int i;
            string S1;
            S = countAndSay(n-1);
            for(i=0,tmp=S[0]; i<S.size(); i++)
            {
                if(tmp==S[i])
                {
                    count++;
                }
                else
                {
                    tmp=S[i];
                    string s_count;
                    s_count = to_string(count);
                    S1.append(s_count);
                    S1.push_back(S[i-1]);
                    //cout<<"DW i "<<i<<" tmp "<<tmp<<" "<<S[i-1]<<" "<<S1<<endl;
                    count = 1;
                }

            }

            if(i==S.size())
            {
                tmp=S[i];
                string s_count;
                s_count = to_string(count);
                S1.append(s_count);
                S1.push_back(S[i-1]);
                //cout<<"up i "<<i<<" tmp "<<tmp<<" "<<S[i-1]<<" "<<S1<<endl;
                count = 1;
                return S1;
            }
            return S1;
        }
    }
};


int main()
{
    Solution A;
    printf("%d\n",A.reverse(-123));
    printf("%d\n",A.reverse(1534236469));
    A.firstUniqChar("leetcode");
    return 0;
}
