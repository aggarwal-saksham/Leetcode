/*
 * Problem #3105: Longest Strictly Increasing or Strictly Decreasing Subarray
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/3/2025, 1:11:41 PM
 * Link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
 */

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt1 = 1, cnt2 = 1;
        int max1 = 1, max2 = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i + 1] > nums[i]){
                cnt1++;
                max1 = max(max1, cnt1);
            }
            else cnt1 = 1;
        }
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i + 1] < nums[i]){
                cnt2++;
                max2 = max(max2, cnt2);
            }
            else cnt2 = 1;
        }

        return max(max1, max2);
    }
};
