/*
 * Problem #980: Unique Paths III
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2025, 10:51:44 PM
 * Link: https://leetcode.com/problems/unique-paths-iii/
 */

class Solution {
public:
    void backtrack(int r, int c, int m, int n, int& cnt,
                   vector<vector<int>>& vis, vector<vector<int>>& grid,
                   int steps, int total) {

        if (grid[r][c] == 2) {
            if (steps == total)
                cnt++;
            return;
        }
        vis[r][c] = 1;

        int delrow[] = {1, 0, 0, -1};
        int delcol[] = {0, 1, -1, 0};

        for (int k = 0; k < 4; k++) {
            int nrow = r + delrow[k];
            int ncol = c + delcol[k];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                grid[nrow][ncol] != -1 && !vis[nrow][ncol]) {
                backtrack(nrow, ncol, m, n, cnt, vis, grid, steps + 1, total);
            }
        }
        vis[r][c] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;
        int total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] != -1) {
                    total++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    backtrack(i, j, m, n, cnt, vis, grid, 1, total);
                }
            }
        }

        return cnt;
    }
};
