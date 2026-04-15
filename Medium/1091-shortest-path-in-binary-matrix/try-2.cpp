/*
 * Problem #1091: Shortest Path in Binary Matrix
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/15/2025, 10:35:17 PM
 * Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
 */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        if(grid.size() == 1) return 1; 
        
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;

        typedef pair<int, pair<int, int>> pip;
        queue<pip> q;

        q.push({1, {0, 0}});

        while (!q.empty()) {
            int d = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;

            q.pop();

            int delrow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
            int delcol[] = {0, -1, 0, 1, 1, -1, 1, -1};

            for (int i = 0; i < 8; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && 1 + d < dist[nrow][ncol]) {
                    dist[nrow][ncol] = 1 + d;
                    if (nrow == n - 1 && ncol == n - 1 )
                        return d + 1;
                    q.push({1 + d, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};
