/*
 * Problem #1091: Shortest Path in Binary Matrix
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 8/20/2025, 12:37:37 AM
 * Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
 */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<tuple<int, int, int>> q;

        q.push({1, 0, 0});

        dist[0][0] = 1;

        int delrow[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int delcol[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

        while (!q.empty()) {
            auto [dis, r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1)
                return dis;

            for (int i = 0; i < 8; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = dis + 1;
                    q.push({dis + 1, nrow, ncol});
                }
            }
        }

        return -1;
    }
};
