/*
 * Problem #207: Course Schedule
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 8/11/2026, 2:44:31 PM
 * Link: https://leetcode.com/problems/course-schedule/
 */

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);

        for(auto &p : prerequisites){
            int u = p[0], v = p[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &nbr : adj[node]){
                indeg[nbr]--;
                if(indeg[nbr] == 0) q.push(nbr);
            }
        }

        for(auto &in : indeg){
            if(in != 0) return false;
        }
        return true;
    }
};
