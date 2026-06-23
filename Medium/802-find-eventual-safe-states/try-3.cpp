/*
 * Problem #802: Find Eventual Safe States
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/19/2026, 1:21:16 PM
 * Link: https://leetcode.com/problems/find-eventual-safe-states/
 */

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>outdeg(n);
        vector<vector<int>> incoming(n);
        for(int i = 0; i < n; i++){
            outdeg[i] = graph[i].size();
            for(auto it : graph[i]){
                incoming[it].push_back(i);
            }
        }
        queue<int> q;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(outdeg[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto n : incoming[node]){
                outdeg[n]--;
                if(outdeg[n] == 0) q.push(n);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
