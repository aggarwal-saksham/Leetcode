/*
 * Problem #1631: Path With Minimum Effort
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/21/2026, 1:38:30 AM
 * Link: https://leetcode.com/problems/path-with-minimum-effort/
 */

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};

        vector<vector<int>> effort(n, vector<int>(m, 1e9));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        effort[0][0] = 0;
        pq.push({0, 0, 0});

        while(!pq.empty()){
            auto [diff, x, y] = pq.top();
            pq.pop();

            if(x == n - 1 && y == m - 1) return diff;
            for(int i = 0; i < 4; i++){
                
                int nx = x + delx[i];
                int ny = y + dely[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int neweff = max(abs(grid[nx][ny] - grid[x][y]), diff);
                    if(neweff < effort[nx][ny]){
                        effort[nx][ny] = neweff;
                        pq.push({neweff, nx, ny});
                    }
                }
                
            }
        }
        return 0;
    }
};
