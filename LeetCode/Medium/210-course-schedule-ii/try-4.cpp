/*
 * Problem #210: Course Schedule II
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 8/11/2026, 2:53:35 PM
 * Link: https://leetcode.com/problems/course-schedule-ii/
 */

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
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
        vector<int> ans;
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            ans.push_back(node);

            for(auto &nbr : adj[node]){
                indeg[nbr]--;
                if(indeg[nbr] == 0) q.push(nbr);
            }
        }
        reverse(ans.begin(), ans.end());
        if (cnt == n) return ans;
        else return {};
    }
};
