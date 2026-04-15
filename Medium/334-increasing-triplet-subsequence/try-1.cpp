/*
 * Problem #334: Increasing Triplet Subsequence
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/22/2026, 12:21:57 AM
 * Link: https://leetcode.com/problems/increasing-triplet-subsequence/
 */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int n : nums) {
            if(n <= min1) {
                min1 = n;  // Update first minimum
            } else if(n <= min2) {
                min2 = n;  // Update second minimum
            } else {
                return true;  // Found a third number greater than both
            }
        }
        return false;  // No triplet found
    }
};
