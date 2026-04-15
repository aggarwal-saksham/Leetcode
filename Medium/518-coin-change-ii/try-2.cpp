/*
 * Problem #518: Coin Change II
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2025, 10:31:04 PM
 * Link: https://leetcode.com/problems/coin-change-ii/
 */

class Solution {
public:
    int countSum(vector<int> &arr, int sum, int n)
        {
            uint64_t t[n + 1][sum + 1];
            for (int i = 0; i < n + 1; i++)
            {
                for (int j = 0; j < sum + 1; j++)
                {
                    if (i == 0)
                        t[i][j] = 0;
                    if (j == 0)
                        t[i][j] = 1;
                }
            }

            for (int i = 1; i < n + 1; i++)
            {
                for (int j = 0; j < sum + 1; j++)
                {
                    if (arr[i - 1] <= j)
                    {
                        t[i][j] = t[i][j - arr[i - 1]] + t[i - 1][j];
                    }
                    else t[i][j] = t[i - 1][j];
                }
            }
            return t[n][sum];
        }
    int change(int amount, vector<int>& coins) {
        return countSum(coins, amount, coins.size());
    }
};
