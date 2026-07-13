/*
 * Problem #1331: Rank Transform of an Array
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/12/2026, 10:45:18 PM
 * Link: https://leetcode.com/problems/rank-transform-of-an-array/
 */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({arr[i], i});
        }

        int rank = 0;
        int prev = INT_MAX;
        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();
            if (prev != num)
                rank++;
            ans[idx] = rank;
            prev = num;
        }
        return ans;
    }
};
