/*
 * Problem #417: Pacific Atlantic Water Flow
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/24/2026, 10:31:47 PM
 * Link: https://leetcode.com/problems/pacific-atlantic-water-flow/
 */

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        for(int k = 0; k < 4; k++) {
            int nr = r + delrow[k];
            int nc = c + delcol[k];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               !vis[nr][nc] &&
               grid[nr][nc] >= grid[r][c]) {

                dfs(nr, nc, grid, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            dfs(i, 0, grid, pac);
            dfs(i, m - 1, grid, atl);
        }

        for(int j = 0; j < m; j++) {
            dfs(0, j, grid, pac);
            dfs(n - 1, j, grid, atl);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
