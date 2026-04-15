/*
 * Problem #1020: Number of Enclaves
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/12/2025, 12:28:32 AM
 * Link: https://leetcode.com/problems/number-of-enclaves/
 */

class Solution {
public:
    void dfs(int row, int col, int m, int n, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        for (int d = 0; d < 4; d++) {
            int nrow = row + delrow[d];
            int ncol = col + delcol[d];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1;
                dfs(nrow, ncol, m, n, grid, vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (grid[i][j] == 1) {
                        vis[i][j] = 1;
                        dfs(i, j, m, n, grid, vis);
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                    cnt++;
                
            }
        }
        return cnt;
    }
};
