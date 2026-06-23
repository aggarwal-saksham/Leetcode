/*
 * Problem #207: Course Schedule
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/19/2026, 1:52:59 AM
 * Link: https://leetcode.com/problems/course-schedule/
 */

class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int> & vis, vector<int> &pathvis, int node){
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(adj, vis, pathvis, it)) return true;
            }
            
            else if(vis[it] && pathvis[it]) return true;
        }
        
        pathvis[node] = 0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto e : prerequisites){
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(dfs(adj, vis, pathvis, i)) return false;
            }
        }
        return true;
    }
};
