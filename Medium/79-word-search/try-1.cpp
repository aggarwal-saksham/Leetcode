/*
 * Problem #79: Word Search
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2025, 11:20:43 PM
 * Link: https://leetcode.com/problems/word-search/
 */

class Solution {
public:
    bool backtrack(int idx, int row, int col, vector<vector<int>>& vis,
                   vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        int delrow[] = {1, 0, 0, -1};
        int delcol[] = {0, 1, -1, 0};

        if (idx == word.size()) {
            return true;
        }

        vis[row][col] = 1;

        for (int k = 0; k < 4; k++) {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                board[nrow][ncol] == word[idx] && !vis[nrow][ncol]) {
                if (backtrack(idx + 1, nrow, ncol, vis, board, word))
                    return true;
            }
        }

        vis[row][col] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (backtrack(1, i, j, vis, board, word))
                        return true;
                    else
                        continue;
                }
            }
        }
        return false;
    }
};
