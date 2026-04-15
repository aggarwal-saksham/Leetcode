/*
 * Problem #518: Coin Change II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2025, 10:20:11 PM
 * Link: https://leetcode.com/problems/coin-change-ii/
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        uint64_t t[n + 1][amount + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (i == 0)
                    t[i][j] = 0;
                if (j == 0)
                    t[i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j)
                    t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        return t[n][amount];
        
    }
};


