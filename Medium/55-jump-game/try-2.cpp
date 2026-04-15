/*
 * Problem #55: Jump Game
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/1/2025, 12:44:25 AM
 * Link: https://leetcode.com/problems/jump-game/
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxInd = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i > maxInd) return false;
            maxInd = max(maxInd, nums[i] + i);
            if(maxInd >= n-1) return true;
        }
        return false;
    }
};
