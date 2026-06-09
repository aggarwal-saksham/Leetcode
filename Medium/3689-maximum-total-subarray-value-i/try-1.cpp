/*
 * Problem #3689: Maximum Total Subarray Value I
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/9/2026, 1:15:43 PM
 * Link: https://leetcode.com/problems/maximum-total-subarray-value-i/
 */

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());

        return (maxi - mini) * 1LL * k;
    }
};
