/*
 * Problem #930: Binary Subarrays With Sum
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2025, 12:14:55 AM
 * Link: https://leetcode.com/problems/binary-subarrays-with-sum/
 */

class Solution {
public:
    int func(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        int sum = 0;
        while (r < n) {
            sum += nums[r];

            while (sum > goal) {
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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return {func(nums, goal) - func(nums, goal - 1)};
    }
};
