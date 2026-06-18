/*
 * Problem #130: Surrounded Regions
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/18/2026, 5:02:03 PM
 * Link: https://leetcode.com/problems/surrounded-regions/
 */

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board,
             int delRow[], int delCol[]) {

        int n = board.size();
        int m = board[0].size();

        board[r][c] = '#';

        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                board[nr][nc] == 'O') {
                dfs(nr, nc, board, delRow, delCol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                dfs(0, j, board, delRow, delCol);

            if (board[n - 1][j] == 'O')
                dfs(n - 1, j, board, delRow, delCol);
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board, delRow, delCol);

            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board, delRow, delCol);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
