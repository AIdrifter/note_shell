/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (43.63%)
 * Total Accepted:    215.7K
 * Total Submissions: 494K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 */
class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> a;
            for( int i = 1; i<=numRows ;i++)
            {
                vector<int> b(i,0);
                b[0] = 1; b[i-1]=1;

                if(i==1 || i==2)
                {
                    a.push_back(b);
                    continue;
                }


                for(int j=1; j<i-1 ; j++)
                {
                   // printf("a[%u][%u] %u\n", i-2,j-1,a[i-2][j-1]);
                   // printf("a[%u][%u] %u \n", i-2,j,a[i-2][j]);
                    b[j] = a[i-2][j-1] + a[i-2][j];
                }
                a.push_back(b);
            }
            return a;
        }
};
