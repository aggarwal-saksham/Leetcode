class DisjointSet {
    public:
	vector<int> rank, parent, size;
	DisjointSet(int n) {
		rank.resize(n + 1, 0);
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
	
	void unionByRank(int u, int v) {
		int Upar_u = findUpar(u);
		int Upar_v = findUpar(v);
		
		if(Upar_u == Upar_v) return;
		
		if (rank[Upar_u] < rank[Upar_v]) {
			parent[Upar_u] = Upar_v;
		}
		else if (rank[Upar_v] < rank[Upar_u]) {
			parent[Upar_v] = Upar_u;
		}
		else if (rank[Upar_u] == rank[Upar_v]) {
			parent[Upar_v] = Upar_u;
			rank[Upar_u]++;
		}
	}
	void unionBySize(int u, int v) {
		int Upar_u = findUpar(u);
		int Upar_v = findUpar(v);
		
		if(Upar_u == Upar_v) return;

		
		if(size[Upar_u] < size[Upar_v]){
		    parent[Upar_u] = Upar_v;
		    size[Upar_v] += Upar_u;
		}
		else{
		    parent[Upar_v] = Upar_u;
		    size[Upar_u] += Upar_v;
		}
	}
};

class Solution {
  public:
    int kruskalsMST(int n, vector<vector<int>> &edges) {
        // code here
        for(auto &e : edges){
            reverse(e.begin(), e.end());
        }
        
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(n);
        int ans = 0;
        for(auto &e : edges){
            int wt = e[0], u = e[1], v = e[2];
            
            if(ds.findUpar(u) != ds.findUpar(v)){
                ans += wt;
                ds.unionBySize(u, v);
            }
        }
        return ans;
    }
};







