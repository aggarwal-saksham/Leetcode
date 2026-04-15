/*
 * Problem #1498: Number of Subsequences That Satisfy the Given Sum Condition
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2025, 2:12:19 PM
 * Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
 */

class Solution
{
    public:
        int numSubseq(vector<int> &nums, int target)
        {
            int n = nums.size();
            int mod = 1e9 + 7;
            sort(nums.begin(), nums.end());
            int l = 0, r = n - 1;
            int cnt = 0;

            vector<int> exp(n, 1);

            for (int i = 1; i < n; i++)
            {
                exp[i] = (exp[i - 1] *2) % mod;
            }

            while (l<= r)
            {
                if (nums[l] + nums[r] <= target)
                {
                    cnt = (cnt + exp[r - l]) % mod;
                    l++;
                }
                else
                {
                    r--;
                }
            }

            return cnt;
        }
};
