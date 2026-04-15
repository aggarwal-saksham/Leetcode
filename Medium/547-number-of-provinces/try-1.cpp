/*
 * Problem #547: Number of Provinces
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/10/2025, 4:09:10 PM
 * Link: https://leetcode.com/problems/number-of-provinces/
 */

class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int> &visited, int node){
        visited[node] = 1;
                
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(adj, visited, it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n, vector<int>(n));
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]== 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                cnt++;
                dfs(adj, visited, i);
            }
        }
        return cnt;
    }
};
