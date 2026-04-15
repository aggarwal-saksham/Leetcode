/*
 * Problem #462: Minimum Moves to Equal Array Elements II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/20/2025, 5:54:41 PM
 * Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 */

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int x = nums[nums.size() / 2];
        for(int num : nums){
            ans += abs(x - num);
        }
        return ans;
    }
};
