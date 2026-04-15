/*
 * Problem #802: Find Eventual Safe States
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/13/2025, 1:04:12 AM
 * Link: https://leetcode.com/problems/find-eventual-safe-states/
 */

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revgraph(n);
        for(int i = 0; i < n; i++){
            for(auto it : graph[i]){
                revgraph[it].push_back(i);
            }
        }
        vector<int> indeg(n, 0);
        queue<int> q;
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            for(auto it : revgraph[i]){
                indeg[it]++;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
                
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
                
            for(auto it : revgraph[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);    
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
