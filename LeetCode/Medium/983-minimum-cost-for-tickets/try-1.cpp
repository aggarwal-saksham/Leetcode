/*
 * Problem #983: Minimum Cost For Tickets
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/7/2026, 12:09:08 PM
 * Link: https://leetcode.com/problems/minimum-cost-for-tickets/
 */

class Solution {
public:
    int lb(vector<int>& days, int target){
        return lower_bound(days.begin(), days.end(), target) - days.begin();
    }
    int rec(vector<int>& days, vector<int>& costs, int idx, vector<int> &dp){
        if(idx == days.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int p1 = costs[0] + rec(days, costs, idx + 1, dp);

        int p7 = costs[1] + rec(days, costs, lb(days, days[idx] + 7), dp);

        int p30 = costs[2] + rec(days, costs, lb(days, days[idx] + 30), dp);

        return dp[idx] = min({p1, p7, p30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return rec(days, costs, 0, dp);
    }
};
