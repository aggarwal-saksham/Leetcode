/*
 * Problem #852: Peak Index in a Mountain Array
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/1/2025, 3:34:55 AM
 * Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
 */

class Solution
{
    public:
        int peakIndexInMountainArray(vector<int> &arr)
        {
            int n = arr.size();
            int l = 1, h = n - 2;

            while (l<= h)
            {
                int mid = l + (h - l) / 2;
                if (arr[mid] > arr[mid - 1] && arr[mid + 1] < arr[mid])
                {
                    return mid;
                }
                else if (arr[mid] > arr[mid - 1])
                {
                    l = mid + 1;
                }
                else if (arr[mid] > arr[mid + 1])
                {
                    h = mid - 1;
                }
            }

            return -1;
        }
};
