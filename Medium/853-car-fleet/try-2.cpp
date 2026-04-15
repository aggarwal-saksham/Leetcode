/*
 * Problem #853: Car Fleet
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/4/2026, 9:08:49 PM
 * Link: https://leetcode.com/problems/car-fleet/
 */

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // 0,1 3,3 5,1 8,4 10,2
        int n = speed.size();
        stack<double> st;
        vector<pair<int, int>> ps;
        for (int i = 0; i < n; i++) {
            ps.push_back({position[i], speed[i]});
        }

        sort(ps.begin(), ps.end());

        for (int i = n - 1; i >= 0; i--) {
            double t  = (target - ps[i].first) / (double)ps[i].second;
            if(st.empty() || st.top() < t) st.push(t);

        }

        return st.size();
    }
};
