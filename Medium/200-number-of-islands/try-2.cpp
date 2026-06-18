/*
 * Problem #200: Number of Islands
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/19/2026, 12:52:45 AM
 * Link: https://leetcode.com/problems/number-of-islands/
 */

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>> & grid,	vector<vector<int>> &vis) {
		vis[r][c] = 1;
		
		int n = grid.size();
		int m = grid[0].size();
		
		int delrow[] = {-1, 0, 1, 0};
		int delcol[] = {0, -1, 0, 1};
		
		for(int k = 0; k < 4; k++){
		    int nr= r + delrow[k];
		    int nc = c + delcol[k];
		    
		    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]){
		        dfs(nr, nc, grid, vis);
		    }
		}
		
	}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
		int m = grid[0].size();
		
		queue<pair<int, int>> q;
		
		vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vis[i][j] && grid[i][j] == '1') {
					dfs(i, j, grid, vis);
                    cnt++;
				}
			}
		}
		
		return cnt;
    }
};
