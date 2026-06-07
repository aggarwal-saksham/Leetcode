/*
 * Problem #3946: Maximum Number of Items From Sale I
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/5/2026, 1:24:44 PM
 * Link: https://leetcode.com/problems/maximum-number-of-items-from-sale-i/
 */

class Solution {
public:
    vector<int> gain;
    vector<vector<int>> dp;
    int n, mini;

    int helper(int idx, int left, vector<vector<int>>& items) {
        if (idx == n) {
            return left / mini;
        }

        if (dp[idx][left] != -1) {
            return dp[idx][left];
        }

        int notTake = helper(idx + 1, left, items);

        int take = 0;
        if (left >= items[idx][1]) {
            take =
                gain[idx] + helper(idx + 1, left - items[idx][1], items);
        }

        return dp[idx][left] = max(take, notTake);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();

        mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, items[i][1]);
        }

        gain.resize(n);

        for (int i = 0; i < n; i++) {
            int free = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    free++;
                }
            }

            gain[i] = 1 + free;
        }

        dp.assign(n, vector<int>(budget + 1, -1));

        return helper(0, budget, items);
    }
};
