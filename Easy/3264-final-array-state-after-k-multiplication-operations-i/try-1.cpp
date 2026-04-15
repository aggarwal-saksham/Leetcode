/*
 * Problem #3264: Final Array State After K Multiplication Operations I
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/16/2024, 12:49:55 PM
 * Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
 */

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k > 0){
            auto mini = min_element(nums.begin(), nums.end());
            int ind = distance(nums.begin(), mini);
            nums[ind] *= multiplier;
            k--;
        }
        return nums;
    }
};
