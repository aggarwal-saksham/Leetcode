/*
 * Problem #1042: Flower Planting With No Adjacent
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2025, 6:29:28 PM
 * Link: https://leetcode.com/problems/flower-planting-with-no-adjacent/
 */

class Solution {
public:
    bool isSafe(int node, vector<vector<int>> &adj, vector<int> &color, int i){
        for(auto it : adj[node]){
            if(color[it] == i) return false;
        }
        return true;
    }
    bool backtrack(int node, vector<vector<int>> &adj, int m, vector<int> &color, int n){
        if(node == n){
            return true;
        }
        
        for(int i = 1; i <= m; i++){
            if(isSafe(node, adj, color, i)){
                color[node] = i;
                if(backtrack(node + 1, adj, m, color, n)) return true;
                color[node] = 0;
            }
        }
        
        return false;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < paths.size(); i++){
            int u = paths[i][0] - 1;
            int v = paths[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n, 0);

        backtrack(0, adj, 4, color, n);

        return color;
        
    }
};
