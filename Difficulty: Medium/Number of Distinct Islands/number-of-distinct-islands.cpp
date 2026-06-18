class Solution {
	public:
	void dfs(int r, int c, vector<vector<char>> & grid,
	vector<vector<int>> &vis, vector<pair<int, int>> &v,
	int &r0, int &c0) {
		vis[r][c] = 1;
		v.push_back({r - r0, c - c0});
		
		int n = grid.size();
		int m = grid[0].size();
		
		int delrow[] = {-1, 0, 1, 0};
		int delcol[] = {0, -1, 0, 1};
		
		for(int k = 0; k < 4; k++){
		    int nr= r + delrow[k];
		    int nc = c + delcol[k];
		    
		    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 'L' && !vis[nr][nc]){
		        dfs(nr, nc, grid, vis, v, r0, c0);
		    }
		}
		
	}
	int countDistinctIslands(vector<vector<char>> & grid) {
		// code here
		int n = grid.size();
		int m = grid[0].size();
		
		queue<pair<int, int>> q;
		
		set<vector<pair<int, int>> > s;
		vector<vector<int>> vis(n, vector<int>(m, 0));
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vis[i][j] && grid[i][j] == 'L') {
					vector<pair<int, int>> v;
					dfs(i, j, grid, vis, v, i, j);
					s.insert(v);
				}
			}
		}
		
		return s.size();
	}
};
