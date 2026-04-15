/*
 * Problem #1011: Capacity To Ship Packages Within D Days
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/17/2024, 9:25:41 PM
 * Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 */

class Solution
{
    public:
        int findDays(vector<int> &weights, int cap)
        {
            int n = weights.size();
            int d = 1;
            int load = 0;
            for (int i = 0; i < n; i++)
            {
                if (load + weights[i] > cap)
                {
                    d += 1;
                    load = weights[i];
                }
                else load += weights[i];
            }
            return d;
        }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int maxi = *max_element(weights.begin(), weights.end());
        int n = weights.size();
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int low = maxi;
        int high = sum;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int totaldays = findDays(weights, mid);
            if (totaldays <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
