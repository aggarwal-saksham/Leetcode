/*
 * Problem #1300: Sum of Mutated Array Closest to Target
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/12/2025, 1:52:26 AM
 * Link: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
 */

class Solution {
public:
    bool possible(vector<int>& arr, int mid, int target) {
        int total = 0;
        for (int val : arr) {
            if (val <= mid)
                total += val;
            else
                total += mid;
        }
        if (total >= target)
            return true;
        return false;
    }
    int findBestValue(vector<int>& arr, int target) {
        int mini = 0;
        int maxi = *max_element(arr.begin(), arr.end());
        int low = mini, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(arr, mid, target)) {
                high = mid - 1;
            } else
                low = mid + 1;
        }

        int sumLow = 0, sumHigh = 0;
        for (int val : arr)
            sumLow += (val < low) ? val : low;
        for (int val : arr)
            sumHigh += (val < low - 1) ? val : (low - 1);

        if (low == 0)
            return low;

        if (abs(sumLow - target) < abs(sumHigh - target))
            return low;
        else
            return low - 1;
    }
};
