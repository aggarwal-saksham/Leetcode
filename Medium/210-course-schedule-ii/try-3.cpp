/*
 * Problem #210: Course Schedule II
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/19/2026, 2:25:17 AM
 * Link: https://leetcode.com/problems/course-schedule-ii/
 */

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto e : prerequisites){
            adj[e[1]].push_back(e[0]);
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
        vector<int> empty;
        return ans.size() == n ? ans : empty;
    }
};
