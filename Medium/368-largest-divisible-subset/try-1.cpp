/*
 * Problem #368: Largest Divisible Subset
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/4/2025, 5:19:39 PM
 * Link: https://leetcode.com/problems/largest-divisible-subset/
 */

class Solution
{
    public:
        vector<int> largestDivisibleSubset(vector<int> &nums)
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<int> dp(n, 1);
            vector<int> hash(n, 1);

            for (int i = 0; i <= n - 1; i++)
            {

                hash[i] = i;
                for (int prev = 0; prev <= i - 1; prev++)
                {

                    if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
                    {
                        dp[i] = 1 + dp[prev];
                        hash[i] = prev;
                    }
                }
            }

            int ans = -1;
            int lastIndex = -1;

            for (int i = 0; i <= n - 1; i++)
            {
                if (dp[i] > ans)
                {
                    ans = dp[i];
                    lastIndex = i;
                }
            }

            vector<int> temp;
            temp.push_back(nums[lastIndex]);

            while (hash[lastIndex] != lastIndex)
            {
                lastIndex = hash[lastIndex];
                temp.push_back(nums[lastIndex]);
            }

            return temp;
        }
};
