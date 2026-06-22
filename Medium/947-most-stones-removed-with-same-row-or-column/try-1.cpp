/*
 * Problem #947: Most Stones Removed with Same Row or Column
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/23/2026, 12:58:38 AM
 * Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
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
    int removeStones(vector<vector<int>>& stones) {
        int maxR = 0, maxC = 0;
        for(auto &s : stones){
            maxR = max(maxR, s[0]);
            maxC = max(maxC, s[1]);
        }
        int n = maxR + maxC + 1;
        DisjointSet ds(n);
        for(auto &s : stones){
            if(ds.findUpar(s[0]) != ds.findUpar(s[1] + maxR + 1)){
                ds.unionBySize(s[0], s[1] + maxR + 1);
            }
        }
        int comp = 0;
        for(int i = 0; i <= n; i++){
            if(ds.parent[i] == i && ds.size[ds.findUpar(i)] > 1){
                comp++;
            }
        }
        return stones.size() - comp;

    }
};
