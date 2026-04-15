/*
 * Problem #37: Sudoku Solver
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2025, 2:50:52 PM
 * Link: https://leetcode.com/problems/sudoku-solver/
 */

class Solution {
public:
    bool backtrack(vector<vector<char>>& board, vector<vector<int>>& row,
                   vector<vector<int>>& col, vector<vector<int>>& grid) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; k++) {
                        if (!row[k][i] && !col[k][j] &&
                            !grid[k][(i / 3 * 3 + j / 3)]) {
                            board[i][j] = k + '1';
                            row[k][i] = 1;
                            col[k][j] = 1;
                            grid[k][(i / 3 * 3 + j / 3)] = 1;

                            if (backtrack(board, row, col, grid)) {
                                return true;
                            }

                            board[i][j] = '.';
                            row[k][i] = 0;
                            col[k][j] = 0;
                            grid[k][(i / 3 * 3 + j / 3)] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> grid(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                else {
                    row[board[i][j] - '1'][i] = 1;
                    col[board[i][j] - '1'][j] = 1;
                    grid[board[i][j] - '1'][(i / 3 * 3 + j / 3)] = 1;
                }
            }
        }
        backtrack(board, row, col, grid);
    }
};
