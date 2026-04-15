/*
 * Problem #3736: Minimum Moves to Equal Array Elements III
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/22/2025, 12:36:24 AM
 * Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/
 */

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(int num : nums){
            ans += maxi - num;
        }
        return ans;

    }
};
