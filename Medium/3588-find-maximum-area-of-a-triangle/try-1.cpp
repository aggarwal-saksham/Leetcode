/*
 * Problem #3588: Find Maximum Area of a Triangle
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/26/2026, 8:26:12 PM
 * Link: https://leetcode.com/problems/find-maximum-area-of-a-triangle/
 */

class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        unordered_map<int, vector<int>> x;
        unordered_map<int, vector<int>> y;

        int minX = INT_MAX, maxX = INT_MIN;
        int minY = INT_MAX, maxY = INT_MIN;

        for (auto c : coords) {
            x[c[0]].push_back(c[1]);
            y[c[1]].push_back(c[0]);

            minX = min(minX, c[0]);
            maxX = max(maxX, c[0]);

            minY = min(minY, c[1]);
            maxY = max(maxY, c[1]);
        }

        long long ans = 0;

        for (auto it : x) {
            vector<int>& v = it.second;

            long long base = *max_element(v.begin(), v.end()) -
                             *min_element(v.begin(), v.end());

            long long h = max(abs(it.first - minX),
                              abs(it.first - maxX));

            ans = max(ans, base * h);
        }

        for (auto it : y) {
            vector<int>& v = it.second;

            long long base = *max_element(v.begin(), v.end()) -
                             *min_element(v.begin(), v.end());

            long long h = max(abs(it.first - minY),
                              abs(it.first - maxY));

            ans = max(ans, base * h);
        }

        return ans ? ans : -1;
    }
};
