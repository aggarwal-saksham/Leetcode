/*
 * Problem #494: Target Sum
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/8/2025, 2:11:18 AM
 * Link: https://leetcode.com/problems/target-sum/
 */

class Solution {
public:
    int countSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        if (arr[0] != 0 && arr[0] <= sum)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++) {

            for (int j = 0; j <= sum; j++) {
                int notake = dp[i - 1][j];

                int take = 0;
                if (arr[i] <= j) {
                    take = dp[i - 1][j - arr[i]];
                }

                dp[i][j] = take + notake;
            }
        }

        return dp[n - 1][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total || (total - abs(target)) % 2 != 0)
            return 0;
        long long sum = (total - target) / 2;
        return countSum(nums, sum);
    }
};
