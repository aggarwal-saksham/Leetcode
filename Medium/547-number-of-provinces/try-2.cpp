/*
 * Problem #547: Number of Provinces
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/17/2026, 6:20:20 PM
 * Link: https://leetcode.com/problems/number-of-provinces/
 */

class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int> &vis, int node){
        vis[node] = 1;
                
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj, vis, it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i= 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j) adj[i].push_back(j);
            }
        }

        vector<int> vis(n, 0);
        int provinces = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                provinces++;
                dfs(adj, vis, i);
            }
        }
        return provinces;
    }
};
