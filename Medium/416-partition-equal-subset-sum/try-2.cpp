/*
 * Problem #416: Partition Equal Subset Sum
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2025, 7:53:44 PM
 * Link: https://leetcode.com/problems/partition-equal-subset-sum/
 */

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // i->ind, j->sum
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
        for (int j = 0; j <= sum; j++) {
            dp[0][j] = false;
        }

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum; j++) {
                bool notake = dp[i - 1][j];

                bool take = false;
                if (arr[i] <= j) {
                    take = dp[i - 1][j - arr[i]];
                }

                dp[i][j] = take || notake;
            }
        }

        return dp[n - 1][sum];
    }

    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += arr[i];
        }
        if (total % 2 != 0 || n == 1)
            return false;
        else
            return isSubsetSum(arr, total / 2);
    }
};
