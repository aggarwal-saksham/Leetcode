/*
 * Problem #2492: Minimum Score of a Path Between Two Cities
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/4/2026, 1:33:30 PM
 * Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
 */

class DisjointSet{
public: 
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(parent[node] == node)
            return parent[node];
        return parent[node] = findUpar(parent[node]);
    }

    void rankBySize(int u, int v){
        int par_u = findUpar(u);
        int par_v = findUpar(v);

        if(par_u == par_v) return;

        if(size[par_u] < size[par_v]){
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }

        else {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        for(auto &e : edges){
            ds.rankBySize(e[0], e[1]);
        }

        int comp = ds.findUpar(1);
        int ans = 1e9;

        for(auto &e : edges){
            if(ds.findUpar(e[0]) == comp){
                ans = min(ans, e[2]);
            }
        }
        return ans;
    }
};
