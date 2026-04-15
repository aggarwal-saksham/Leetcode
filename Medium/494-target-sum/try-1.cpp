/*
 * Problem #494: Target Sum
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2025, 6:50:14 PM
 * Link: https://leetcode.com/problems/target-sum/
 */

class Solution
{
    public:
        int countSum(vector<int> &arr, int sum, int n)
        {
            int t[n + 1][sum + 1];
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
                        t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
                    }
                    else t[i][j] = t[i - 1][j];
                }
            }
            return t[n][sum];
        }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total || (total + abs(target)) % 2 != 0)
            return 0;
        long long sum = (total + target) / 2;
        return countSum(nums, sum, n);
    }
};
