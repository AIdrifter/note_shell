/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 *
 * https://leetcode.com/problems/image-smoother/description/
 *
 * algorithms
 * Easy (47.63%)
 * Total Accepted:    30.3K
 * Total Submissions: 63.6K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a 2D integer matrix M representing the gray scale of an image, you
 * need to design a smoother to make the gray scale of each cell becomes the
 * average gray scale (rounding down) of all the 8 surrounding cells and
 * itself.  If a cell has less than 8 surrounding cells, then use as many as
 * you can.
 *
 * Example 1:
 *
 * Input:
 * [[1,1,1],
 * ⁠[1,0,1],
 * ⁠[1,1,1]]
 * Output:
 * [[0, 0, 0],
 * ⁠[0, 0, 0],
 * ⁠[0, 0, 0]]
 * Explanation:
 * For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
 * For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
 * For the point (1,1): floor(8/9) = floor(0.88888889) = 0
 *
 *
 *
 * Note:
 *
 * The value in the given matrix is in the range of [0, 255].
 * The length and width of the given matrix are in the range of [1, 150].
 *
 *
 */

/*
 * a00 a01 a02
 * a10 a11 a12
 * a20 a21 a22
 */

class Solution {
    public:
        vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
            int m = M.size();
            int n = M[0].size();
            vector<vector<int>> ans = M;
            int range[] = {-1, 0, 1};

            for (int row = 0; row<m ; row++)
                for (int col = 0; col<n ; col++)
                {
                    int Dividend = 0;
                    int Divisor = 0;
                    for(int a: range)
                        for(int b: range)
                        {
                            int row_now = row + a ;
                            int col_now = col + b ;

                            if(row_now>=0 && row_now<m  && col_now>=0 && col_now<n )
                            {
                                    Dividend += M[row_now][col_now];
                                    Divisor++;
                            }
                        }
                    ans[row][col] = (int) floor((double)Dividend/Divisor);
                }

                return ans;
        }
};
