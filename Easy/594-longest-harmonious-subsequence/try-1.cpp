/*
 * Problem #594: Longest Harmonious Subsequence
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2025, 2:47:38 PM
 * Link: https://leetcode.com/problems/longest-harmonious-subsequence/
 */

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        sort(nums.begin(), nums.end());
        // 1 2 2 2 3 3 5 7
        int maxlen = 0;
        while (r < n) {
            if (nums[r] - nums[l] <= 1) {
                if (nums[r] - nums[l] == 1)
                    maxlen = max(maxlen, r - l + 1);
                r++;
            }
            else {
                l++;
            }
        }
        return maxlen;
    }
};
