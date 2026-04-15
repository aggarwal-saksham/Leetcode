/*
 * Problem #130: Surrounded Regions
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/12/2025, 12:05:00 AM
 * Link: https://leetcode.com/problems/surrounded-regions/
 */

class Solution {
public:
    void dfs(int row, int col, int m, int n, vector<vector<char>>& board,
             vector<vector<char>>& ans) {
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        for (int d = 0; d < 4; d++) {
            int nrow = row + delrow[d];
            int ncol = col + delcol[d];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                board[nrow][ncol] == 'O' && ans[nrow][ncol] != 'O') {
                ans[nrow][ncol] = 'O';
                dfs(nrow, ncol, m, n, board, ans);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<char>> ans(m, vector<char>(n, 'X'));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 'O') {
                        ans[i][j] = 'O';
                        dfs(i, j, m, n, board, ans);
                    }
                }
            }
        }

        board = ans;
    }
};
