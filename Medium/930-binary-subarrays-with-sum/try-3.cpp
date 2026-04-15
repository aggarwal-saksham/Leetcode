/*
 * Problem #930: Binary Subarrays With Sum
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 12/20/2025, 1:24:28 PM
 * Link: https://leetcode.com/problems/binary-subarrays-with-sum/
 */

class Solution
{
    public:
        int func(vector<int> &nums, int goal)
        {
            int l = 0, r = 0, sum = 0, cnt = 0;
            int n = nums.size();
            if(goal < 0) return 0;
            while (l <= r && r < n)
            {

                sum += nums[r];
                while (sum > goal)
                {
                    sum -= nums[l];
                    l++;
                }
                cnt += r - l + 1;
                r++;
            }
            return cnt;
        }

   	// create a fn that cnt num of subarr <= k

   	// ans = func(goal) - func(goal - 1)// equal to goal
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return {
            func(nums, goal) - func(nums, goal - 1)
        };
    }
};
