/*
 * Problem #994: Rotting Oranges
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/17/2026, 7:30:56 PM
 * Link: https://leetcode.com/problems/rotting-oranges/
 */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();

        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, -1, 0, 1};

        queue<pair<int, int>> q;

        int total = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] != 0) total++;
            }
        }

        int cnt = 0, time = 0;
        while(!q.empty()){
            int k = q.size();
            cnt += k;

            while(k--){
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + delx[i];
                    int ny = y + dely[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }

            if(!q.empty()) time++;
        }
        return total == cnt ? time : -1;
    }
};
