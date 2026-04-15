/*
 * Problem #79: Word Search
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2025, 11:28:16 PM
 * Link: https://leetcode.com/problems/word-search/
 */

class Solution {
public:
    bool backtrack(int idx, int row, int col, vector<vector<char>>& board,
                   string word) {
        int m = board.size();
        int n = board[0].size();

        int delrow[] = {1, 0, 0, -1};
        int delcol[] = {0, 1, -1, 0};

        if (idx == word.size()) {
            return true;
        }
        char temp = board[row][col];
        board[row][col] = '#';

        for (int k = 0; k < 4; k++) {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                board[nrow][ncol] == word[idx]) {
                if (backtrack(idx + 1, nrow, ncol, board, word))
                    return true;
            }
        }

        board[row][col] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (backtrack(1, i, j, board, word))
                        return true;
                    else
                        continue;
                }
            }
        }
        return false;
    }
};
