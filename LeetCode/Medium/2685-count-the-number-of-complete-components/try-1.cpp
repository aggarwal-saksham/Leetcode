/*
 * Problem #2685: Count the Number of Complete Components
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/11/2026, 4:43:19 PM
 * Link: https://leetcode.com/problems/count-the-number-of-complete-components/
 */

class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n);       
        size.resize(n);       
        iota(parent.begin(), parent.end(), 0);
    }
    int findUpar(int node){
        if(parent[node] == node) return parent[node];
        return parent[node] = findUpar(parent[node]);
    }
    void UnionBySize(int u, int v){
        int par_u = findUpar(u);
        int par_v = findUpar(v);
        if(par_u == par_v) return;

        if(size[par_u] < size[par_v]){
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
        else if(size[par_u] > size[par_v]){
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        else{
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            ds.UnionBySize(e[0], e[1]);
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_map<int, vector<int>> comp;
        for(int i = 0; i < n; i++){
            comp[ds.findUpar(i)].push_back(i);
        }

        int cnt = 0;
        for(auto it : comp){
            vector<int> c = it.second;
            bool flag = true;
            for(int j = 0; j < c.size(); j++){
                if(adj[c[j]].size() < c.size() - 1) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;        
    }
};  
