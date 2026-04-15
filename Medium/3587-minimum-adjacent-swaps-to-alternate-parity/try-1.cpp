/*
 * Problem #3587: Minimum Adjacent Swaps to Alternate Parity
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/21/2025, 8:51:31 PM
 * Link: https://leetcode.com/problems/minimum-adjacent-swaps-to-alternate-parity/
 */

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
    vector<int> evenIdx, oddIdx;

    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 0)
            evenIdx.push_back(i);
        else
            oddIdx.push_back(i);
    }

    int even = evenIdx.size(), odd = oddIdx.size();
    if (abs(even - odd) > 1) return -1;

    int minSwap = INT_MAX;

    if (even >= odd) {
        int swapCount = 0;
        int ei = 0;
        for (int i = 0; i < n; i += 2) {
            if (ei >= evenIdx.size()) break;
            swapCount += abs(i - evenIdx[ei]);
            ei = ei + 1;
        }
        minSwap = min(minSwap, swapCount);
    }

    if(odd >= even) {
        int swapCount = 0;
        int oi = 0;
        for (int i = 0; i < n; i += 2) {
            if (oi >= oddIdx.size()) break;
            swapCount += abs(i - oddIdx[oi]);
            oi = oi + 1;
        }
        minSwap = min(minSwap, swapCount);
    }

    return minSwap;
    }
};
