/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (41.44%)
 * Total Accepted:    208.8K
 * Total Submissions: 504K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 *
 *
 *
 * A partially filled sudoku which is valid.
 *
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 *
 *
 * Note:
 *
 *
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int,int>::iterator iter;

        for (int i=0; i<board[0].size() ; i++)
        {
            map<int,int> hash_row;
            for (int j=0; j<board[0].size() ; j++)
                if(board[i][j]!='.')
                    hash_row[board[i][j]]++;

            for(iter = hash_row.begin(); iter != hash_row.end(); iter++)
                if(iter->second >= 2)
                    return false;
        }

        printf("row pass\n");

        for (int j=0; j<board[0].size() ; j++)
        {
            map<int,int> hash_col;
            for (int i=0; i<board[0].size() ; i++)
                if(board[i][j]!='.')
                    hash_col[board[i][j]]++;

            for(iter = hash_col.begin(); iter != hash_col.end(); iter++)
                if(iter->second >= 2)
                    return false;
        }

        printf("col pass\n");
        int start_i=0; int start_j = 0;

        for(start_i=0; start_i<board[0].size(); start_i+=3)
            for(start_j=0; start_j<board[0].size(); start_j+=3)
            {
                map<int,int> hash_region;
                int i,j;
                for (i=start_i; i<start_i+board[0].size()/3 ; i++)
                {
                    for (j=start_j; j<start_j+board[0].size()/3 ; j++)
                        {
                            if(board[i][j]!='.')
                                hash_region[board[i][j]]++;

                            printf(" [%u][%u]=%u ",i,j,board[i][j]);
                        }

                }
                puts("");

                for(iter = hash_region.begin(); iter != hash_region.end(); iter++)
                {
                    printf(" [%u][%u]  ",iter->first,iter->second);
                    if(iter->second >= 2)
                        return false;
                }

                puts("");
            }

        printf("region pass\n");

        return true;
    }
};

#if 0
int main()
{
    Solution S;
    vector<vector<char> > board{  {'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'} };

    vector<vector<char> > board1 {{'.','.','4','.','.','.','6','3','.'},
                                  {'.','.','.','.','.','.','.','.','.'},
                                  {'5','.','.','.','.','.','.','9','.'},
                                  {'.','.','.','5','6','.','.','.','.'},
                                  {'4','.','3','.','.','.','.','.','1'},
                                  {'.','.','.','7','.','.','.','.','.'},
                                  {'.','.','.','5','.','.','.','.','.'},
                                  {'.','.','.','.','.','.','.','.','.'},
                                  {'.','.','.','.','.','.','.','.','.'}};

    vector<vector<char> > board2 {{'.','.','.','.','5','.','.','1','.'},
                                  {'.','4','.','3','.','.','.','.','.'},
                                  {'.','.','.','.','.','3','.','.','1'},
                                  {'8','.','.','.','.','.','.','2','.'},
                                  {'.','.','2','.','7','.','.','.','.'},
                                  {'.','1','5','.','.','.','.','.','.'},
                                  {'.','.','.','.','.','2','.','.','.'},
                                  {'.','2','.','9','.','.','.','.','.'},
                                  {'.','.','4','.','.','.','.','.','.'}};

    vector<vector<char> > board3  [[".",".",".","1",".","8",".",".","."],
                                    [".",".",".",".",".",".",".",".","."],
                                    [".",".",".",".",".",".",".",".","."],
                                    ["4",".",".",".",".","7",".",".","."],
                                    [".",".",".","7",".",".","8","4","1"],
                                    [".",".",".",".","7",".",".",".","."],
                                    [".",".",".",".",".",".","6",".","."],
                                    [".",".",".","6",".",".",".",".","."],
                                    ["6",".",".",".",".",".",".",".","."]]

    S.isValidSudoku(board2);
    return 0;
}
#endif

