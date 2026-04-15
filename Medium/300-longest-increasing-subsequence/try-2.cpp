/*
 * Problem #300: Longest Increasing Subsequence
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/4/2025, 4:51:19 PM
 * Link: https://leetcode.com/problems/longest-increasing-subsequence/
 */

class Solution
{
    public:
        int lengthOfLIS(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> dp(n, 1);
            int maxi = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (nums[j] < nums[i])
                    {
                        dp[i] = max(1 + dp[j], dp[i]);
                    }
                }
                maxi = max(maxi, dp[i]);
            }
            return maxi;
        }
};
