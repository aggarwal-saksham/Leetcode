/*
 * Problem #1020: Number of Enclaves
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/18/2026, 5:29:56 PM
 * Link: https://leetcode.com/problems/number-of-enclaves/
 */

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid,
             int delRow[], int delCol[]) {

        int n = grid.size();
        int m = grid[0].size();

        grid[r][c] = 2;

        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] == 1) {
                dfs(nr, nc, grid, delRow, delCol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1)
                dfs(0, j, grid, delRow, delCol);

            if (grid[n - 1][j] == 1)
                dfs(n - 1, j, grid, delRow, delCol);
        }

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1)
                dfs(i, 0, grid, delRow, delCol);

            if (grid[i][m - 1] == 1)
                dfs(i, m - 1, grid, delRow, delCol);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};
