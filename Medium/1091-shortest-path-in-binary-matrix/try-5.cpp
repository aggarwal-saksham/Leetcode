/*
 * Problem #1091: Shortest Path in Binary Matrix
 * Difficulty: Medium
 * Submission: Try 5
 * status: Accepted
 * Language: cpp
 * Date: 6/21/2026, 12:39:50 AM
 * Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
 */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1) return -1;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<tuple<int, int, int>> q;

        dist[0][0] = 0;
        q.push({0, 0, 0});

        while(!q.empty()){
            auto [d, x, y] = q.front();
            q.pop();

            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if(i == 0 && j == 0) continue;

                    int nx = x + i;
                    int ny = y + j;

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && d + 1 < dist[nx][ny]){
                        dist[nx][ny] = d + 1;
                        q.push({d + 1, nx, ny});
                    }
                }
            }
        }

        return dist[n - 1][m - 1] == 1e9 ? -1 : dist[n - 1][m - 1] + 1;


    }
};
