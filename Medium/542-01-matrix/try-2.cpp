/*
 * Problem #542: 01 Matrix
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/18/2026, 2:16:19 PM
 * Link: https://leetcode.com/problems/01-matrix/
 */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int m = mat[0].size();

        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, -1, 0, 1};

        queue<tuple<int, int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({i, j, 0});
                }
            }
        }


        while(!q.empty()){
            auto [x, y, steps] = q.front();
            q.pop();

            dist[x][y] = steps;

            for (int i = 0; i < 4; i++) {
                int nx = x + delx[i];
                int ny = y + dely[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny, steps + 1});
                }
            }
        }
        return dist;
    }
};
