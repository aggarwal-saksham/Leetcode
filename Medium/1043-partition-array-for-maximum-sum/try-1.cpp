/*
 * Problem #1043: Partition Array for Maximum Sum
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/6/2025, 11:39:17 PM
 * Link: https://leetcode.com/problems/partition-array-for-maximum-sum/
 */

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            int len = 0;
            int maxel = INT_MIN;
            int maxans = INT_MIN;

            for(int j = i; j < min(n, i + k); j++){
                len++;
                maxel = max(maxel, arr[j]);
                int cost = (len * maxel) + dp[j + 1];
                maxans = max(maxans, cost);
            }

            dp[i] = maxans;
        }

        return dp[0];        
    }
};
