/*
 * Problem #1800: Maximum Ascending Subarray Sum
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/4/2025, 1:49:33 PM
 * Link: https://leetcode.com/problems/maximum-ascending-subarray-sum/
 */

class Solution
{
    public:
        int maxAscendingSum(vector<int> &nums)
        {
            if (nums.size() == 1) return nums[0];
            int sum = nums[0];
            int ans = nums[0];
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i + 1] > nums[i] && sum != 0) sum += nums[i + 1];
                if (nums[i + 1] > nums[i] && sum == 0)
                {
                    sum += nums[i + 1];
                    sum += nums[i];
                }
                else if (nums[i + 1] <= nums[i]) sum = 0;
                ans = max(ans, sum);
            }
            return ans;
        }
};
