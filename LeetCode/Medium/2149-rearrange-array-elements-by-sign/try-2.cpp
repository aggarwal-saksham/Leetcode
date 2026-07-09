/*
 * Problem #2149: Rearrange Array Elements by Sign
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/8/2026, 2:47:06 AM
 * Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
 */

class Solution
{
    public:
        vector<int> rearrangeArray(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> ansarr(n, 0);
            int neg = 1;
            int pos = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] < 0)
                {
                    ansarr[neg] = nums[i];
                    neg += 2;
                }
                else
                {
                    ansarr[pos] = nums[i];
                    pos += 2;
                }
            }
            return ansarr;
        }
};
