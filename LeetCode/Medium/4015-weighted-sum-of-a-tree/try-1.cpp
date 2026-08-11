/*
 * Problem #4015: Weighted Sum of a Tree
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/9/2026, 11:21:39 PM
 * Link: https://leetcode.com/problems/weighted-sum-of-a-tree/
 */

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            if(parent[i] == -1) continue;
            adj[parent[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        int h = 1;
        vector<int> depth(n);
        depth[0] = 1;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                for(auto &nbr : adj[node]){
                    depth[nbr] = h + 1;
                    q.push(nbr);
                }
            }
            if(!q.empty()) h++;
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += 1LL * nums[i] * (h - depth[i] + 1);
        }
        return ans;
    }
};
