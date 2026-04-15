/*
 * Problem #802: Find Eventual Safe States
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/12/2025, 6:41:12 PM
 * Link: https://leetcode.com/problems/find-eventual-safe-states/
 */

class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> & vis, vector<int> &pathvis, int node, vector<int> &check){
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        
        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(graph, vis, pathvis, it, check)) return true;
            }
            
            else if(vis[it] && pathvis[it]) return true;
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        vector<int> check(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                (dfs(graph, vis, pathvis, i, check));
            }
        }

        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(check[i] == 1) ans.push_back(i);
        }

        return ans;
    }
};
