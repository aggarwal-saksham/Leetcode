/*
 * Problem #416: Partition Equal Subset Sum
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2026, 1:41:27 PM
 * Link: https://leetcode.com/problems/partition-equal-subset-sum/
 */

class Solution {
public:
    bool rec(int i, vector<int> &arr, int target, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(i < 0 || target < 0) return false;

        if(dp[i][target] != -1) return dp[i][target];


        return dp[i][target] = rec(i - 1, arr, target - arr[i], dp) ||
                            rec(i - 1, arr, target, dp);
    }

    bool checkSubsequenceSum(vector<int>& arr, int k) {
        vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
        return rec(arr.size() - 1, arr, k, dp);
    }

    bool canPartition(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if(total % 2 == 1) return false;
        return checkSubsequenceSum(arr, total / 2);
    }
};
