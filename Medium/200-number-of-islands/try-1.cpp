/*
 * Problem #200: Number of Islands
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/12/2025, 12:54:12 AM
 * Link: https://leetcode.com/problems/number-of-islands/
 */

class Solution {
private:
    void bfs(vector<vector<char>>& grid, int i, int j,
             vector<vector<int>>& vis, int m, int n) {
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
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(grid, i, j, vis, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};
