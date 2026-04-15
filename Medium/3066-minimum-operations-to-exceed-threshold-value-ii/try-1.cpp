/*
 * Problem #3066: Minimum Operations to Exceed Threshold Value II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/13/2025, 3:28:21 PM
 * Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minH;
        for (int num : nums) {
            minH.push(num);
        }
        int cnt = 0;
        while (minH.top() < k && minH.size() >= 2) {
            cnt++;
            //if (minH.size() >= 2) {
                long long x = minH.top();
                minH.pop();
                long long y = minH.top();
                minH.pop();
            //}
            minH.push(min(x, y) * 2 + max(x, y));
        }
        return cnt;
    }
};
