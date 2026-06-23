class Solution {
	public:
	int countIslands(vector<vector<char>> & grid) {
		// Code here
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> vis(n, vector<int>(m, 0));
		
		int delx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
		int dely[] = {-1, 0, 1, -1, 1, -1, 0, 1};
		
		int islands = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'L' && !vis[i][j]) {
					islands++;
					vis[i][j] = 1;
					
					queue<pair<int, int>> q;
					q.push({i, j});
					
					while (!q.empty()) {
						auto [x, y] = q.front();
						q.pop();
						
						for (int k = 0; k < 8; k++) {
							int nx = x + delx[k];
							int ny = y + dely[k];
							
							if (nx >= 0 && nx < n && ny >= 0 &&
							ny < m && grid[nx][ny] == 'L' && !vis[nx][ny]) {
								vis[nx][ny] = 1;
								q.push({nx, ny});
							}
						}
					}
				}
			}
		}
		return islands;
	}
};
