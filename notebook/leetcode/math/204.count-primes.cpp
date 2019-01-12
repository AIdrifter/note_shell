/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (27.72%)
 * Total Accepted:    201.2K
 * Total Submissions: 726K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Example:
 *
 *
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 *
 */
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace::std;

static const auto kSpeedUp = []() {    std::ios::sync_with_stdio(false);    std::cin.tie(nullptr);    return nullptr;}();
class Solution {
    public:
        int countPrimes(int n) {
            int primes_num = 0;
            if(n ==0)
                return 0;
            if(n ==1)
                return 0;

            /* sieve of Eratosthenes */
            vector<bool> sieve(n + 1, true);

            for(int i=2; i<n; i++)
            {
                if(sieve[n])
                {
                    for(int j=i*2; j<n; j=j+i)
                        sieve[j] = false;
                }
            }


            for(int i=2; i<n; i++)
            {
                if(sieve[i])
                {
                    //cout<<i<<endl;
                    primes_num++;
                }
            }

            return primes_num;
        }
};


#if 0
int main()
{
    Solution s;
    s.countPrimes(10);
}
#endif
