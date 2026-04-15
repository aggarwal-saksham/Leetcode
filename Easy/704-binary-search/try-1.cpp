/*
 * Problem #704: Binary Search
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/13/2024, 2:04:50 PM
 * Link: https://leetcode.com/problems/binary-search/
 */

class Solution
{
    public:
        int search(vector<int> &nums, int target)
        {
            int n = nums.size();
            int low = 0, high = n - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (target == nums[mid])
                {
                    return mid;
                }
                else if (target <= nums[mid])
                {
                    high = mid - 1;
                }
                else if (target >= nums[mid])
                {
                    low = mid + 1;
                }
            }
            return -1;
        }
};
