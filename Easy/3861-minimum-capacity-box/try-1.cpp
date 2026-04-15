/*
 * Problem #3861: Minimum Capacity Box
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/13/2026, 11:28:53 PM
 * Link: https://leetcode.com/problems/minimum-capacity-box/
 */

class Solution {
public:
    int minimumIndex(vector<int>& nums, int itemSize) {
        int n = nums.size(), idx = -1;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] < mini && nums[i] >= itemSize) {
                mini = nums[i];
                idx = i;
            }
        }
        return idx;
    }
};
