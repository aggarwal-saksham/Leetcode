/*
 * Problem #1004: Max Consecutive Ones III
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/4/2025, 7:43:42 PM
 * Link: https://leetcode.com/problems/max-consecutive-ones-iii/
 */

class Solution
{
    public:
        int longestOnes(vector<int> &nums, int k)
        {
            int n = nums.size();
            int l = 0, r = 0;
            int ans = 0;
            int zeroCount = 0;
            while (r < n)
            {
                if (nums[r] == 0)
                {
                    zeroCount++;
                }
                if (zeroCount > k)
                {
                    if (nums[l] == 0) zeroCount--;
                    l++;
                }
                else
                {
                    int len = r - l + 1;
                    ans = max(ans, len);
                }
                r++;
            }
            return ans;
        }
};
