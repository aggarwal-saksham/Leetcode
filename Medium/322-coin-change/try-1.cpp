/*
 * Problem #322: Coin Change
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/29/2025, 12:03:30 AM
 * Link: https://leetcode.com/problems/coin-change/
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int t[12 + 1][10000 + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (i == 0)
                    t[i][j] = INT_MAX - 1;
                if (j == 0)
                    t[i][j] = 0;
            }
        }
        for(int i=1, j = 1; j <= amount; j++){
            if(j % coins[0] == 0){
                t[i][j] = j / coins[0];
            }
            else t[i][j] = INT_MAX - 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j)
                    t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        return (t[n][amount] == INT_MAX || t[n][amount] == INT_MAX-1) ? -1 : t[n][amount];
    }
};
