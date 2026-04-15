/*
 * Problem #1254: Number of Closed Islands
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2025, 3:25:04 AM
 * Link: https://leetcode.com/problems/number-of-closed-islands/
 */

class Solution {
public:
    void bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis,
             int m, int n) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {

                    if (!vis[i][j] && grid[i][j] == 0) {
                        bfs(grid, i, j, vis, m, n);
                    }
                }
            }
        }
        int count = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (!vis[i][j] && grid[i][j] == 0) {
                    bfs(grid, i, j, vis, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};
