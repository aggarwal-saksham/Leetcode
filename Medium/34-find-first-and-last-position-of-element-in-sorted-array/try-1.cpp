/*
 * Problem #34: Find First and Last Position of Element in Sorted Array
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/15/2024, 2:35:59 PM
 * Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */

class Solution
{
    public:
        int first_occ(vector<int> &nums, int target)
        {
            int n = nums.size();
            int low = 0, high = n - 1;
            int first = -1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (nums[mid] == target)
                {
                    first = mid;
                    high = mid - 1;
                }
                else if (nums[mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            return first;
        }

    int last_occ(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int last = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int first = first_occ(nums, target);
        if (first == -1)
        {
            return { -1,
                -1 };
        }
        int last = last_occ(nums, target);
        return {
            first,
            last
        };
    }
};
