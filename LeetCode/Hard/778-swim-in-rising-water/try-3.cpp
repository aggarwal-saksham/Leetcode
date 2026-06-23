/*
 * Problem #778: Swim in Rising Water
 * Difficulty: Hard
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/23/2026, 4:58:31 PM
 * Link: https://leetcode.com/problems/swim-in-rising-water/
 */

class DisjointSet {
    public:
	vector<int> parent, size;
	DisjointSet(int n) {
		size.resize(n + 1, 1);
		parent.resize(n + 1);
		for (int i = 0; i <= n ; i++) {
			parent[i] = i;
		}
	}
	
	int findUpar(int node) {
		if (parent[node] == node)
			return parent[node];
		
		return parent[node] = findUpar(parent[node]);
	}
	
	void unionBySize(int u, int v) {
		int Upar_u = findUpar(u);
		int Upar_v = findUpar(v);
		
		if(Upar_u == Upar_v) return;
		
		if(size[Upar_u] < size[Upar_v]){
		    parent[Upar_u] = Upar_v;
		    size[Upar_v] += size[Upar_u];
		}
		else{
		    parent[Upar_v] = Upar_u;
		    size[Upar_u] += size[Upar_v];
		}
	}
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return 0;
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};

        unordered_map<int, pair<int, int>> pos;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                pos[grid[i][j]] = {i, j};
            }
        }
        DisjointSet ds(n *n +1);
        int t = 0;
        while(ds.findUpar(0) != ds.findUpar(n *n -1)){
            auto [x, y] = pos[t];
            for(int k = 0; k < 4; k++){
                int nx = x + delx[k];
                int ny = y + dely[k];

               if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] <= t){
                ds.unionBySize(x * n + y, nx * n + ny);
               }
            }
            t++;
        }
        return t  - 1;
    }
};
