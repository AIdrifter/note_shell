/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (34.55%)
 * Total Accepted:    318.8K
 * Total Submissions: 922.8K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 * Note:
 *
 *
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 *
 *
 * Example:
 *
 *
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 *
 * Output: [1,2,2,3,5,6]
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
#if 0
        vector<int> ans;
        ans.resize(m+n);
        int a0 = 0,a1 = 0;

        if(m==0)
        {
            return;
        }

        if(n==0)
        {
            nums1.resize(m+n);
            memcpy(&nums1[0],&nums2[0],m+n);
            return;
        }

        for(int i=0; i<m+n; i++)
        {
            if(nums1[a0]<nums2[a1])
            {
                ans[i]=nums1[a0];
                a0++;
            }
            else
            {
                ans[i]=nums2[a1];
                a1++;
            }

            if(a0==m-1)
            {
                memcpy(&ans[a0+a1+1],&nums2[a1],sizeof(int)*(n-a1));
                ans[i+1]=nums1[a0];
                break;
            }
            if(a1==n-1)
            {
                memcpy(&ans[a0+a1+1],&nums1[a0],sizeof(int)*(m-a0));
                ans[i+1]=nums2[a1];
                break;
            }
        }

        nums1.resize(m+n);
        memcpy(&nums1[0],&ans[0],sizeof(int)*(m+n));
        return;
#else
    // 向思路，merge後的數組一共有m+n個數。i, j從A, B尾部掃瞄，選max(A[i], B[j])插入從m+n起的尾部。這樣也可以防止插入到A原來數字的範圍內時，overwrite掉A原來的數。

    vector<int> ans;
    ans.resize(m+n);
    int a=m-1, b=n-1 ,pc = n+m-1;

    while(a>=0 &&b>=0)
    {
        if(nums1[a]>nums2[b])
        {
            ans[pc--] = nums1[a];
            a--;
        }
        else
        {
            ans[pc--] = nums2[b];
            b--;
        }
    }

    while(a>=0) ans[pc--] = nums1[a--];
    while(b>=0) ans[pc--] = nums2[b--];

   nums1.resize(m+n);
   memcpy(&nums1[0],&ans[0],sizeof(int)*(m+n));

#endif
    }
};

#if 0
int main()
{
    Solution S;
    vector<int> A = {1,2,3,0,0,0};
    vector<int> B = {2,5,6};
    S.merge(A,3,B,3);

    return 0;
}
#endif

