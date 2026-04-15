/*
 * Problem #153: Find Minimum in Rotated Sorted Array
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/15/2024, 6:49:09 PM
 * Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 */

class Solution
{
    public:
        int findMin(vector<int> &nums)
        {
            int n = nums.size();
            int low = 0, high = n - 1;
            int ans = INT_MAX;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (nums[low] <= nums[mid])
                {
                    ans = min(ans, nums[low]);
                    low = mid + 1;
                }
                else
                {
                    ans = min(ans, nums[mid]);
                    high = mid - 1;
                }
            }
            return ans;
        }
};
