/*
 * Problem #2016: Maximum Difference Between Increasing Elements
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/16/2025, 8:20:12 PM
 * Link: https://leetcode.com/problems/maximum-difference-between-increasing-elements/
 */

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int ans = -1;
        for(int i = 1; i < nums.size(); i++){
            int diff = -1;
            if(nums[i] > mini) diff = nums[i] - mini;
            ans = max(ans, diff);
            mini = min(mini, nums[i]);
        }

        return ans;
    }
};
