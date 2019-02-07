/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 *
 * https://leetcode.com/problems/first-bad-version/description/
 *
 * algorithms
 * Easy (28.55%)
 * Total Accepted:    197K
 * Total Submissions: 690K
 * Testcase Example:  '5\n4'
 *
 * You are a product manager and currently leading a team to develop a new
 * product. Unfortunately, the latest version of your product fails the quality
 * check. Since each version is developed based on the previous version, all
 * the versions after a bad version are also bad.
 * 
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the
 * first bad one, which causes all the following ones to be bad.
 * 
 * You are given an API bool isBadVersion(version) which will return whether
 * version is bad. Implement a function to find the first bad version. You
 * should minimize the number of calls to the API.
 * 
 * Example:
 * 
 * 
 * Given n = 5, and version = 4 is the first bad version.
 * 
 * call isBadVersion(3) -> false
 * call isBadVersion(5) -> true
 * call isBadVersion(4) -> true
 * 
 * Then 4 is the first bad version. 
 * 
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int binary_search(int start, int end)
    {
        // To overcome overflow . (A+B)/2  => A + (B-A)/2, if A<B
        int mid = start+ (end-start)/2;

        // F T T
        if(isBadVersion(mid-1) == false && isBadVersion(mid) == true && isBadVersion(mid+1) == true )
            return mid;

        // F F T
        if(isBadVersion(mid-1) == false && isBadVersion(mid) == false && isBadVersion(mid+1) == true )
            return mid+1;

        if(isBadVersion(mid))
            return binary_search(start,mid);
        else
            return binary_search(mid,end);
    }

    int firstBadVersion(int n) {
#if 0
        for(int i=1; i<=n; i++)
        {
            if(isBadVersion(i))
                return i;
        }
        return n;
#else
        // Binary Search
        if(n==1)
            return 1;

        return binary_search(1,n);

#endif
    }
};
