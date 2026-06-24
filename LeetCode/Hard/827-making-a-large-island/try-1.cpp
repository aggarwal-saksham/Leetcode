/*
 * Problem #827: Making A Large Island
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/23/2026, 5:27:39 PM
 * Link: https://leetcode.com/problems/making-a-large-island/
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};

        DisjointSet ds(n * n + 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int node = i * n + j;

                    for(int k = 0; k < 4; k++){
                        int nx = i + delx[k];
                        int ny = j + dely[k];

                        if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1){
                            int adjNode = nx * n + ny;

                            if(ds.findUpar(node) != ds.findUpar(adjNode)){
                                ds.unionBySize(node, adjNode);
                            }
                        }
                    } 
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                unordered_set<int> st;
                if(grid[i][j] == 0){
                    int node = i * n + j;

                    for(int k = 0; k < 4; k++){
                        int nx = i + delx[k];
                        int ny = j + dely[k];

                        if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1){
                            int adjNode = nx * n + ny;                            
                            st.insert(ds.findUpar(adjNode));       
                        }
                    } 
                    int curr = 1;

                    for (auto &par : st) {
                        curr += ds.size[par];
                    }
                    ans = max(ans, curr);
                }
            }
        }
        for(int i = 0; i < n * n; i++){
            ans = max(ans, ds.size[ds.findUpar(i)]);
        }
        return ans;
    }
};
