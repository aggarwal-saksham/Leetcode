/*
 * Problem #122: Best Time to Buy and Sell Stock II
 * Difficulty: Medium
 * Submission: Try 6
 * status: Accepted
 * Language: cpp
 * Date: 7/18/2026, 12:32:53 AM
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mini = nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] < mini){
                mini = nums[i];
            }
            else{
                ans += nums[i] - mini;
                mini = nums[i];
            }
        }
        return ans;

    }
};
