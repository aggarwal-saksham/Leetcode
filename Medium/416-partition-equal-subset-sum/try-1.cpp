/*
 * Problem #416: Partition Equal Subset Sum
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2025, 3:40:19 PM
 * Link: https://leetcode.com/problems/partition-equal-subset-sum/
 */

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> t(n + 1, vector<int>(sum + 1));
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (i == 0)
                    t[i][j] = false;
                if (j == 0)
                    t[i][j] = true;
            }
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (arr[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                } 
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        return t[n][sum];
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
