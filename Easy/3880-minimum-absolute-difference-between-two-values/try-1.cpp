/*
 * Problem #3880: Minimum Absolute Difference Between Two Values
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/28/2026, 8:06:58 PM
 * Link: https://leetcode.com/problems/minimum-absolute-difference-between-two-values/
 */

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int idx1 = -1, idx2 = -1;
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                idx1 = i;
                if (idx2 != -1) {
                    ans = min(ans, abs(idx1 - idx2));
                }
            } else if (nums[i] == 2) {
                idx2 = i;
                if (idx1 != -1)
                    ans = min(ans, abs(idx1 - idx2));
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};
