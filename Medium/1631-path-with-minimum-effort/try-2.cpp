/*
 * Problem #1631: Path With Minimum Effort
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 8/20/2025, 12:56:35 AM
 * Link: https://leetcode.com/problems/path-with-minimum-effort/
 */

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        
        vector<vector<int>> effort(n, vector<int>(m, 1e9));
        effort[0][0] = 0;

        typedef pair<int, pair<int, int>> pip;
        priority_queue<pip, vector<pip>, greater<pip>> pq;

        pq.push({0, {0, 0}});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            if (row == n - 1 && col == m - 1)
                return d;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int neweff = max(abs(grid[nrow][ncol] - grid[row][col]), d);
                    if (neweff < effort[nrow][ncol]) {
                        effort[nrow][ncol] = neweff;
                        pq.push({neweff, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
