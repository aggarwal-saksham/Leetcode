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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &a) {
        // code here
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};

        DisjointSet ds(n * m + 1);

        vector<vector<int>> v(n, vector<int>(m, 0));
        vector<int> ans;
        ans.push_back(1);
        v[a[0][0]][a[0][1]] = 1;

        for(int l = 1; l < a.size(); l++){
            int i = a[l][0], j = a[l][1];
            if(v[i][j] == 1){
                ans.push_back(ans.back());
                continue;
            } 

            v[i][j] = 1;
            int cnt = 0;

            int node = i * m + j;

            for(int k = 0; k < 4; k++){
                int nx = i + delx[k];
                int ny = j + dely[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny]){
                    int adjNode = nx * m + ny;

                    if(ds.findUpar(node) != ds.findUpar(adjNode)){
                        cnt++;
                        ds.unionBySize(node, adjNode);
                    }
                }
            } 
            ans.push_back(ans.back() - cnt + 1);           
        }
        
        return ans;
    }
};
