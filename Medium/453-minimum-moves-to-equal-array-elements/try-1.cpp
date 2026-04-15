/*
 * Problem #453: Minimum Moves to Equal Array Elements
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/12/2025, 9:32:26 PM
 * Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 */

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int mini = *min_element(nums.begin(), nums.end());

        ans = sum - (n * mini);

        return ans;
    }
};
