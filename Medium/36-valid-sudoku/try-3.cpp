/*
 * Problem #36: Valid Sudoku
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 2/27/2026, 9:36:25 PM
 * Link: https://leetcode.com/problems/valid-sudoku/
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> grid(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (row[board[i][j] - '1'][i] || col[board[i][j] - '1'][j] ||
                        grid[board[i][j] - '1'][(i / 3) * 3 + (j / 3)])
                        return false;
                    else {
                        row[board[i][j] - '1'][i] = 1;
                        col[board[i][j] - '1'][j] = 1;
                        grid[board[i][j] - '1'][(i / 3) * 3 + (j / 3)] = 1;
                    }
                }
            }
        }
        return true;
    }
};
