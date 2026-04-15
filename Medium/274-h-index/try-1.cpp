/*
 * Problem #274: H-Index
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/15/2025, 2:15:26 AM
 * Link: https://leetcode.com/problems/h-index/
 */

class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] >= n - i){
                return n - i;
            }
        }
        return 0;
    }
};
