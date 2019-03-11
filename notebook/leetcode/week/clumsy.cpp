#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int sum = 0;
    int clumsy(int N) {
        int i = 0;
        static int op_status = 0;
        vector<int> sub_sum(N);
        for(int i = N ; i<=1; i--);
        {
            switch(op_status)
            {
                case 0 :
                        sub_sum[i] = i * (i-1);
                        break;
                case 1 :
                        sub_sum[i] = i  (i-1);
                        break;
                case 2 :
                        sub_sum[i] = i * (i-1);
                        break;
                case 3 :
                        sub_sum[i] = i * (i-1);
                        break;

            }
        }
    }
};

#if 1
int main()
{
    Solution S;
    S.clumsy(4);
    S.clumsy(10);
    return 0;
}
#endif
