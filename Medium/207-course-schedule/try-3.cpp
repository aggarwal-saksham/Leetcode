/*
 * Problem #207: Course Schedule
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/19/2026, 2:20:00 AM
 * Link: https://leetcode.com/problems/course-schedule/
 */

class Solution {
public:
   

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto e : prerequisites){
            adj[e[0]].push_back(e[1]);
        }

        vector<int> indeg(n, 0);
        queue<int> q;
        int cnt = 0;
        
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
            cnt++;
            q.pop();
                
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);    
            }
        }
        
        return (cnt == n);
    }
};
