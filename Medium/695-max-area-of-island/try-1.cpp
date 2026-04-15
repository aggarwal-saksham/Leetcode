/*
 * Problem #695: Max Area of Island
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/21/2025, 1:49:14 AM
 * Link: https://leetcode.com/problems/max-area-of-island/
 */

class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis,
            int m, int n) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        int localmaxi = 1;
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    localmaxi++;
                    q.push({nrow, ncol});
                }
            }
        }
        return localmaxi;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    ans = max(ans, bfs(grid, i, j, vis, m, n));
                }
            }
        }
        return ans;
    }
};
