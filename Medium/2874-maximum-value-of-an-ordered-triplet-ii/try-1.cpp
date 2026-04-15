/*
 * Problem #2874: Maximum Value of an Ordered Triplet II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 4/3/2025, 4:13:30 PM
 * Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/
 */

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int maxnum = 0, maxsum = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, nums[i] * 1LL * maxsum);
            maxsum = max(maxsum, maxnum - nums[i]);
            maxnum = max(maxnum, nums[i]);
        }
        return ans;
    }
};
