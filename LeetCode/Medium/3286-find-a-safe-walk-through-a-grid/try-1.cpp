/*
 * Problem #3286: Find a Safe Walk Through a Grid
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2026, 3:19:07 PM
 * Link: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/
 */

class Solution {
public:
    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m= grid[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        queue<tuple<int, int, int>> q;
        vector<vector<int>> best(n, vector<int>(m, 0));

        best[0][0] = (grid[0][0] == 1) ? health - 1 : health;
        q.push({best[0][0], 0, 0});

        while(!q.empty()){
            auto [h, x, y] = q.front();
            q.pop();

            if(x == n - 1 && y == m - 1){
                return (h >= 1) ? true : false;
            } 


            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
               

                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    
                    if(grid[nx][ny] == 0 && best[nx][ny] < h){
                        q.push({h, nx, ny});
                        best[nx][ny] = h;
                    }
                    else{
                        if(h > 1 && best[nx][ny] < h - 1){
                            q.push({h - 1, nx, ny});
                            best[nx][ny] = h - 1;
                        }
                    }
                }
            }
        }
        return false;
    }
};
