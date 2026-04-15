/*
 * Problem #3784: Minimum Deletion Cost to Make All Characters Equal
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/21/2025, 6:29:08 PM
 * Link: https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal/
 */

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char, long long> mpp;
        int n = s.size();
        for(int i = 0; i < n; i++){
            mpp[s[i]] += cost[i];
        }
        if(mpp.size() == 1) return 0;
        long long total = 0;
        for(auto it : mpp){
            total += it.second;
        }
        long long mini = LLONG_MAX;
        for(auto it : mpp){
            mini = min(mini, total - it.second);
        }
        return mini;        
    }
};
