/*
 * Problem #2812: Find the Safest Path in a Grid
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/1/2026, 12:54:08 PM
 * Link: https://leetcode.com/problems/find-the-safest-path-in-a-grid/
 */

class Solution {
public:
    vector<vector<int>> bfs(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    dist[nx][ny] > dist[x][y] + 1) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return dist;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> dist = bfs(grid);
        int n = grid.size();
        int m = grid[0].size();

        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};

        vector<vector<int>> safe(n, vector<int>(m, -1));
        priority_queue<tuple<int, int, int>> pq;

        safe[0][0] = dist[0][0];
        pq.push({dist[0][0], 0, 0});

        while(!pq.empty()){
            auto [md, x, y] = pq.top();
            pq.pop();

            if (md < safe[x][y]) continue;

            if(x == n - 1 && y == m - 1) return md;
            for(int i = 0; i < 4; i++){
                
                int nx = x + delx[i];
                int ny = y + dely[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int newS = min(md, dist[nx][ny]);
                    if(safe[nx][ny] < newS){
                        safe[nx][ny] = newS;
                        pq.push({newS, nx, ny});
                    }
                }
                
            }
        }
        return 0;
    }
};
