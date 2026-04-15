/*
 * Problem #1749: Maximum Absolute Sum of Any Subarray
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/26/2025, 11:40:14 PM
 * Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
 */

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum1 = 0;
        int max_sum2 = 0;
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < nums.size(); i++){
            sum1 += nums[i];
            max_sum1 = max(max_sum1, sum1);
            if(sum1 < 0) sum1 = 0;
        }
        for(int i = 0; i < nums.size(); i++){
            sum2 += nums[i];
            max_sum2 = max(max_sum2, abs(sum2));
            if(sum2 > 0) sum2 = 0;
        }

        return max(max_sum1, max_sum2);
    }
};
