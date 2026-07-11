/*
 * Problem #3532: Path Existence Queries in a Graph I
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/9/2026, 2:15:36 PM
 * Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        for(int i = 0; i < n - 1; i++){
            int val_u = nums[i];
            int val_v = nums[i + 1];
            if(val_v - val_u <= maxDiff) ds.UnionBySize(i, i + 1);
        }
        vector<bool> ans;
        for(auto &q : queries){
            int u = q[0];
            int v = q[1];
            ans.push_back(ds.findUpar(u) == ds.findUpar(v));
        }
        return ans;
    }
};
