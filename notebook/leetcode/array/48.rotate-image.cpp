/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (46.11%)
 * Total Accepted:    216.1K
 * Total Submissions: 468.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Note:
 *
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 *
 * Example 1:
 *
 *
 * Given input matrix =
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 *
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Given input matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ],
 *
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    void swap(int &a, int &b)
    {
        /*
         * Well, take a look at what happens if we expand out line 1:
         *
         * x = x xor y
         * x = x xor x  // x and y are equal
         * x = 0
         * Wow! So x becomes 0 right at the get-go. That’s ok by itself,
         * but because x and y are at the same location, we just made y zero as well! We’ve lost the original values
         *
         */
        if(&a!=&b)
        {
            a = a ^ b;
            b = b ^ a;
            a = a ^ b;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
#if 1
        int len = matrix[0].size();
        // reverse diagonal
        for (int i=0; i<len - 1; i++)
            for (int j=0; j<len - i ; j++)
                swap(matrix[i][j], matrix[len-j-1][len-i-1]);

       printf("[DEBUG][%s]@%u",__func__,__LINE__);

        // reverse x axis
        for (int i=0; i<len/2; i++)
            for (int j=0; j<len; j++)
            {
                swap(matrix[i][j], matrix[len-i-1][j]);
            }
       printf("[DEBUG][%s]@%u",__func__,__LINE__);
#endif

    }
};

#if 0
int main()
{
    Solution S;
    vector<vector<int>> A {{1,2,3},{4,5,6},{7,8,9}};
    S.rotate(A);
    return 0;
}
#endif

