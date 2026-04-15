/*
 * Problem #3423: Maximum Difference Between Adjacent Elements in a Circular Array
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/21/2025, 12:51:24 AM
 * Link: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/
 */

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 1; i < nums.size(); i++){
            maxi = max(maxi, abs(nums[i] - nums[i - 1]));
        }
        maxi = max(maxi, abs(nums[0] - nums[nums.size() - 1]));
        return maxi;
    }
};
