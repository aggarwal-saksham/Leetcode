/*
 * Problem #81: Search in Rotated Sorted Array II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/15/2024, 5:48:33 PM
 * Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
            int low = 0, high = n - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (nums[mid] == target)
                {
                    return true;
                }
                if(nums[low] == nums[mid] && nums[mid] == nums[high])
                {
                    low++;
                    high--;
                    continue;
                }

                if (nums[low] <= nums[mid])
                {
                    if (nums[low] <= target && target <= nums[mid])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                    if (nums[mid] <= target && target <= nums[high])
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }
            return false;
        
    }
};
