/*
 * Problem #1319: Number of Operations to Make Network Connected
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2026, 9:21:05 PM
 * Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
 */

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cnt = 0;
        for(auto &c : connections){
            int u = c[0], v = c[1];
            if(ds.findUpar(u) != ds.findUpar(v)){
                cnt++;
                ds.unionBySize(u, v);
            }
        }
        int rem = connections.size() - cnt;
        set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(ds.findUpar(i));
        }
        return(rem >= st.size() - 1) ? st.size() - 1 : -1;

    }
};
