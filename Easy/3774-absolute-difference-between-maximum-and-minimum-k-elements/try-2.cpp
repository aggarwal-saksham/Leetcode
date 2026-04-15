/*
 * Problem #3774: Absolute Difference Between Maximum and Minimum K Elements
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 12/22/2025, 12:32:05 AM
 * Link: https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements/
 */

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mini = 0, maxi = 0, n = nums.size();
        for(int l = 0; l < k; l++){
            mini += nums[l];
            maxi += nums[ n - l - 1];
        }
        return (maxi - mini);
    }
};
