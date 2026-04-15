/*
 * Problem #207: Course Schedule
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/13/2025, 12:36:44 AM
 * Link: https://leetcode.com/problems/course-schedule/
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> indeg(n, 0);
        queue<int> q;
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
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
                
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);    
            }
        }
        
        return (ans.size() == n);
        //true if doesn't contain cycle
    }
};
