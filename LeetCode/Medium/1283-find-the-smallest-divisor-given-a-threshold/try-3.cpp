/*
 * Problem #1283: Find the Smallest Divisor Given a Threshold
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2026, 11:50:46 PM
 * Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
 */

class Solution
{
    public:
        int findSum(vector<int> &nums, int divisor)
        {
            int n = nums.size();
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += ceil(nums[i] / (double) divisor);
            }
            return sum;
        }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int sum = findSum(nums, mid);
            if (sum <= threshold)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
