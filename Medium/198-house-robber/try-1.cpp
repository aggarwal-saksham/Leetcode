/*
 * Problem #198: House Robber
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/13/2025, 1:04:24 PM
 * Link: https://leetcode.com/problems/house-robber/
 */

class Solution
{
    public:
        int rec(vector<int> &nums, int n, vector<int> &t)
        {
            if (n <= 0) return 0;
            if (t[n] != -1) return t[n];
            return t[n] = max(nums[n - 1] + rec(nums, n - 2, t), rec(nums, n - 1, t));
        }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> t(n + 1, - 1);
        return rec(nums, n, t);
    }
};
