/*
 * Problem #36: Valid Sudoku
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/9/2026, 1:31:54 PM
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
                    if (row[i][board[i][j] - '1'] || col[j][board[i][j] - '1'] ||
                        grid[(i / 3) * 3 + (j / 3)][board[i][j] - '1'])
                        return false;
                    else {
                        row[i][board[i][j] - '1'] = 1;
                        col[j][board[i][j] - '1'] = 1;
                        grid[(i / 3) * 3 + (j / 3)][board[i][j] - '1'] = 1;
                    }
                }
            }
        }
        return true;
    }
};
